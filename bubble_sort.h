void bubllesort(){
    int vetor[12]={2,5,35,6,3,2,1,36,6,0,4,7};
    int tamanho=12;

    for(int i=0; i < (tamanho-1); i++){
        if(vetor[i] > vetor[i+1]){
            int aux = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = aux;
        }
        bubllesort(vetor);
    }
    for(int j=0; j<= tamanho; j++){
        printf("Vetor %c", vetor[j]);
        printf("\n");
    }
}
