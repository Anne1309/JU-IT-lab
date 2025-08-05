"""
Parallel Matrix Multiplication using multiprocessing in Python

Usage:
    python3 parallel_matrix_multiplication.py <dimension> <num_processes> <mod> <print_switch>

Example:
    python3 parallel_matrix_multiplication.py 3000 4 100 0

Timing and CPU Usage:
----------------------
Matrix dimension: 3000 x 3000
Processes used: 4
Matrix value mod: 100

Execution Time (multiplication only): <INSERT_TIME> seconds

CPU Utilization (captured using mpstat/sar):
Run the following command in a separate terminal during execution:
    mpstat -P ALL 1
Or:
    sar -u 1 3

(Attach the CPU output from the terminal here)
"""

import numpy as np
import multiprocessing as mp
import sys
import time

def matrix_worker(start_row, end_row, A, B, output_queue):
    """Worker function for multiprocessing to compute a sub-matrix product."""
    result = np.dot(A[start_row:end_row], B)
    output_queue.put((start_row, result))

def parallel_matrix_multiply(A, B, num_processes):
    n = A.shape[0]
    chunk_size = n // num_processes
    processes = []
    output_queue = mp.Queue()

    for i in range(num_processes):
        start_row = i * chunk_size
        end_row = (i + 1) * chunk_size if i != num_processes - 1 else n
        p = mp.Process(target=matrix_worker, args=(start_row, end_row, A, B, output_queue))
        processes.append(p)
        p.start()

    # Collect results
    result = np.zeros((n, n), dtype=np.uint32)
    for _ in range(num_processes):
        start_row, partial_result = output_queue.get()
        result[start_row:start_row + partial_result.shape[0], :] = partial_result

    for p in processes:
        p.join()

    return result

def main():
    if len(sys.argv) != 5:
        print("Usage: python3 parallel_matrix_multiplication.py <dimension> <num_processes> <mod> <print_switch>")
        sys.exit(1)

    dimension = int(sys.argv[1])
    num_processes = int(sys.argv[2])
    mod_value = int(sys.argv[3])
    print_switch = int(sys.argv[4])

    # Initialize matrices with random integers (0 to mod_value)
    A = np.random.randint(0, mod_value, size=(dimension, dimension), dtype=np.uint32)
    B = np.random.randint(0, mod_value, size=(dimension, dimension), dtype=np.uint32)

    # Start timing for multiplication only
    start_time = time.perf_counter()
    result = parallel_matrix_multiply(A, B, num_processes)
    end_time = time.perf_counter()

    print(f"\nMatrix Multiplication Completed in {end_time - start_time:.4f} seconds\n")

    if print_switch == 1:
        print("Matrix A:")
        print(A)
        print("\nMatrix B:")
        print(B)
        print("\nResultant Matrix:")
        print(result)

if __name__ == "__main__":
    mp.set_start_method('fork')  # Use 'fork' for Unix-like systems
    main()
