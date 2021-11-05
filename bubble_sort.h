void troca_valor(int *posicao_atual, int *posicao_prox){ 
    int auxiliar = *posicao_atual; 
    *posicao_atual = *posicao_prox; 
    *posicao_prox = auxiliar; 
} 
void bubble_sort(int *vetor, int tamanho_vetor){ 

    if (tamanho_vetor < 1){
        return; 
    } 
    for (int posicao=0; posicao<tamanho_vetor-1; posicao++){ 
        if (*(vetor + posicao) > *(vetor + posicao +1) ){ 
            troca_valor(&vetor[posicao], &vetor[posicao+1]);
        }
    }  
    bubble_sort(vetor, tamanho_vetor-1); 
} 
