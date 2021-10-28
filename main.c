#include <stdio.h>
#include <stdlib.h>

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

int main(){ 
    
    int qtd_linhas=0; char auxCaractere; int auxNumero;
    
    FILE *arquivoGeral, *arquivoLetras, *arquivoNumeros;

    arquivoGeral = fopen("teste.txt","r");
    arquivoLetras = fopen("letras.txt", "w+");
    arquivoNumeros = fopen("numeros.txt","w+");
    
    //Preenchendo arquivos de letras e números
    while(!feof(arquivoGeral)){
        fscanf(arquivoGeral,"%c\t%i\n", &auxCaractere,&auxNumero);
    
        fprintf(arquivoLetras,"%c\n", auxCaractere);
        fprintf(arquivoNumeros,"%i\n", auxNumero);
        
        qtd_linhas++;
    }
    printf("Linhas = %d\n", qtd_linhas);

    fclose(arquivoLetras);
    fclose(arquivoNumeros);
    fclose(arquivoGeral);

    int vetorNumeros[qtd_linhas]; 
    char caractere[qtd_linhas];
    caractere[qtd_linhas-1] ='\0';

    //Preenchendo vetor de números
    FILE *lerNumeros, *copiar;

    lerNumeros = fopen("numeros.txt","r");

    for(int posicao=0; posicao<=qtd_linhas; posicao++){
        fscanf(lerNumeros, "%i", &auxNumero);
        vetorNumeros[posicao] = auxNumero;
    }
    
    printf("Numeros Embaralhados:\n");
    for(int posicao=0; posicao<qtd_linhas; posicao++){
        printf("%d ",vetorNumeros[posicao]); 
    }
 
    copiar = fopen("numeros.txt", "w+");
    bubble_sort(vetorNumeros, qtd_linhas);
    
    printf("\nNumeros na ordem crescente:\n");
    for(int posicao=0; posicao<qtd_linhas; posicao++){
        printf("%d ",vetorNumeros[posicao]);
    }
    
    for(int posicao=0; posicao<qtd_linhas; posicao++){
        fprintf(copiar,"%d\n",vetorNumeros[posicao]);
    }

    fclose(lerNumeros); 
    fclose(copiar);

    //Preenchendo vetor de letras
    FILE *l = fopen("letras.txt","r");
    
    int letras[qtd_linhas];
    
    for(int posicao=0; posicao<qtd_linhas; posicao++){
        fgets(caractere,qtd_linhas,l);
        //printf("letras: %s",caractere);
        
        letras[posicao]= (int)caractere[0];
        //printf("ascii: %d\n\n",letras[a]);
    }

    printf("Letras:\n");
    for(int posicao=0; posicao<qtd_linhas; posicao++){
        printf("%i ",letras[posicao]); 
    }

    FILE *copiaL = fopen("letras.txt", "w+");
    
    bubble_sort(letras, qtd_linhas);

    printf("\nLetras na ordem crescente:\n");
    for(int posicao=0; posicao<qtd_linhas; posicao++){
        printf("%c ",letras[posicao]);
    }

    for(int posicao=0; posicao<qtd_linhas; posicao++){
        fprintf(copiaL,"%c\n",letras[posicao]);
    }

    fclose(copiaL);
    fclose(l);
    
    return 0;
}