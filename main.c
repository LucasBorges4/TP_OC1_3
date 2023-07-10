#include "arquivos.h"
#define TAM 20

//atribui e mostra;
short atribui_vetor(int*, int);
short mostra_vetor(int*, int);

//bubbleSort;
void troca(int*, int*);
void bubbleSort(int*, int);

//concatena vetor

int concatenar_vetor(int* vetor1, int* vetor2, int vetor_resultante, int tam_vet_1, int tam_vet_2);

int main(void){
    srand(time(NULL)); //Semente para a rand, gerar numeros aleatorios com base no tempo;

    int vetor1[TAM], vetor2[TAM];

    atribui_vetor(vetor1, TAM);
    atribui_vetor(vetor2, TAM);
    
    printf("Vetores Originais:\n");
    mostra_vetor(vetor1, TAM);
    mostra_vetor(vetor2, TAM);
    
    printf("Vetores Ordenados pelo bubblesort:\n");
    bubbleSort(vetor1, TAM);
    bubbleSort(vetor2, TAM);
 
    mostra_vetor(vetor1, TAM);
    mostra_vetor(vetor2, TAM);

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

int particao(int vetor[], int esq, int dir) {
    int pivo = vetor[dir];
    int i = (esq - 1);

    for (int j = esq; j <= dir - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[dir]);
    return (i + 1);
}

void quicksort(int vetor[], int esq, int dir) {
    if (esq < dir) {
        int pivoIndex = particao(vetor, esq, dir);
        quicksort(vetor, esq, pivoIndex - 1);
        quicksort(vetor, pivoIndex + 1, dir);
    }
}

int concatenar_vetor(int* vetor1, int* vetor2, int vetor_resultante, int tam_vet_1, int tam_vet_2){
    if (vetor_resultante == NULL) return -1;

    for (int i = 0; i < tam_vet_1; i++){
        vetor_resultante = vetor1[i];
    }
    
    for (int j = 0; j < tam_vet_2; j++){
        vetor_resultante = vetor2[tam_vet_1 + j];
    }

    return 1;
}