//
// Created by matthieu on 01/10/24.
//
#include "main.h"
int data = 42;
int bss;
const char* str = "Hello World!";

int q1_main() {
    //printf("Hello, World!\n");

    int *heap_var = (int*) malloc(sizeof(int));
    *heap_var = 100;

    int stack_var = 42;


    printf("DATA adress: %p\n", (void*)&data);
    printf("BSS adress: %p\n", (void*)&bss);
    printf("Text adress: %p\n", (void*)&str);
    printf("Heap adress: %p\n", (void*)heap_var);
    printf("Stack adress: %p\n", (void*)&stack_var);
    printf(".txt adress: %p\n", (void*)&q1_main);
    printf("LibC Function address (strcpy): %p\n", (void*)&strcpy);

    void *mmap_region = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mmap_region == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }
    printf("Mmap allocated address: %p\n", mmap_region);


    pid_t ppid = getpid();

    pid_t pid = fork();

    if(pid==0) {
        char command[50];
        sprintf(command, "%d", ppid);
        printf("\n Memory map of PID %s:\n", command);
        execlp("pmap", "pmap", "-X", command, NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
    }
    else if(pid>0) {
        wait(NULL);
    }
    else {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    free (heap_var);
    return 0;
}