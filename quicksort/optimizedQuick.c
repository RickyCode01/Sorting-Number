#include <stdlib.h>
#include <stdio.h>
#include "nearMedian.c" // integra anche libreria array

int Partition(int *A, int start, int end){
	int pivot = nearMedian(A, start, end); // valore pivot (non indice)
	/* la ricerca della mediana ordina l'array in parte!! */
	printf("pivot=%d\n", pivot);
	printArray(A, start, end+1, false);
	// int ipivot = start; // indice pivot
	int i = start;
	int j = end;
	while (i < j){
		if(i < j && A[i] == A[j])j--; // evita il loop se si hanno ripertiozini del perno
		// diminuisco l'indice superiore finchè valore < perno
		while(i < j && A[j] > pivot)j--;
		// if(A[j] == pivot) ipivot = i;
		// incremento l'indice inferiore finchè valore > perno
		while(i < j && A[i] < pivot)i++;
		// if(A[i] == pivot) ipivot = j;
		printf("i:%d -> j:%d\n", i, j);
		Swap(A, i, j);
		printArray(A, start, end+1, false);
	}
	// Swap(A, i, ipivot);
	return i; // ritorno posizione del perno
}

void Quicksort(int *A, int start, int end){
	if ((end-start) > 10) {
		int pivot = Partition(A, start, end); // perno di partizione
		printf("ipivot=%d\n", pivot);
		printArray(A, start, end+1, false);
		Quicksort(A, start, pivot - 1); // partizione bassa
		Quicksort(A, pivot + 1, end); // partizione alta
	} else {
		printArray(A, start, end+1, false);
		// passa un elemento extra per eseguire correttamento ciclo for
		InsertionSort(A, start, end+1);
	}
}

int main(int argc, char const *argv[])
{   
	int size = 15;
	int *A = randIntArr(size, 0, 100);
	// int A[] = {25 ,77 ,2 ,12 ,13 ,44 ,65 ,31 ,83 ,32 ,14 ,95 ,96 ,48 ,7};
	// size = sizeof(A)/sizeof(A[0]);
	printArray(A, 0, size, false);
	Quicksort(A, 0, size-1);
	printArray(A, 0, size, false);
	return 0;
}
