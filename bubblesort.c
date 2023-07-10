#include <bubblesort.h>

//Referência: https://www.geeksforgeeks.org/bubble-sort/

void troca(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void bubbleSort(int vetor[], int tam_vetor){
    int i, j;
    bool trocou;
   for (i = 0; i < tam_vetor - 1; i++) {
        trocou = false;
        for (j = 0; j < tam_vetor - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                troca(&vetor[j], &vetor[j + 1]);
                trocou = true;
            }
        }
        
        if (trocou == false)
            break;
    }
}