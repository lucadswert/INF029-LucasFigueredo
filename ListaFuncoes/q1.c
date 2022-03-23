#include <stdio.h>

int soma(int a, int b);

int main()
{
    int v1, v2, resultado;
    v1 = 45; 
    v2 = 30;
    resultado = soma(v1, v2);
  
    printf("A soma dos valores %d e %d eh: %d", v1, v2, resultado);
    return 1;
  }
  int soma(int a, int b)
{
    int res = a + b;
    return res;
}