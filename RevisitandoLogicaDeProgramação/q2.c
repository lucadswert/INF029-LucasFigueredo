#include <stdio.h>

int main() {
    int valor1, valor2, soma;
    printf ("Insira a primeira idade:");
    scanf("%d", &valor1);
    printf("Insira a segunda idade:");
    scanf("%d", &valor2);

  soma = valor1 + valor2;

  printf("\nA soma das idades eh: %d", soma);
  return 0;
  }