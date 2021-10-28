#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void bubbleSort(int *v, int n){ 
    if (n < 1)return; 
 
    for (int i=0; i<n; i++) 
        if (v[i] > v[i+1]) 
            swap(&v[i], &v[i+1]);  
    bubbleSort(v, n-1); 
} 

int main(){
    int tam,i,*v;
    scanf("%d",&tam);
    v=(int*)malloc(tam*sizeof(int));
    for(i=0;i<tam;i++)scanf("%d",&v[i]);
    bubbleSort(v,tam-1);
    for(i=0;i<tam;i++)printf("%d ",v[i]);
    return 0;
}
/*
    char caractere[2];
    int k = 0;
    while(fgets(caractere, 2, lerN) != NULL){
        letras[k] = caractere[k];
        k++;
    }
    printf("Letras:\n");
    for(i=0;i<qtd_linhas;i++)printf("%c",letras[i]);

    
    for(int b=0; b<=qtd_linhas; b++){
        fscanf(lerL, "%c", &l);
        letras[b] = l;
    }
    printf("Letras:\n");
    for(i=0;i<qtd_linhas;i++)printf("%c",letras[i]); */

        /*
    int letras[qtd_linhas];
    int numeros[qtd_linhas];
    
    for(int i=0; i<=qtd_linhas; i++){
        letras[i] = *arq1;
        numeros[i] = *arq2;
    }
    
    for(int j=0; j<= qtd_linhas; j++){
        printf("%d", numeros[j]);
        printf("\n");
    }
    for(int j=0; j<= qtd_linhas; j++){
        printf("%c", letras[j]);
        printf("\n");
    }
        
    int *p = vetor;
    int tamanho=11;
     */


    /*TESTE COM ARRAY
    int numeros[]={2,5,35,20,6,1,10,3,0,7};
    int qtd_linhas = 10;  
    printf("\nNumeros embaralhados:\n");
    for(int i=0;i<qtd_linhas;i++)printf("%d ",numeros[i]);
    */