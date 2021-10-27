#include <stdio.h>

int main(){
    FILE *file;
    file = fopen("teste.txt","r");

    int i;
    char c;
    FILE *arq1,*arq2;
    
    while(!feof(file)){
        fscanf(file,"%c\t%i\n", &c,&i);
        
        arq1 = fopen("letras.txt", "a");
        fprintf(arq1,"%c\n", c);

        arq2 = fopen("numeros.txt","a");
        fprintf(arq2,"%i\n", i);
    } 
    
    fclose(file);
    fclose(arq1);
    fclose(arq2);
    return 0;
}