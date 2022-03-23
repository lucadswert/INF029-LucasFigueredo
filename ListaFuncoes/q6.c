#include <stdio.h>
void retornaLET(char vet[]);

int main()
{
	char letraVetor[3];
    letraVetor[0] = 'a';
    letraVetor[1] = 'b';
    letraVetor[2] = 'c';
    
    //Chamar função para reatribuir as letras
    retornaLET( letraVetor);
    
    
    //Printar letras
    printf("As letras foram:\n", letraVetor[0]);
    printf("%c\n", letraVetor[0]);
    printf("%c\n", letraVetor[1]);
    printf("%c\n", letraVetor[2]);
}

void retornaLET(char retorno[])
{		
    retorno[0] = 'L';
    retorno[1] = 'U';
    retorno[2] = 'C';
}