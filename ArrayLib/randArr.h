/* header file to use functions in randArr */
#include <stdbool.h>

/* function to get a random intger array -> return pointer to array
min/max = minimum/maximum value of int */
extern int *randIntArr(int len, int min, int max);
// function to print array
extern void printArray(int *A, int start, int end, bool space);
