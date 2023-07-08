#include "arquivos.h"
#define TAM 10

short atribui_vetor(short vetor[], short tamanho){
    short *p, i = 0;
    short limite_superior;
    limite_superior = rand();

    if (vetor == NULL || tamanho == 0) return -1;

    for (p = &vetor[0]; p < &vetor[tamanho]; p++){
        *p = rand() % (limite_superior % 100); // retornar um valor pseudoaleatorio menor que 1000
        i++;
    }

    return 0;
}

int main(void){
    srand(time(NULL)); //Semente para a rand, gerar numeros aleatorios com base no tempo;

    short vetor1[TAM], vetor2[TAM];

    atribui_vetor(vetor1, TAM);
    atribui_vetor(vetor2, TAM);

    printf("\n");
    return 0;
}