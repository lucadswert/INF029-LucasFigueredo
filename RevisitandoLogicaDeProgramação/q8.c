#include <stdio.h>

int main()
{
int fat, valor;
printf("Insira o numero deseja calcular o fatorial: ");
scanf("%d", &valor);

for(fat = 1; valor > 1; valor = valor - 1)
fat = fat * valor;

printf("\nO resultado do fatorial de %d, eh %d", valor, fat);
return 0;
}