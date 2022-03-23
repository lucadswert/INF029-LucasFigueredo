#include <stdio.h>
void retornaNUM(int vet[]);

int main()
{
	int numeroVetor[3];
    numeroVetor[0] = 329;
    numeroVetor[1] = 2536;
    numeroVetor[2] = 5464;
    
    //Chamar função para reatribuir valor aos números
    retornaNUM( numeroVetor);
    
    
    //Printar números
    printf("Os numeros foram:\n", numeroVetor[0]);
    printf("%d\n", numeroVetor[0]);
    printf("%d\n", numeroVetor[1]);
    printf("%d\n", numeroVetor[2]);
}

void retornaNUM(int retorno[])
{		
    retorno[0] = 21;
    retorno[1] = 3;
    retorno[2] = 2003;
}