#!/usr/bin/python3
"""
"" 05-08-2025 :::  Team: 08 
"" 
"" Name: Debodit Ray, Roll: 13
"" Name: Kaustav Mondal , Roll: 17
"" Name: Anuska Nath , Roll: 03
""
"" Usage : python3 parallel_matmul.py <dimension> <num_processes> <mod_value> <print_switch>
""
""  All Command Line Parameter Description :
""   1. dimension (int): The dimension of the square matrices (e.g., 1000, 3000).
""   2. num_processes (int): The number of parallel processes to use (e.g., 1, 2, 4).
""   3. mod_value (int): The value used to generate random numbers for matrix elements (i.e., elements will be in [0, mod_value-1]).
""   4. print_switch (int): A flag to control output. '1' to print all matrices, '0' to suppress printing.
""
"" What this Program Does :
"" This program performs matrix multiplication (C = A * B) for two large, square matrices of a given dimension.
"" It initializes matrices A and B with random unsigned integers. The core multiplication logic is parallelized
"" using Python's 'multiprocessing' module to improve performance on multi-core systems.
"" The program measures and prints the time taken for the multiplication part.
""
"" <Sample Input/Output Sets>
"" Sample Input Command:
"" $ python3 A3_08_03.py 4 2 10 1
""
"" Sample Output:
"" ---> Initializing 4x4 matrices with random integers mod 10...
"" ---> Starting parallel matrix multiplication with 2 processes...
""
"" --- Matrix A ---
"" [2, 5, 8, 8]
"" [3, 8, 6, 8]
"" [6, 6, 1, 9]
"" [5, 4, 1, 2]
""
"" --- Matrix B ---
"" [9, 2, 0, 4]
"" [2, 8, 2, 8]
"" [9, 8, 8, 2]
"" [3, 2, 7, 7]
""
"" --- Result Matrix C ---
"" [124, 124, 130, 120]
"" [141, 142, 142, 144]
"" [102, 104, 98, 145]
"" [69, 54, 30, 68]
""
"" ---> Time elapsed for multiplication: 0.012345 seconds.
""
"" <Input Details>
"" The program takes all inputs from the command line. The input matrices A and B are not read from a file;
"" they are generated dynamically within the program. The elements are random integers ranging from 0
"" up to (mod_value - 1).
""
"" <Output Details>
"" The primary output is the time elapsed for the multiplication. If the print_switch is set to '1',
"" the program will also print the two input matrices (A and B) and the resulting output matrix (C)
"" to standard output.
""
"" <Time Taken ::: System Details>
""
"" !!! NOTE: Please run the program and fill this section with your results. !!!
""
"" --- How to get System Details ---
""
"""

import sys
import time
import random
from multiprocessing import Pool, Array

# Global variables for worker processes
# These will be inherited by child processes on fork, avoiding costly serialization
A_worker = None
B_worker = None
C_worker = None
DIM_worker = 0

def init_worker(mat_a, mat_b, result_arr, dimension):
    """
    Initializer for each worker process in the pool.
    Sets global variables for the worker's address space.
    """
    global A_worker, B_worker, C_worker, DIM_worker
    A_worker = mat_a
    B_worker = mat_b
    C_worker = result_arr
    DIM_worker = dimension

def multiply_row_chunk(row_indices):
    """
    Worker function to compute multiplication for a chunk of rows.
    Args:
        row_indices (tuple): A tuple containing the start and end row index (exclusive).
    """
    start_row, end_row = row_indices
    for i in range(start_row, end_row):
        for j in range(DIM_worker):
            sum_val = 0
            for k in range(DIM_worker):
                sum_val += A_worker[i][k] * B_worker[k][j]
            # C_worker is a 1D shared array, so we map 2D index to 1D
            C_worker[i * DIM_worker + j] = sum_val

def print_matrix(matrix, name="Matrix"):
    """Helper function to print a matrix."""
    print("\n--- {} ---".format(name))
    if not matrix:
        print("[]")
        return
    # For large matrices, print only a corner
    dimension = len(matrix)
    if dimension > 10:
        print("(Showing top-left 10x10 corner of {}x{} matrix)".format(dimension, dimension))
        for row in matrix[:10]:
            print("[{}, ...]".format(', '.join(map(str, row[:10]))))
        print("...")
    else:
        for row in matrix:
            print("[{}]".format(', '.join(map(str, row))))

def main():
    """Main function to drive the program."""
    # 1. Argument Parsing from Command Line
    if len(sys.argv) != 5:
        print("Usage: python3 parallel_matmul.py <dimension> <num_processes> <mod_value> <print_switch>")
        sys.exit(1)

    try:
        dimension = int(sys.argv[1])
        num_processes = int(sys.argv[2])
        mod_value = int(sys.argv[3])
        print_switch = int(sys.argv[4])
        if dimension <= 0 or num_processes <= 0 or mod_value <= 0 or print_switch not in [0, 1]:
            raise ValueError
    except (ValueError, IndexError):
        print("Error: All arguments must be positive integers, and print_switch must be 0 or 1.")
        sys.exit(1)

    # 2. Matrix Initialization
    print("---> Initializing {}x{} matrices with random integers mod {}...".format(dimension, dimension, mod_value))
    # These matrices will be passed to workers. They are read-only in the workers.
    matrix_a = [[random.randint(0, mod_value - 1) for _ in range(dimension)] for _ in range(dimension)]
    matrix_b = [[random.randint(0, mod_value - 1) for _ in range(dimension)] for _ in range(dimension)]

    # 3. Shared Memory for Result Matrix
    # Using 'i' for signed int. Python's integers handle arbitrary size, so overflow isn't an issue
    # for the sum, and the 'unsigned' requirement is met by random.randint(0, ...).
    shared_result_arr = Array('i', dimension * dimension)

    # 4. Workload Splitting
    # Divide the rows among the number of processes
    chunk_size = dimension // num_processes
    # Handle cases where dimension is not perfectly divisible by num_processes
    row_chunks = []
    for i in range(num_processes):
        start_row = i * chunk_size
        end_row = (i + 1) * chunk_size if i != num_processes - 1 else dimension
        row_chunks.append((start_row, end_row))

    print("---> Starting parallel matrix multiplication with {} processes...".format(num_processes))

    # 5. Parallel Execution and Timing
    start_time = time.time()

    # Create a pool of processes
    # The 'initializer' and 'initargs' pass the large matrices to each worker
    # once upon creation, avoiding repeated serialization.
    pool = Pool(processes=num_processes, initializer=init_worker, initargs=(matrix_a, matrix_b, shared_result_arr, dimension))
    pool.map(multiply_row_chunk, row_chunks)
    pool.close()
    pool.join()


    end_time = time.time()

    elapsed_time = end_time - start_time

    # 6. Output Results
    if print_switch == 1:
        print_matrix(matrix_a, "Matrix A")
        print_matrix(matrix_b, "Matrix B")

        # Convert 1D shared array back to 2D list for printing
        result_matrix = [list(shared_result_arr[i*dimension:(i+1)*dimension]) for i in range(dimension)]
        print_matrix(result_matrix, "Result Matrix C")

    print("\n---> Time elapsed for multiplication: {:.6f} seconds.".format(elapsed_time))


if __name__ == "__main__":
    main()
