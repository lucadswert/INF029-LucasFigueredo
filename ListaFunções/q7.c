#include <stdio.h>
#define TAM_PALAVRA 30

typedef struct
{
    char palavra[TAM_PALAVRA],
         palavra2[TAM_PALAVRA],
         palavra3[TAM_PALAVRA];    
} Palavras;

Palavras scanPalavras();
void printPalavras(Palavras suaPalavra);

int main(){
	Palavras palavraInserida;

	palavraInserida = scanPalavras();
  printf("\n");
	printPalavras(palavraInserida);

}

Palavras scanPalavras(){
	Palavras texto;
	printf("Digite a 1° palavra\n");
  fgets((texto.palavra), TAM_PALAVRA, stdin);

	printf("Digite a 2° palavra\n");
	fgets((texto.palavra2), TAM_PALAVRA, stdin);

	printf("Digite a 3° palavra\n");
	fgets((texto.palavra3), TAM_PALAVRA, stdin);
  

	return texto;
}

void printPalavras(Palavras suaPalavra){
	printf("Palavra 1: %s\n", suaPalavra.palavra);
	printf("Palavra 2: %s\n", suaPalavra.palavra2);
	printf("Palavra 3: %s\n", suaPalavra.palavra3);
}