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
   
    FILE *file;
    file = fopen("teste.txt","r");

    int i;
    char c;
    int qtd_linhas=0;
    FILE *arq1,*arq2;

    //Preenchendo arquivos de letras e números
    while(!feof(file)){
        fscanf(file,"%c\t%i\n", &c,&i);
        
        arq1 = fopen("letras.txt", "a");
        fprintf(arq1,"%c\n", c);

        arq2 = fopen("numeros.txt","a");
        fprintf(arq2,"%i\n", i);
        
        qtd_linhas++;
    } 
    printf("Linhas = %d\n", qtd_linhas);
    
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
   
    /*
    int numeros[]={2,5,35,20,6,1,10,3,0,7};
    int qtd_linhas = 10;  
    printf("\nNumeros embaralhados:\n");
    for(int i=0;i<qtd_linhas;i++)printf("%d ",numeros[i]);
    */

    bubble_sort(numeros, qtd_linhas);
    printf("\nNumeros na ordem crescente:\n");
    for(int i=0;i<qtd_linhas;i++)printf("%d ",numeros[i]);
  

    //Preenchendo vetor de letras

    /**/

    fclose(file);
    fclose(arq1);
    fclose(arq2);
    fclose(ler); 

   
    
    return 0;
}