#include <stdio.h>
#include "bubble_sort.h"

int main(){ 
    
    int qtd_linhas=0; char aux_caractere; int aux_numero;    
    int opcao_usuario = 1;

    while( opcao_usuario != 0){
        printf("============== Ordena Tudo ==============\n\n");
        printf("Digite o número da opção desejada: \n\n1 - Separar letras e números.\n2 - Ordenar arquivo.\n0 - Exit.\n\n");
        scanf("%i", &opcao_usuario);

        if(opcao_usuario < 0 || opcao_usuario > 2 ){
            printf("Opção inexistente! Por favor escolha outra opção \n\n");
        }
        if(opcao_usuario == 1){
            FILE *arquivo_geral, *arq_letras, *arq_numeros;

            arquivo_geral = fopen("teste.txt","r");
            arq_letras = fopen("letras.txt", "w+");
            arq_numeros = fopen("numeros.txt","w+");
                    
            //Preenchendo arquivos de letras e números
            while(!feof(arquivo_geral)){
                fscanf(arquivo_geral,"%c\t%i\n", &aux_caractere,&aux_numero);
            
                fprintf(arq_letras,"%c\n", aux_caractere);
                fprintf(arq_numeros,"%i\n", aux_numero);
            
                qtd_linhas++;
            }
            printf("\nLetras e Números separados!\n\n");   

            fclose(arq_letras);
            fclose(arq_numeros);
            fclose(arquivo_geral);
        }
        if(opcao_usuario == 2){  
            int vetor_numeros[qtd_linhas]; 
            char caractere[qtd_linhas];
            caractere[qtd_linhas-1] ='\0';

            //Preenchendo vetor de números 
            FILE  *acessa_numeros;

            acessa_numeros = fopen("numeros.txt","r+");

            for(int posicao=0; posicao<=qtd_linhas; posicao++){
                fscanf(acessa_numeros, "%i", &aux_numero);
                vetor_numeros[posicao] = aux_numero;
            }
            
            acessa_numeros = fopen("numeros.txt", "w+");
            bubble_sort(vetor_numeros, qtd_linhas);
            
            for(int posicao=0; posicao<qtd_linhas; posicao++){
                fprintf(acessa_numeros,"%d\n",vetor_numeros[posicao]);
            }

            fclose(acessa_numeros);

            //Preenchendo vetor de letras
            FILE *acessa_letras = fopen("letras.txt","r");
            
            int vetor_letras[qtd_linhas];
            
            for(int posicao=0; posicao<qtd_linhas; posicao++){
                fgets(caractere,qtd_linhas,acessa_letras);                
                vetor_letras[posicao]= (int)caractere[0];
            }

            acessa_letras = fopen("letras.txt", "w+");
            
            bubble_sort(vetor_letras, qtd_linhas);

            for(int posicao=0; posicao<qtd_linhas; posicao++){
                fprintf(acessa_letras,"%c\n",vetor_letras[posicao]);
            }
            printf("\nArquivos ordenados com sucesso!\n\n");
            fclose(acessa_letras);
        }
    }
    return 0;
}
