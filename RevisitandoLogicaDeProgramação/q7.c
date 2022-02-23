#include <stdio.h>

int main() {
    int valor, i, resultado = 0;
  
    printf("Digite um numero:");
     scanf("%d", &valor);
  
    for (i = 2; i <= valor / 2; i++) {
    if (valor % i == 0) {
       resultado++;
       break;
    }
 }
 
 if (resultado == 0)
    printf("%d eh um numero primo\n", valor);
 else
    printf("%d nao eh um numero primo\n", valor);
 
 return 0;
}
