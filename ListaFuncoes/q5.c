#include <stdio.h>

typedef struct
{
    int numero1;
    int numero2;
    int numero3;
    int numero4;
} Numeros;

Numeros scanNum();
void printNum(Numeros seuNum);

int main(){
	Numeros numInserido;

	numInserido = scanNum();

	printNum(numInserido);

}

Numeros scanNum(){
	Numeros numeros;
	printf("Digite o 1° valor\n");
	scanf("%d", &numeros.numero1);

	printf("Digite o 2° valor\n");
	scanf("%d", &numeros.numero2);

	printf("Digite o 3° valor\n");
	scanf("%d", &numeros.numero3);

	printf("Digite o 4° valor\n");
	scanf("%d", &numeros.numero4);

	return numeros;
}

void printNum(Numeros seuNum){
	printf("Valor 1: %d\n", seuNum.numero1);
	printf("Valor 2: %d\n", seuNum.numero2);
	printf("Valor 3: %d\n", seuNum.numero3);
	printf("Valor 4: %d\n", seuNum.numero4);
}