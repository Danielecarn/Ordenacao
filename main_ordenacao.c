#include <stdio.h>
#include <stdlib.h>
//#include "bubble_sort.h"
int main(){
    FILE *file;
    file = fopen("teste.txt","r");

    int i;
    char c;
    int qtd_linhas=0;
    FILE *arq1,*arq2;
    
    while(!feof(file)){
        fscanf(file,"%c\t%i\n", &c,&i);
        
        arq1 = fopen("letras.txt", "a");
        fprintf(arq1,"%c\n", c);

        arq2 = fopen("numeros.txt","a");
        fprintf(arq2,"%i\n", i);
        
        qtd_linhas++;
    } 
    printf("Linhas = %d\n", qtd_linhas);
    
    int *numeros;
    int j;
    numeros=(int*)malloc(qtd_linhas*sizeof(int));
    FILE *ler = fopen("numeros.txt","r");

    for(int a=0; a<=qtd_linhas; a++){
        fscanf(ler, "%i", &j);
        numeros[a] = j;
    }

    printf("%d ",numeros[i]);
    for(i=0;i<qtd_linhas;i++)printf("%d ",numeros[i]);


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
        int vetor[12]={2,5,35,6,3,2,1,36,6,0,4,7};
    int *p = vetor;
    int tamanho=11;
    */

    

    fclose(file);
    fclose(arq1);
    fclose(arq2);
    fclose(ler);
    return 0;
}