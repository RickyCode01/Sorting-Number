#include <stdlib.h>
#include <stdio.h>
#include "../ArrayLib/randArr.h"

/* MAX_HEAP ARRAY STRUCTURE 
    1. A[0] MUST BE MAX VALUE OF ARRAY 
    2. A[2*J] IS LEFT CHILD 
    3. A[2*J+1] IS RIGHT CHILD
    4. A[J/2] IS FATHER OF J */

void Max_Heapfy(int* A, int j, int n){
    // rebuild structure max-heap of one branch
    int max = j; // store max val, init to node j = father
    if((2*j)<=n && A[2*j] > A[max]){ // if left child > father
        max = 2*j; // max -> left child
    }
    if((2*j+1)<=n && A[2*j+1] > A[max]){ // if right child > max(father or left child)
        max = 2*j+1;
    }
    if(max != j){ // if max is one of childs
        Swap(A, max, j); // execute swap between max and j node
        // printf("j:%d", j);
        // printArray(A, 0, 10, false);
        Max_Heapfy(A, max, n); // recursive call on child swapped
    }/*else{
        printf("j:%d\n", j);
    }*/
}

void Buid_Max_Heap(int* A, int n){
    // construct max-heap from an unordered array A of n elements
    for (int i = n/2-1; i >= 0; i--){ // start build max heap from last parents = n/2
        Max_Heapfy(A, i, n);
    }
}

void Heapsort(int* A, int n){
    Buid_Max_Heap(A, n);
    for (size_t i = n-1; i > 0; i--){
        Swap(A, 0, i); // swap last element with first to order array
        Max_Heapfy(A, 0, i-1); // reconstruct sub-heap 
    }
    
}

int main(int argc, char const *argv[])
{
    int* A = randIntArr(10, 0 ,10);
    printArray(A, 0, 10, false);
    Heapsort(A, 10);
    printArray(A, 0, 10, false);
    return 0;
}
