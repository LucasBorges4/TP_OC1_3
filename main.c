#include "arquivos.h"
#define TAM 10

int atribui_vetor(int vetor[], int tamanho){
    int *p, i = 0;
    for (p = &vetor[0]; p < &vetor[tamanho]; p++){
        *p = 2*i;
        i++;
    }
}

int main(void){
    int vetor1[TAM], vetor2[TAM];

    atribui_vetor(vetor1, TAM);
    atribui_vetor(vetor2, TAM);

    printf("Primeira posição do vetor: %d\n", vetor1[0]);

    printf("\n");
    return 0;
}