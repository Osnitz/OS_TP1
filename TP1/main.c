//
// Created by matthieu on 01/10/24.
//

#include "main.h"
int q1_main();
int q2_main();
int q3_main();


int main() {
    //printf("Hello, World!\n");
    printf("------------ 1- Memory segmentation ------------\n");
    q1_main();
    printf("\n------------ 2- File projection in memory ------------\n");
    q2_main();
    printf("Check the file 'test.txt' to see the result of the projection\n");
    printf("\n------------ 3- Circular, double linked list ------------\n");
    q3_main();

    return 0;
}
