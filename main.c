#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM 10000

//atribui e mostra;
short atribui_vetor(int*, int);
short mostra_vetor(int*, int);

void radixsort(int *vet, int n);

void troca(int* xp, int* yp);
void quicksort(int vetor[], int esq, int dir);

int concatena_vetor(int* vetor1, int* vetor2, int* vetor_resultante, int tam_vet_1, int tam_vet_2);

void troca(int*, int*);
void bubbleSort(int*, int);

int main(void){
    srand(time(NULL)); //Semente para a rand, gerar numeros aleatorios com base no tempo;

    int vetor1[TAM];
    int vetor2[TAM], vetor_resultante[2*TAM];

    atribui_vetor(vetor1, TAM);
    atribui_vetor(vetor2, TAM);
    
    /*
    printf("Vetores Originais:\n");
    mostra_vetor(vetor1, TAM);
    mostra_vetor(vetor2, TAM);
    */
    
    
    //printf("Vetores Ordenados pelo Bubblesort:\n");
    //bubbleSort(vetor1, TAM);
    //bubbleSort(vetor2, TAM);
    

    
    //printf("Vetores Ordenados pelo Radixsort:\n");
    //radixsort(vetor1, TAM);
    //radixsort(vetor2, TAM);
    

    //printf("Vetores Ordenados pelo Quicksort:\n");
    //quicksort(vetor1, 0, TAM-1);
    //quicksort(vetor2, 0, TAM-1);
    
    
    //mostra_vetor(vetor1, TAM);
    //mostra_vetor(vetor2, TAM);
    
    concatena_vetor(vetor1, vetor2, vetor_resultante, TAM, TAM);
    //printf("Vetor resultante da concatenação:\n");
    //mostra_vetor(vetor_resultante, 2*TAM);
    

    printf("\n");
    return 0;
}

short atribui_vetor(int vetor[], int tamanho){
    int *p, i = 0;
    int limite_superior;
    limite_superior = rand();

    if (vetor == NULL || tamanho == 0) return -1;

    for (p = &vetor[0]; p < &vetor[tamanho]; p++){
        *p = rand() % (limite_superior % TAM);
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


void radixsort(int *vet, int n) {
	int i, exp = 1, m = 0, bucket[n], temp[n];

	for(i = 0; i < n; i++) {
		if(vet[i] > m) {
			m = vet[i];
		}
	}

	while((m/exp) > 0) {
		for (i = 0; i < n; i++) {
			bucket[i] = 0;
		}
		for(i = 0; i < n; i++) {
			bucket[(vet[i] / exp) % 10]++;
		}
		for(i = 1; i < n; i++) {
			bucket[i] += bucket[i-1];
		}
		for(i = (n - 1); i >= 0; i--) {
			temp[--bucket[(vet[i] / exp) % 10]] = vet[i];
		}
		for(i = 0; i < n; i++) {
			vet[i] = temp[i];
		}
		exp *= 10;
	}
}

void troca(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
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


int concatena_vetor(int* vetor1, int* vetor2, int* vetor_resultante, int tam_vet_1, int tam_vet_2){
    //if (vetor_resultante == NULL) return -1;

    for (int i = 0; i < tam_vet_1; i++){
        vetor_resultante[i] = vetor1[i];
    }
    
    for (int j = 0; j < tam_vet_2; j++){
        vetor_resultante[tam_vet_1+j] = vetor2[j];
    }

    return 1;
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