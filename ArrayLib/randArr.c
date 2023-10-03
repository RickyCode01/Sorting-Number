#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "randArr.h"

void printArray(int *A, int start, int end, bool space){ // function to print array
    printf("[");
    for(int i=start; i<end; i++){
        if(i<end-1)printf("%d ,", *(A+i));
        else printf("%d", *(A+i));
    }
    if (space){
        printf("] "); 
    }else{
        printf("]\n"); 
    }
     
}

int * randIntArr(int len, int min, int max){
    int * array = (int *) calloc((size_t) len, sizeof(int));
    array = memset(array, 0,(size_t) len);
    /* initialize random number generator */
    srand((unsigned) time(NULL));
    /* fill array w random number */
    for(int i=0; i<len; i++){
        *(array+i) = (rand() % (max-min+1))+min;
    }
    // printArray(array, len);
    return array;
}

// int main(int argc, char const *argv[])
// {
//     int *A = randIntArr(10, -10, 10); 
//     return 0;
// }
