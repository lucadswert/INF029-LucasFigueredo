#include <stdio.h>

#define quantMaxClientes 3

#define TAM_CPF 16
#define TAM_NAC 12
#define TAM_NOME 30
#define TAM_MAT 13

struct Cad_Clientes{
    char cpf[TAM_CPF],
         nascimento[TAM_NAC],
         nome[TAM_NOME],
         sexo;
}clientes[quantMaxClientes];
typedef struct Cad_Clientes Clientes;

Clientes scanDados( );
void printDados(Clientes dadosClientes);

int clientesCadastrados = 0;


int main( ){
  Clientes dadosCadastrados;

  dadosCadastrados = scanDados();
  printf("\n");
   for (int posicao = 0; posicao < quantMaxClientes; posicao++){
     printf("==================================================\n");
	   printf("Nome: %s\n", clientes[posicao].nome);
	   printf("Nascimento: %s\n", clientes[posicao].nascimento);
     printf("CPF: %s\n", clientes[posicao].cpf);
     printf("Sexo: %c \n", clientes[posicao].sexo);
     printf("==================================================\n");
     }
}

Clientes scanDados(){
  Clientes dados;
  int posicao = clientesCadastrados - 1;
  char TesteSaida[4];

   for (int posicao = 0; posicao < quantMaxClientes; posicao++){
   printf("\nDigite o nome do cliente:\n");
   fgets(clientes[posicao].nome, TAM_NOME, stdin);

   printf("Digite a data de nascimento:\n");
   fgets(clientes[posicao].nascimento, TAM_NAC, stdin);

   printf("Digite o CPF:\n");
   fgets(clientes[posicao].cpf, TAM_CPF, stdin);

   printf("Digite o sexo:\n");
   fgets( TesteSaida, 4, stdin);
   clientes[posicao].sexo = TesteSaida[0];
  }
  return dados;
}
