#include <stdio.h>

int main() {
    int valor1;
    printf ("Insira a idade:");
    scanf("%d", &valor1);

        if (valor1 < 18) {
          printf ("Vc tem %d anos e eh menor de idade", valor1);
        }
  else {
    printf ("Vc tem %d anos e eh maior de idade", valor1);
  }
  return 0;
  }