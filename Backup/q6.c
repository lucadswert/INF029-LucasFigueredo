#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N, numBusca, invertido, busca, cont = 0, posicao, sizeBusca;
int quebraNumero(int, int);
int i = 0;
int digNum[11], digBusca[11];
int qtdOcorrencias;

int main()
{
  printf("===================================\n"
         "||        PROCURAR NUMERO        ||\n"
         "===================================\n");
  printf("- Digite um numero:\n-> ");
  scanf("%i", &N);
  printf("- Digite um numero:\n-> ");
  scanf("%i", &numBusca);
  quebraNumero(N, numBusca);
  printf("\nO numero %d, ocorre %d vezes\n", numBusca, qtdOcorrencias);
  return qtdOcorrencias;
}

int quebraNumero(int num, int numB){
    int contDig = 0;
    for (;num != 0;){
        digNum[i] = num % 10;
        invertido = invertido*10 + digNum[i];
        num = num/10;
        i++;
    }

    for (int l = 0 ;numB != 0; l++){
        digBusca[l] = numB % 10;
        busca = busca*10 + digBusca[l];
        numB = numB/10;
        contDig++;
        }

    if ((contDig < 2)){
    for (int j = 0; digNum[j] != 0; j++){
        for (int k = 0; digBusca[k] != 0; k++){
            if(digNum[j] == digBusca[k]){
                qtdOcorrencias++;
                }
            }
        }
    }
    else{
        for (int s = 0; digNum[s]!= 0;){
            int d = 0;
            int cont = 0;
            while ((digNum[s] == digBusca[d]))
            {
                cont++;
                s++;
                d++;
            }
            if (cont == contDig){
                qtdOcorrencias++;
                cont = 0;
            }
            else{
               s++;
            }
          }
        }
    return qtdOcorrencias;
 }
