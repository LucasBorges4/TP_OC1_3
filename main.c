#include "bubblesort.h"
#include "concatena.h"
#include "quicksort.h"
#include "radixsort.h"

#define TAM 20

//atribui e mostra;
short atribui_vetor(int*, int);
short mostra_vetor(int*, int);

int main(void){
    srand(time(NULL)); //Semente para a rand, gerar numeros aleatorios com base no tempo;

    int vetor1[TAM], vetor2[TAM], vetor_resultante[2*TAM];

    atribui_vetor(vetor1, TAM);
    atribui_vetor(vetor2, TAM);
    
    printf("Vetores Originais:\n");
    mostra_vetor(vetor1, TAM);
    mostra_vetor(vetor2, TAM);
    
    /*printf("Vetores Ordenados pelo Bubblesort:\n");
    bubbleSort(vetor1, TAM);
    bubbleSort(vetor2, TAM);*/
 
    /*printf("Vetores Ordenados pelo Radixsort:\n");
    radixsort(vetor1, TAM);
    radixsort(vetor2, TAM);
    */
    /*
    printf("Vetores Ordenados pelo Quicksort:\n");
    quicksort(vetor1, 0, TAM-1);
    quicksort(vetor2, 0, TAM-1);
    */

    mostra_vetor(vetor1, TAM);
    mostra_vetor(vetor2, TAM);

    /*
    concatena_vetor(vetor1, vetor2, vetor_resultante, TAM, TAM);
    printf("Vetor resultante da concatenação");
    mostra_vetor(vetor_resultante, 2*TAM);
    */

    printf("\n");
    return 0;
}

short atribui_vetor(int vetor[], int tamanho){
    int *p, i = 0;
    int limite_superior;
    limite_superior = rand();

    if (vetor == NULL || tamanho == 0) return -1;

    for (p = &vetor[0]; p < &vetor[tamanho]; p++){
        *p = rand() % (limite_superior % 101); // retornar um valor pseudoaleatorio menor que 1000
        i++;
    }

    return 0;
}

short mostra_vetor(int vetor[], int tamanho){
    if (vetor == NULL || tamanho == 0) return -1;
    
    for (short i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 1;
}


