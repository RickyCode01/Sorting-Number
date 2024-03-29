/* Algoritmo quicksort = è un tipo di algoritmo divide et impera che ha una complessità media
computazionale pari a O(n log n) ma non è un algoritmo ottimo come ad esempio il merge sort.
A differenza di questo ultimo l'ordinamento viene eseguito nella procedura partition che si occupa
di ordinare gli elementi dell'array a destra e sinistra di un elemento perno il quale si troverà
nella sua posizione finale terminata la procedura. Richiamando questa in modo ricorsivo a dx e sx del perno
viene eseguito l'odinamento */

#include <stdlib.h>
#include <stdio.h>
#include "../ArrayLib/randArr.h"

int PPartition(int *A, int start, int end, int pivot){  
  int key = A[pivot];
  printf("key:%d\n", key);
  Swap(A, pivot, end); // scambio la pivot con l'ultimo elemento
  int i = start - 1; // l'indice i punta sempre all'ultimo valore minore del pivot trovato
  for (size_t j = start; j <= end-1; j++){
    if(A[j] < key){ // se trovo un valore minore del pivot
      i++;
      Swap(A, i, j); // lo sposto sull'indice i
    } 
  }
  Swap(A, i+1, end); // sposto il mio pivot dopo l'ultimo elemento minore trovato
  return i+1;
}

int Partition(int *A, int start, int end){
  int pivot = A[start]; // scelgo il pivot come primo valore dell'array
  int i = start;
  int j = end;
  while(i < j){ // cicla fino ad aver controllato tutti gli elementi dell'array
    while (A[j] > pivot)j--; // decremento a dx finchè trovo un valore > pivot
    if(i < j){ // se non ho superato il pivot
      printf("i:%d -> j:%d\n", i, j);
      Swap(A, i, j); // scambio gli elementi: pivot -> elemento dx > del pivot
      printArray(A, start, end+1, false);
      i++; // incremento l'indice sx perchè questo elemento è ordinato rispetto al pivot
    }
    /* di seguito ripeto la procedura appena applicata partendo dall'indice a sx dopo 
    l'elemento appena scambiato */
    while(A[i] < pivot)i++;
    if(i < j){
      printf("i:%d -> j:%d\n", i, j);
      Swap(A, i, j);
      printArray(A, start, end+1, false);
      j--;
    }
  }
  return i; // ritorno l'ultima posizione del pivot
}

void Quicksort(int arr[], int start, int end){
  if (start < end) {
    // int myrand = start + rand()%(end-start);
    printf("end: %d\n", end);
    int pindex = PPartition(arr, start, end, end); //indice di partizione
    printf("pi:%d\n", pindex);
    printArray(arr, start, end+1, false);
    Quicksort(arr, start, pindex - 1); //partizione bassa
    Quicksort(arr, pindex + 1, end); // partizione alta
  }
}

int main(){
  int *A = randIntArr(10, 0, 10);
  printArray(A, 0, 10, false);
  Quicksort(A, 0, 9);
  printArray(A, 0, 10, false);
}
