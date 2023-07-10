//referencia https://www.geeksforgeeks.org/quick-sort/

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