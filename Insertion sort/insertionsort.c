#include <stdlib.h>
#include <stdio.h>

const int LENGHT = 10;

void printArr(int A[LENGHT]){
    for(int i = 0; i<LENGHT; i++){
        if (i != LENGHT-1) printf("%d,", A[i]);
        else printf("%d\n", A[i]);
    }
}

void InsertionSort(int *A){
    int i,j,key; // variables used in algorithm
    for(i=1; i<LENGHT; i++){
        key = *(A+i);
        // printf("chiave=%d\n",key);
        j = i-1; //index of end of subarray
        while(j >= 0 && *(A+j) > key){ // if previous element > key
            *(A+j+1) = *(A+j); // move previous forward
            j--; // j = j - 1
        }
        *(A+j+1) = key; // insert key in array
    }
}

int main(int argc, char const *argv[])
{   
    int testArray[LENGHT] = {0, -1, 2, -3, -5, 3, 10, 9, 3, -1};
    printArr(testArray);
    InsertionSort(&testArray);
    printArr(testArray);
    return 0;
}
