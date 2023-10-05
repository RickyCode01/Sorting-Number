/* L'algoritmo di counting è un algoritmo che ha una complessità computaione lineare 
e che si basa sul concetto di conteggio dei possibili valori in un array disordinato.
Il principio alla base di questo algoritmo è che a differenza dei normali algoritmi di ordinamento
questo sfrutta delle informazioni aggiuntive sugli elementi come il range di valori ammessi */

#include <stdlib.h>
#include <stdio.h>
#include "../ArrayLib/randArr.h"

const int N = 10; // #elementi array
const int MAX = 10; // max value of integer element

int *Countingsort(int *A, int n, int r){ // n = #elementi, r = range valori
    int C[r]; // array di supporto per contatori valori
    int *B = zeroArray(n);
    for (size_t i = 0; i < r; i++){
        C[i] = 0; // azzero ogni valore dell'array
    }
    for (size_t j = 0; j < n; j++){ // conteggio elementi array
        C[A[j]]++; // incrementa il contatore relativo al valore A[j]
    }
    printf("Counting array = ");
    printArray(&C, 0, r, false); // print counter array
    C[0]--; /* aggiusto il primo prefisso diminuendolo di un'unità 
    poichè le posizioni in un'array partono dall'elemento 0 */
    for (size_t i = 1; i < r; i++){ // calcolo dei prefissi
        /* I prefissi contengono la posizione finale di ciascun valore.
        Calcolati sommando i prefissi precedenti cioè sommando i conteggi precedenti 
        NOTA: parto dal secondo elemento poichè il primo prefisso è già calcolato*/ 
        C[i] = C[i] + C[i-1];
    }
    printf("Prefix array = ");
    printArray(&C, 0, r, false); // print counter array with prefix
    for (int j = n-1; j >= 0; j--){ // ricreo il nuovo array B
        //printf("A[j]:%d\n", A[j]);
        B[C[A[j]]] = A[j]; // scrivo A[j] nell'array B al prefisso calcolato in C[A[j]]
        C[A[j]]--; // decremento il prefisso relativo al valore A[j]
    }
    return B;
}

int main(int argc, char const *argv[])
{   
    int *A = randIntArr(N, 0, MAX);
    printArray(A, 0, N, false);
    int *B = Countingsort(A, N, MAX+1);
    printArray(B, 0, N, false);
    return 0;
}
