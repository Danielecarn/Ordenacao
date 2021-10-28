#include <stdio.h>
#include <stdlib.h>

void troca(int *v, int *prox){ 
    int aux = *v; 
    *v = *prox; 
    *prox = aux; 
} 
void bubble_sort(int *vetor, int tamanho){ 
    if (tamanho < 1){
        return; 
    }
    for (int i=0; i<tamanho-1; i++) 
        if (vetor[i] > vetor[i+1]) 
            troca(&vetor[i], &vetor[i+1]);  
    bubble_sort(vetor, tamanho-1); 
} 

int main(){ 
   
    FILE *file, *copiar;
    file = fopen("teste.txt","r");

    int i;
    char c;
    int qtd_linhas=0;
    FILE *arq1,*arq2;

    //Preenchendo arquivos de letras e números
    arq1 = fopen("letras.txt", "w+");
    arq2 = fopen("numeros.txt","w+");
    while(!feof(file)){
        fscanf(file,"%c\t%i\n", &c,&i);
    
        fprintf(arq1,"%c\n", c);
        fprintf(arq2,"%i\n", i);
        
        qtd_linhas++;
    } 
    printf("Linhas = %d\n", qtd_linhas);
    fclose(arq1);
    fclose(arq2);
    //Preenchendo vetor de números
    int numeros[qtd_linhas]; 
    int j;
    FILE *ler = fopen("numeros.txt","r");

    for(int a=0; a<=qtd_linhas; a++){
        fscanf(ler, "%i", &j);
        numeros[a] = j;
    }

    printf("Numeros Embaralhados:\n");
    for(i=0;i<qtd_linhas;i++)printf("%d ",numeros[i]); 
   
    copiar = fopen("ordemcrescente.txt", "w+");
    bubble_sort(numeros, qtd_linhas);
    printf("\nNumeros na ordem crescente:\n");
    for(int i=0;i<qtd_linhas;i++)printf("%d ",numeros[i]);
    for(int i=0;i<qtd_linhas;i++){
        fprintf(copiar,"%d\n",numeros[i]);
    }

    //Preenchendo vetor de letras

    fclose(file);

    fclose(ler); 
    fclose(copiar);
    
    return 0;
}