/* código */
//organizar dados dentro de um arquivo

/* --- Bibliotecas Auxiliares ---*/
#include <stdio.h> 

/*--- Protótipos das Funções --- */
void crecente(int *vet);

//--- Função principal---
int main(void)
{
    /*-- vetor com 11 posições ---*/
    int vet[11]; 

    crecente(&vet[0]);

    printf("--- vetor foi organizado com sucesso ---\n\n");

    return 0 ;
}

/*--- Desenvolvimento das Funções Auxiliares ---*/
void crecente(int *vet)
{
    /*--- Variaveis de interação --- */
    int i,j, acumulador;

    /*--- Arquivos --- */
    FILE *letrascci;
    FILE *copiar;

    /*--- Abrindo Arquivos ---*/
    letrascci = fopen("numeros.txt", "r");

    /*--- Lendo e coletando as informações do primeiro arquivo --- */
    for(i = 0; i < 10 ; i++)
    {
        fscanf(letrascci, "%d\n", &vet[i]);
    }

    /*--- Criando o segundo arquivo para ordenar --- */
    copiar = fopen("ordemcrescente.txt", "w+");

    /*--- Ordenando as informações que estavam dentro do arquivo ---*/
    for(i = 0; i<10; i++)
    {
        for(j = i+1 ; j<10; j++)
        {
            if(vet[i]>vet[j])
            {
                acumulador = vet[i];
                vet[i] = vet[j];
                vet[j] = acumulador;
            }
        }
    }

    /*--- Imprimindo dentro do novo arquivo ---*/
    for(j = 0 ; j<10 ; j++)
    {
        fprintf(copiar, "%d\n", vet[j]);
    }

    /*--- Fechando os arquivos ---*/
    fclose(letrascci);
    fclose(copiar);
}