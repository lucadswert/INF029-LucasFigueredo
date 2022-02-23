#include <stdio.h>

int main() {
    int valor1, valor2, aux;
    printf ("Insira o primeiro valor:");
    scanf("%d", &valor1);
    printf("Insira o segundo valor:");
    scanf("%d", &valor2);
   aux = valor1;
  valor1 = valor2;
  valor2 = aux;

  printf("\nO valor de A foi %d e o valor de B foi %d", valor1, valor2);

  
  return 0;
  }