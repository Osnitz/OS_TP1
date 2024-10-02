//
// Created by matthieu on 01/10/24.
//
#include "main.h"
int q2_main() {
    //  2 - Projection of a file in memory
    const char* filename = "test.txt";
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("fstat");
        return 1;
    }
    size_t file_size = file_stat.st_size;

    // Mapping in memory
    char *file_in_memory = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_in_memory == MAP_FAILED) {
        perror("Error in memory mapping");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Inversion of the file content
    for (size_t i = 0; i < file_size / 2; i++) {
        char tmp = file_in_memory[i];
        file_in_memory[i] = file_in_memory[file_size - 1 - i];
        file_in_memory[file_size - 1 - i] = tmp;
    }

    // End mapping
    if (munmap(file_in_memory, file_size) == -1) {
        perror("Error in memory unmapping");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);

    return 0;
}