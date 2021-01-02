/* PROGRAMMA ORDINAMENTO(SORTING) 10 NUMERI */
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){                                                       // FUNZIONE PER LO SCAMBIO(SWAP) DEI NUMERI
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int array[10];

  printf("\t10 numeri da ordinare: \n");
  printf("------------------------\n");

  for(int i = 0; i < 10; i++){                                                   // PRENDO 10 NUMERI DALL'UTENTE
    printf("inserisci %d° numero: ", i+1);
    scanf("%d", &array[i]);
    while(getchar()!='\n');
    printf("------------------------\n");
  }

  printf("\n------------------------------------------------\n");


  for(int i = 0; i < 10; i++) printf(" %d ",array[i]);
  int i = 0;
  while(i != 10){                                                                // CICLO PER SCORRERE L'ARRAY
    if(array[i] > array[i+1] && i != 9){                                         // CONTROLLO SE PROSSIMO NUMERO è MAGGIORE
        printf(" |-> swap: %d -> %d\n", array[i], array[i+1]);
        printf("------------------------------------------------\n");
        swap(&array[i], &array[i+1]);                                            // SCAMBIO I NUMERI
        i = 0;                                                                   // AZZERO CICLO OGNI VOLTA CHE SCAMBIO I NUMERI PER RICONTROLLARE L'ARRAY
        for(int k = 0; k < 10; k++) printf(" %d ",array[k]);
    }else{ i++; }                                                                // ALTRIMENTI VADO AVANTI
  }

  printf("\n------------------------------------------------\n");

}
