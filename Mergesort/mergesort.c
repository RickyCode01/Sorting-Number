#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../ArrayLib/randArr.h"

const int LENGHT = 10;

void Merge(int *A, int a, int b, int c){
    printf("start:%d, half:%d, end:%d\n", a, b, c);
    // printArray(A, a, c, true);
    int n1 = b-a+1; // lenght of left array
    int n2 = c-b; // lenght of right array
    int L[n1+1], R[n2+1]; // create left & right subarray
    for(size_t i=0; i<n1; i++){ // fill left array
        L[i] = A[a+i];
    }
    for(int j=0; j<n2; j++){ // fill right array
        R[j] = A[b+1+j];
    }
    L[n1] = LENGHT + 1; // save Lenght+1 in last element to mark end of array
    R[n2] = LENGHT + 1;
    // printf("lenght:%d\n", sizeof(L)/sizeof(int)); // print lenght of array
    printf("LEFT: ");
    printArray(L, 0 ,n1+1, true); // debug array
    printf("RIGHT: ");
    printArray(R, 0, n2+1, true);
    // reset indexes to iterate L and R arrays
    int i = 0;
    int j = 0; 
    for(size_t k=a; k<=c; k++){ // copy values in subarrays
        // printf("i:%d, j:%d\n", i, j);
        // printf("k -> %d\n", k);
        if(L[i] <= R[j]){
            // printf("L[i]:%d\n",L[i]);
            A[k] = L[i];
            i++; 
        }else{
            // printf("R[j]:%d\n",R[j]);
            A[k] = R[j];
            j++;
        }
    }
    printf("MERGE: ");
    printArray(A, a, c+1, false);
}

void Mergesort(int *A, int start, int end){
    if(start < end){
        int half = (start + end)/2; // start + end cause right side of array
        // printf("start:%d, half:%d, end:%d\n", start, half, end);
        Mergesort(A, start, half); //set A[start:half]
        Mergesort(A, half+1, end); // set A[half+1:end] 
        Merge(A, start, half, end);
    }
}

int main(int argc, char const *argv[])
{
    int *A = randIntArr(LENGHT, -LENGHT, LENGHT);
    printArray(A, 0, LENGHT, false);
    Mergesort(A, 0, LENGHT-1);
    printArray(A, 0, LENGHT, false);
}
