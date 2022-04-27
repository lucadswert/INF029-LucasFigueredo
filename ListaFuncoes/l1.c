#include <stdio.h>

int soma(int a, int b);
int subtrai (int a, int b);
int multiplica (int x, int y);

int main()
{
    int v1, v2, resultsoma, resultsub, resultmult;

    printf("Digite o valor 1: \n");
    scanf("%d", &v1);
    printf("Digite o valor 2: \n");
    scanf("%d", &v2);
  
    resultsoma = soma(v1, v2);
    resultsub = subtrai(v1, v2);
    resultmult = multiplica(resultsoma, resultsub);
  
  
    printf("A soma dos valores %d e %d eh: %d\n", v1, v2, resultsoma);
    printf("A subtracao dos valores %d e %d eh: %d\n", v1, v2, resultsub);
    printf("A multiplicação dos valores %d e %d eh: %d\n", resultsoma, resultsub, resultmult);
    return 1;
  }
  int soma(int a, int b)
{
    int res = a + b;
    return res;
}
int subtrai (int a, int b){
  int res = a - b;
  return res;
}

int multiplica (int x, int y){
  int res = x * y;
  return res;
}
