#include <stdio.h>

int sub(int a, int b, int c);

int main()
{
    int v1, v2, v3, resultado;
    v1 = 95; 
    v2 = 33;
    v3 = 12;
    resultado = sub(v1, v2, v3);
  
    printf("A subtracao dos valores %d e %d e %d eh: %d", v1, v2, v3, resultado);
    return 1;
  }
  int sub(int a, int b, int c)
{
    int res = a - b - c;
    return res;
}