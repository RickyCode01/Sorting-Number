#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printarr(int arr[], int inizio, int fine){
  for(int i = inizio; i <= fine; i++ ){
    printf(" %d ", arr[i]);
  }
  printf("\n");
}

int partition(int arr[], int start, int end){
    //printarr(arr, start, end);
    int pivot = arr[start];
    printf("pivot:%d\n",pivot);
    int pos = start; //variabile che memorizza posizione pivot
    int i = start;
    int j = end;
    do{
      if(arr[i] < pivot){
        i++;
      }else{
        if(arr[j] < pivot){
          printf(" %d -> %d\n", arr[i], arr[j]);
          swap(&arr[i], &arr[j]);
          if(arr[j] == pivot)pos = j; //salva la posizione del pivot dopo lo scambio
          i++;
        }else{j--;}
      }
    }while(i<j);
    swap(&arr[pos], &arr[j]); //metto il pivot nella giusta posizione nell'arr
    return j;
}

void Quicksort(int arr[], int start, int end){
  if (start < end) {
      int pindex = partition(arr, start, end); //indice di partizione
      //printf("pi:%d\n", pindex);
      Quicksort(arr, start, pindex - 1); //partizione bassa
      Quicksort(arr, pindex + 1, end); // partizione alta
    }
}

int main(){

    int a = 0;
    int b = 0;
    int size = 9;
    int arr[] = {1,5,7,-9,3,-3,15,0,4,10};
    printarr(arr, 0, size);
    Quicksort(arr, 0, size);
    printarr(arr, 0, size);
}
