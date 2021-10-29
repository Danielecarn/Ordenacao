void troca_valor(int *posicaoAtual, int *posicaoProx){ 
    int auxiliar = *posicaoAtual; 
    *posicaoAtual = *posicaoProx; 
    *posicaoProx = auxiliar; 
} 
void bubble_sort(int *vetor, int tamanhoVetor){ 
    if (tamanhoVetor < 1){
        return; 
    }
    for (int posicaoVetor=0; posicaoVetor<tamanhoVetor-1; posicaoVetor++){ 
        if (vetor[posicaoVetor] > vetor[posicaoVetor+1]){ 
            troca_valor(&vetor[posicaoVetor], &vetor[posicaoVetor+1]);
        }
    }  
    bubble_sort(vetor, tamanhoVetor-1); 
} 
