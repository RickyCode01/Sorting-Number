#include <stdio.h>
#include <stdlib.h>
#include "../ArrayLib/randArr.h"

void InsertionSort(int *A, int p, int r){
    int i,j,key;
    for(i=p+1; i<r; i++){ // scorro la lista
        key = A[i]; // elemento nuovo da riordinare
        // printf("key:%d\n", key);
        j = i-1; // indice finale elemento da riordinare
        while(j >= p && A[j] > key){  // finchè l'ordine è sbagliato
            A[j+1] = A[j]; // scambio gli elementi disordinati
            j--;
        }
        A[j+1] = key; // riodino l'elemento chiave
    }
}

int nearMedian(int *A, int p, int r){
    int n = r-p; // lunghezza array
    // printf("n = %d\n", n);
    if(n > 10){ // se la lunghezza supera i 10 elementi
        int groups = (r-p)/5; // divido la mia lista in gruppi di 5
        // printf("grp_n = %d\n", groups);
        int medians[groups];
        for (size_t i = 0; i < groups; i++){ // ordino i gruppi e di essi ricavo le mediane
            int start = i*5;
            int end = start + 4; // parto da 0 quindi devo togliere un elemento
            // printf("i:%d - f:%d\n", start, end);
            InsertionSort(A, start, end);
            // printArray(A, start, end+1, false);
            medians[i] = A[start + 2]; // la mediana di 5 elementi è il terzo elemento
        }
        // printArray(medians, 0, 2, false);
        // InsertionSort(medians, 0, groups); // ricavo la mediana delle mediane
        // return(medians[groups/2]); // ritorno il valore della mediana
        return(nearMedian(medians, 0, groups));
    }else{ // se l'array è abbanza piccolo ordino e ricavo la mediana
        InsertionSort(A, p, r);
        if(n%2 == 0)return(A[(n/2)-1]);
        return(A[n/2]);
    }
}


// int main(int argc, char const *argv[])
// {
//     int *A = randIntArr(12, 0, 100);
//     // InsertionSort(A, 0, 11);
//     printArray(A, 0, 12, false);
//     int test = nearMedian(A, 0, 11);
//     printf("near_median = %d\n", test);
//     InsertionSort(A, 0, 11);
//     printArray(A, 0, 12, false);
//     return 0;
// }