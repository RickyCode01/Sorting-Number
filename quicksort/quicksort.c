/* Algoritmo quicksort = è un tipo di algoritmo divide et impera che ha una complessità media
computazionale pari a O(nlog n) ma non è un algoritmo ottimo come ad esempio il merge sort.
A differenza di questo ultimo l'ordinamento viene eseguito nella procedura partition che si occupa
di ordinare gli elementi dell'array a destra e sinistra di un elemento perno il quale si troverà
nella sua posizione finale terminata la procedura. Richiamando questa in modo ricorsivo a dx e sx del perno
viene eseguito l'odinamento */

#include <stdlib.h>
#include <stdio.h>
#include "../ArrayLib/randArr.h"

void swap(int *A, int a, int b){
    int temp = *(A+a);
    *(A+a) = *(A+b);
    *(A+b) = temp; 
}

int Partition(int *A, int start, int end){
  int pivot = *(A+start); // scelgo il pivot come primo valore dell'array
  int i = start;
  int j = end;
  while(i < j){ // cicla fino ad aver controllato tutti gli elementi dell'array
    while (A[j] > pivot)j--; // decremento a dx finchè trovo un valore > pivot
    if(i < j){ // se non ho superato il pivot
      printf("i:%d -> j:%d\n", i, j);
      swap(A, i, j); // scambio gli elementi: pivot -> elemento dx > del pivot
      printArray(A, start, end+1, false);
      i++; // incremento l'indice sx perchè questo elemento è ordinato rispetto al pivot
    }
    /* di seguito ripeto la procedura appena applicata partendo dall'indice a sx dopo 
    l'elemento appena scambiato */
    while(A[i] < pivot)i++;
    if(i < j){
      printf("i:%d -> j:%d\n", i, j);
      swap(A, i, j);
      printArray(A, start, end+1, false);
      j--;
    }
  }
  return i; // ritorno l'ultima posizione del pivot
}

void Quicksort(int arr[], int start, int end){
  if (start < end) {
    int pindex = Partition(arr, start, end); //indice di partizione
    //printf("pi:%d\n", pindex);
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
