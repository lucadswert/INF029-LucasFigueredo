#include <stdio.h>
#include <string.h>
#define TAM 2

typedef struct dados_pessoas{
  char nome[31];
  int idade;
  char sexo;
  char cpf[16];
} Pessoa;


int main(){
  
  Pessoa pessoas[TAM];

  for (int i = 0; i < TAM; i ++){
    printf("Digite o nome: ");
    
    fgets(pessoas[i].nome, 31, stdin); 
    size_t ln = strlen(pessoas[i].nome) - 1;
    if (pessoas[i].nome[ln] == '\n')
      pessoas[i].nome[ln] = '\0';

    printf("Digite o sexo: ");
    scanf("%c", &pessoas[i].sexo);

    printf("Digite a idade: ");
    scanf("%d", &pessoas[i].idade);

    getchar();

    printf("Digite o CPF: ");
    fgets(pessoas[i].cpf, 16, stdin); 
    ln = strlen(pessoas[i].cpf) - 1; 
    if (pessoas[i].cpf[ln] == '\n')
      pessoas[i].cpf[ln] = '\0'; 
  }  
  
  printf("\n### Pessoas Cadastrasdas ####\n");
  int i;
  for (i = 0; i < TAM; i++){
    printf("-----\n");
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Sexo: %c\n", pessoas[i].sexo);
    printf("Idade: %d\n", pessoas[i].idade);
    printf("CPF: %s\n", pessoas[i].cpf);
  }
}