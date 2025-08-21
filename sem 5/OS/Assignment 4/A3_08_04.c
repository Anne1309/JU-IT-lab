/*
============================================================================
  >Team: 08
  >Name: Debodit Ray, Roll: 13
  >Name: Kaustav Mondal , Roll: 17
  >Name: Anuska Nath , Roll: 03
  >Date: 19/08/2025
============================================================================

Assignment Details:
  The objective of this programming assignment is to use mmap() call and
observe page-fault using the ‘sar’ command.
A big file (about 8GB) should be created using the ‘fallocate’ command.
This big file should be written with a single byte value (say X) at a specific
offset (say F). Both the values and the offset should be generated using a
random function. Please do remember this random function should
generate a quantity anywhere between 0 and 8G for the value of F and
between 0-255 for the value of X.
The above big file should also be mapped in the virtual address space
using mmap() call. Once it is mapped, the data should be read from the
same specific offset (F). Now, if the data read is X`; then verify that X and
X` are the same. In case of verification failure, an error message is to be
printed and also the program should terminate. Note that, the offset value F
can be anywhere between 0 and 8G and you should display the offset as
hex number format.
This sequence of writing and reading data to/from a specific offset and also
verification should be put in a while loop to go forever.
In another terminal execute the command ‘sar –B 1’ to observe for the
page fault. This command should be started before the above program is
put under execution. So, one can observe that the page faults are
increasing, once the above program starts executing.
The output of the program and the ‘sar’ command should be pasted as a
comment at the beginning of the program file as indicated by the
guidelines.

----------------------------------------------------------------------------
  Setup and Execution Commands
----------------------------------------------------------------------------

1. Command for creating an 8GB file:
   fallocate -l 8G bigfile.dat

2. Compilation Command:
   gcc -o A3_08_04 A3_08_04.c

3. Command to observe page faults in another terminal:
   sar -B 1
   
4. Execution Command:
   ./A3_08_04 largefile.dat



----------------------------------------------------------------------------
  Sample Output (Program Output)
----------------------------------------------------------------------------

File 'bigfile.dat' (size: 8589934592 bytes) mapped successfully. Starting write/read loop...
OK: Wrote 0xC6 and read 0xC6 at offset 0xDD028AB
OK: Wrote 0x38 and read 0x38 at offset 0x127245B6A
OK: Wrote 0xF8 and read 0xF8 at offset 0x15267DF0E
OK: Wrote 0xCE and read 0xCE at offset 0x170A7F31D
OK: Wrote 0x3D and read 0x3D at offset 0x143AB2A15
OK: Wrote 0x60 and read 0x60 at offset 0x31C6F43
OK: Wrote 0x97 and read 0x97 at offset 0x5EB3612F
OK: Wrote 0x43 and read 0x43 at offset 0x1284AFC5B
OK: Wrote 0x61 and read 0x61 at offset 0x159AEECE6
OK: Wrote 0x6C and read 0x6C at offset 0x53889C85
OK: Wrote 0x17 and read 0x17 at offset 0x60EBABD0
OK: Wrote 0x81 and read 0x81 at offset 0x4A925C61
OK: Wrote 0x90 and read 0x90 at offset 0x31467EFD
OK: Wrote 0xAD and read 0xAD at offset 0x17E4C429C
OK: Wrote 0xC2 and read 0xC2 at offset 0x1330F6963
OK: Wrote 0x05 and read 0x05 at offset 0x5C1AA313
OK: Wrote 0x35 and read 0x35 at offset 0x60EEB8E7
OK: Wrote 0x90 and read 0x90 at offset 0x17B53EDD4
OK: Wrote 0x76 and read 0x76 at offset 0x155B02391
OK: Wrote 0xFB and read 0xFB at offset 0x667BE5F3
OK: Wrote 0xCB and read 0xCB at offset 0x1323FE373
OK: Wrote 0x2D and read 0x2D at offset 0xC150BB9
OK: Wrote 0x2A and read 0x2A at offset 0x43E21D37
OK: Wrote 0xC6 and read 0xC6 at offset 0x21F2B5AE
OK: Wrote 0x29 and read 0x29 at offset 0x12536A3F3
OK: Wrote 0x3C and read 0x3C at offset 0x5D6EAA75
OK: Wrote 0x23 and read 0x23 at offset 0x16F562157
OK: Wrote 0xF7 and read 0xF7 at offset 0x7BB9D2D1
OK: Wrote 0x88 and read 0x88 at offset 0x699A908E
OK: Wrote 0x7B and read 0x7B at offset 0x6E98CAC
OK: Wrote 0xEE and read 0xEE at offset 0xBE7EB37
OK: Wrote 0xA7 and read 0xA7 at offset 0x10665D4DA
OK: Wrote 0xDE and read 0xDE at offset 0x1D87A4FE
OK: Wrote 0x8D and read 0x8D at offset 0x23B53AB2
OK: Wrote 0x80 and read 0x80 at offset 0x9968913
OK: Wrote 0xF6 and read 0xF6 at offset 0x112D6BA37
OK: Wrote 0x4D and read 0x4D at offset 0x142923D61
OK: Wrote 0x1E and read 0x1E at offset 0x777C73BF
OK: Wrote 0xAC and read 0xAC at offset 0x159E059AE
OK: Wrote 0x59 and read 0x59 at offset 0x1436CDC12
....


----------------------------------------------------------------------------
  Sample Output (sar Command Output)
----------------------------------------------------------------------------
Linux 5.15.0-60-generic (adminpc-HP-Pro-Tower-280-G9-PCI-Desktop-PC) 	19/08/25 	_x86_64_	(12 CPU)

03:52:15 PM IST  pgpgin/s pgpgout/s   fault/s  majflt/s  pgfree/s pgscank/s pgscand/s pgsteal/s    %vmeff
03:52:16 PM IST      0.00      0.00     31.00      0.00   1211.00      0.00      0.00      0.00      0.00
03:52:17 PM IST      0.00     64.00     58.00      0.00    378.00      0.00      0.00      0.00      0.00
03:52:18 PM IST      0.00      0.00      3.00      0.00    175.00      0.00      0.00      0.00      0.00
03:52:19 PM IST      0.00      0.00      5.00      0.00   1710.00      0.00      0.00      0.00      0.00
03:52:20 PM IST      0.00     84.00     42.00      0.00    227.00      0.00      0.00      0.00      0.00
03:52:21 PM IST      0.00    252.00 300758.00      0.00   1294.00      0.00      0.00      0.00      0.00
03:52:22 PM IST      0.00 256004.00 437133.00      0.00   3882.00      0.00      0.00      0.00      0.00
03:52:23 PM IST      0.00 781592.00 382555.00      0.00   8341.00      0.00      0.00      0.00      0.00
03:52:24 PM IST      0.00 762424.00 374318.00      0.00   5785.00      0.00      0.00      0.00      0.00
03:52:25 PM IST      0.00 731088.00 372730.00      0.00   5403.00      0.00      0.00      0.00      0.00
03:52:26 PM IST      0.00 790256.00 371625.00      0.00   6882.00      0.00      0.00      0.00      0.00
03:52:27 PM IST      0.00 1049820.00 327437.00      0.00   8286.00      0.00      0.00      0.00      0.00
03:52:28 PM IST      0.00 607816.00 424352.00      0.00   6076.00      0.00      0.00      0.00      0.00
03:52:29 PM IST      0.00 591724.00 401179.00      0.00   5167.00      0.00      0.00      0.00      0.00
03:52:30 PM IST      0.00 769864.00 369179.00      0.00   5599.00      0.00      0.00      0.00      0.00
03:52:31 PM IST      0.00 289232.00 322417.00      0.00   2801.00      0.00      0.00      0.00      0.00
03:52:32 PM IST      0.00 718548.00 111038.00      0.00   6761.00      0.00      0.00      0.00      0.00
03:52:33 PM IST      0.00      0.00    359.00      0.00   1623.00      0.00      0.00      0.00      0.00
03:52:34 PM IST      0.00      0.00      2.00      0.00     73.00      0.00      0.00      0.00      0.00
03:52:35 PM IST      0.00      0.00    835.00      0.00   7603.00      0.00      0.00      0.00      0.00
^C
Average:         0.00 367438.40 209802.80      0.00   3963.85      0.00      0.00      0.00      0.00


============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int fd;
    unsigned char *mapped_region;
    struct stat file_stats;
    uint64_t file_size;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        fprintf(stderr, "Hint: First, create a large file with 'fallocate -l 8G <filename>'\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    if (fstat(fd, &file_stats) == -1) {
        perror("Error getting file stats");
        close(fd);
        return EXIT_FAILURE;
    }
    file_size = file_stats.st_size;

    mapped_region = mmap(NULL,
                         file_size,
                         PROT_READ | PROT_WRITE,
                         MAP_SHARED,
                         fd,
                         0);

    if (mapped_region == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("File '%s' (size: %lu bytes) mapped successfully. Starting write/read loop...\n", argv[1], file_size);

    while (1) {
        uint64_t offset = ((uint64_t)rand() << 32) | rand();
        offset %= file_size;

        unsigned char value_to_write = rand() % 256;

        mapped_region[offset] = value_to_write;

        unsigned char value_read_back = mapped_region[offset];

        if (value_to_write == value_read_back) {
            printf("OK: Wrote 0x%02X and read 0x%02X at offset 0x%lX\n",
                   value_to_write, value_read_back, offset);
        } else {
            fprintf(stderr, "ERROR: Verification FAILED at offset 0x%lX! Wrote 0x%02X, but read 0x%02X\n",
                    offset, value_to_write, value_read_back);

            munmap(mapped_region, file_size);
            close(fd);
            return EXIT_FAILURE;
        }

        fflush(stdout);
    }

    munmap(mapped_region, file_size);
    close(fd);

    return EXIT_SUCCESS;
}

