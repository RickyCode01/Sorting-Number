#include <stdlib.h>
#include <stdio.h>

void InsertionSort(int *A, int start, int end){
    int i,j,key; // variables used in algorithm
    for(i=start; i<end; i++){
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

/* int main(int argc, char const *argv[])
{   
    int testArray[10] = {0, -1, 2, -3, -5, 3, 10, 9, 3, -1};
    printArr(testArray);
    InsertionSort(&testArray, 0, 10);
    printArr(testArray);
    return 0;
} */
