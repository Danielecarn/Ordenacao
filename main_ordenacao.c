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
    fclose(file);

    //Preenchendo vetor de números
    int numeros[qtd_linhas]; 
    int j;
    FILE *ler = fopen("numeros.txt","r");

    for(int a=0; a<=qtd_linhas; a++){
        fscanf(ler, "%i", &j);
        numeros[a] = j;
    }
    /*
    printf("Numeros Embaralhados:\n");
    for(i=0;i<qtd_linhas;i++)printf("%d ",numeros[i]); 
    */
    copiar = fopen("numeros.txt", "w+");
    bubble_sort(numeros, qtd_linhas);
    /*
    printf("\nNumeros na ordem crescente:\n");
    for(int i=0;i<qtd_linhas;i++)printf("%d ",numeros[i]);
    */
    for(int i=0;i<qtd_linhas;i++){
        fprintf(copiar,"%d\n",numeros[i]);
    }
    fclose(ler); 
    fclose(copiar);

    //Preenchendo vetor de letras
    FILE *l = fopen("letras.txt","r");
    char caractere[qtd_linhas];
    caractere[qtd_linhas-1] ='\0';
    int letras[qtd_linhas];
    
    for(int a=0; a<qtd_linhas; a++){
        fgets(caractere,qtd_linhas,l);
        printf("letras: %s",caractere);
        
        letras[a]= (int)caractere[0];
        printf("ascii: %d\n\n",letras[a]);
    }

    
    printf("Letras:\n");
    for(i=0;i<qtd_linhas;i++)printf("%i ",letras[i]); 
    FILE *copiaL = fopen("letras.txt", "w+");
    bubble_sort(letras, qtd_linhas);
    printf("Letras na ordem crescente:\n");
    for(int i=0;i<qtd_linhas;i++)printf("%c ",letras[i]);
    for(int i=0;i<qtd_linhas;i++){
        //char l[qtd_linhas] = letrasN[i]+'0';
        fprintf(copiaL,"%c\n",letras[i]);
    }

    fclose(copiaL);

    fclose(l);
    
    return 0;
}