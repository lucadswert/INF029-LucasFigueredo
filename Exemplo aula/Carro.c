
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAR 100
#define TAM_MOD 100

typedef struct
{
    int ano;
    char marca[TAM_MAR], 
         modelo[TAM_MOD];
} InfCar;

void solicitaDados();
void imprimeDados();

int main()
{   
    InfCar dadosCar;
    solicitaDados(&dadosCar);
    imprimeDados(&dadosCar);
    return 0;
}

void solicitaDados(InfCar* dadosCar){
    int ano;
    int i= 0;
    for (int i = 0; i < 3; i++){     
      printf("\nInsira a marca do carro:\n");
      fgets(dadosCar[i].marca, TAM_MAR, stdin);
      printf("Insira o modelo do carro:\n");
      fgets(dadosCar[i].modelo, TAM_MOD, stdin);
      printf("Insira o ano do carro:\n");
      scanf("%d", &dadosCar[i].ano);
      getchar();
      }
}

void imprimeDados(InfCar* dadosCar){
    for (int i = 0; i < 3; i++){
      printf("\nMarca: %s", dadosCar[i].marca);
      printf("Modelo: %s", dadosCar[i].modelo);
      printf("Marca: %d\n", dadosCar[i].ano);
    }
}