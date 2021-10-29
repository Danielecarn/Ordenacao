#include <stdio.h>
#include "bubbleSort.h"

int main(){ 
    
    int qtd_linhas=0; char auxCaractere; int auxNumero;    
    int opcaoUsuario = 1;

    while( opcaoUsuario != 0){
        printf("============== Ordena Tudo ==============\n\n");
        printf("Digite o número da opção desejada: \n\n1 - Separar letras e números.\n2 - Ordenar arquivo.\n0 - Exit.\n\n");
        scanf("%i", &opcaoUsuario);

        if(opcaoUsuario < 0 || opcaoUsuario > 2 ){
            printf("Opção inexistente! Por favor escolha outra opção \n\n");
        }
        if(opcaoUsuario == 1){
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
            printf("\nLetras e Números separados!\n\n");   

            fclose(arquivoLetras);
            fclose(arquivoNumeros);
            fclose(arquivoGeral);
        }
        if(opcaoUsuario == 2){  
            int vetorNumeros[qtd_linhas]; 
            char caractere[qtd_linhas];
            caractere[qtd_linhas-1] ='\0';

            //Preenchendo vetor de números 
            FILE  *acessaNumeros;

            acessaNumeros = fopen("numeros.txt","r+");

            for(int posicao=0; posicao<=qtd_linhas; posicao++){
                fscanf(acessaNumeros, "%i", &auxNumero);
                vetorNumeros[posicao] = auxNumero;
            }
            
            acessaNumeros = fopen("numeros.txt", "w+");
            bubble_sort(vetorNumeros, qtd_linhas);
            
            for(int posicao=0; posicao<qtd_linhas; posicao++){
                fprintf(acessaNumeros,"%d\n",vetorNumeros[posicao]);
            }

            fclose(acessaNumeros);

            //Preenchendo vetor de letras
            FILE *acessaLetras = fopen("letras.txt","r");
            
            int vetorLetras[qtd_linhas];
            
            for(int posicao=0; posicao<qtd_linhas; posicao++){
                fgets(caractere,qtd_linhas,acessaLetras);                
                vetorLetras[posicao]= (int)caractere[0];
            }

            acessaLetras = fopen("letras.txt", "w+");
            
            bubble_sort(vetorLetras, qtd_linhas);

            for(int posicao=0; posicao<qtd_linhas; posicao++){
                fprintf(acessaLetras,"%c\n",vetorLetras[posicao]);
            }
            printf("\nArquivos ordenados com sucesso!\n\n");
            fclose(acessaLetras);
        }
    }
    
    return 0;
}