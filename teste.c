int concatena_vetor(int* vetor1, int* vetor2, int* vetor_resultante, int tam_vet_1, int tam_vet_2);

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
