#include <stdio.h>
#include <stdlib.h>
int N, num, aux;
int inverteNumero(int);

int main()
{
  printf("===================================\n"
         "||        INVERTER NUMERO        ||\n"
         "===================================\n");
  printf("- Digite um numero:\n-> ");
  scanf("%i", &N);
  inverteNumero(N);
  printf("%d", num);
  return num;
}

int inverteNumero(int inverter){

    for (;inverter != 0;){
        aux = inverter % 10;
        num = num*10 + aux;
        inverter = inverter/10;
    }
    return num;
 }
