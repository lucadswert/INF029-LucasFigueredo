#include <stdio.h>

int main() {
    int valor1;
    printf ("Insira a idade:\n");
    scanf("\n%d", &valor1);
    while (valor1 > 0){
        if (valor1 < 18) {
          printf ("Vc tem %d anos e eh menor de idade\n", valor1);
          printf ("Insira a idade:\n");
    	scanf("\n%d", &valor1);
        }
  else {
    printf ("Vc tem %d anos e eh maior de idade\n", valor1);
    printf ("Insira a idade:\n");
    scanf("\n%d", &valor1);
  }
        }
  printf ("Finalizando o programa...");
  return 0;
  }