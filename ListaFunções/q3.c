#include <stdio.h>

int fatorial(int a);

int main()
{
    int v1, resultado;
    printf("Insira o numero deseja calcular o fatorial: ");
    scanf("%d", &v1);
  
    resultado = fatorial(v1);
    if (v1 > 0){
    printf("\nO resultado do fatorial de %d, eh %d", v1, resultado);
}
    return 0;
  }
  int fatorial(int a)
{
    int res;
    
    if (a > 0){
    for(res = 1; a > 1; a = a - 1)
    res = res * a;
}
	else 
	{
	printf("========================================\n"); 
	printf("ERRO, o valor inserido eh invalido\n");
	printf("========================================\n"); 
	}
	return res;
}