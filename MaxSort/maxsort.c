#include <stdio.h>
#include <stdlib.h>
#include "../ArrayLib/randArr.h"

const int LENGHT = 10;

int findMax(int *A, size_t size){
    int max = A[0]; // initialize max value
    size_t index = 0;// init index of max to 0
    for (size_t i = 0; i < size; i++){
        if (*(A+i) > max){  
            max = *(A+i);
            index = i;
        }
    }
    return index; // return index of max value
}

void Swap(int *A, int a, int b){
    /* fun used to swap two elements from an array */
    int temp = *(A+a); // saving a in a temporary variable
    *(A+a) = *(A+b); // a <- b
    *(A+b) = temp; // b <- b
}

void Maxsort(int* A, int size){
    /* Sorting Algorithm base on swap max values on last position to order array*/
    for (size_t i = size; i > 0; i--){
        int imax = findMax(A, i); // find max value
        if(*(A+imax) != *(A+i-1)){ // avoid useless swap
            printf("%d -> %lu\n", imax, i-1); // debug
            Swap(A, imax, i-1); // swap max with last value
            printArray(A, 0, size, true);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int *A = randIntArr(LENGHT, 0, 10);
    printArray(A, 0, LENGHT, true);
    // printf("Index="%d -> Max=%d\n",findMax(A, LENGHT),A[findMax(A, LENGHT)]);
    // int imax = findMax(A, LENGHT);
    // printf("%d -> %d\n", imax, 0);
    // Swap(A, imax, 0);
    // printArray(A, 0, LENGHT, false);
    Maxsort(A, LENGHT);
    // printArray(A, 0, LENGHT, false);
    return 0;
}
