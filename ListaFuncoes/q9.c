#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define bool _Bool
#define true 1
#define false 0

#define quantMaxClientes 3

#define TAM_CPF 16
#define TAM_NAC 12
#define TAM_NOME 20
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

bool validaNome (char*);
bool validaNascimento (char*);
bool validaCPF (char*);
bool validaSexo (char);
bool validaNumero (char num);
bool validaLetra (char letra);

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
   printf("\n|| CADASTRO CLIENTES  ||\n");
   printf("\nDigite o nome do cliente:\n- ");
   fgets(clientes[posicao].nome, TAM_NOME, stdin);
   validaNome (clientes[posicao].nome);

   printf("Digite a data de nascimento:\n(Ex: 00/00/0000)\n- ");
   fgets(clientes[posicao].nascimento, TAM_NAC, stdin);
   validaNascimento (clientes[posicao].nascimento);

   printf("Digite o CPF:\n(Ex: 000.000.000-00)\n- ");
   fgets(clientes[posicao].cpf, TAM_CPF, stdin);
   validaCPF (clientes[posicao].cpf);

   printf("Digite o sexo:\n(Op: M | F | O)\n- ");
   fgets( TesteSaida, 4, stdin);
   clientes[posicao].sexo = TesteSaida[0];
   validaSexo (clientes[posicao].sexo);
  }
  return dados;
}

void printDados(Clientes dadosClientes){
  for (int posicao = 0; posicao < quantMaxClientes; posicao++){
      printf("==================================================\n");
	    printf("Nome: %s", clientes[posicao].nome);
	    printf("Nascimento: %s", clientes[posicao].nascimento);
	    printf("CPF: %s", clientes[posicao].cpf);
        printf("Sexo: %c", clientes[posicao].sexo);
        printf("==================================================\n");
    }
  }

bool validaNome (char* nome){
  if (strlen(nome) > 20){
    puts ("Quantidade de caracteres inválida");
    return false;
  }
  for( int i = 0; i < 2; i++){
    if(!validaLetra(nome[i])){
      puts( "Nome invalido" );
            return false;}}
    return true;
}

bool validaNascimento (char* data){
  if (strlen(data) > 12){
    puts ("Data Inválida");
    return false;
  }

    for( int i = 0; i < 2; i++){
    if(!validaNumero(data[i])){
      puts( "Data invalida" );
            return false;}}

  for (int i = 3; i < 5; i++){
    if (!validaNumero(data[i])){
      puts( "Data invalida" );
            return false;}}

  for (int i = 6; i < 10; i++){
    if (!validaNumero(data[i])){
      puts( "Data invalida" );
            return false;}}

   for(int i = 2; i < 3 ; i++){
        if ( !(data[i] == '/') ){
            puts( "Data invalida" );
            return false;}}
    for(int i = 5; i < 6 ; i++){
        if ( !(data[i] == '/') ){
            puts( "Data invalida" );
            return false;}}

    return true;
}

bool validaCPF (char* cpf){
    for(int i = 0; cpf[i] !='\0'; i++){
        if(cpf[3] != '.' && cpf[7] != '.' && cpf[11] != '-'){
            puts("CPF Invalido");
            return false;
        }
    }

   for(int num = 0; cpf[num] != '\0'; num++){
        if( cpf[num] < '0' && cpf[num] > '9'){
            puts( "Caractere inserido inválido");
            return false;}}
  }

bool validaSexo (char sexo){
  if (!(sexo == 'm') && !(sexo == 'M') && !(sexo == 'F') &&
      !(sexo == 'f') && !(sexo == 'o') && !(sexo == 'O') ){
      puts( " > Opção inválida <" );
      return false;
    }else{
      return true;}
}

bool validaNumero (char num){
  char numerosValidos[] = "0123456789";
  for(int i = 0; numerosValidos[i] != '\0'; i++){
      if( num == numerosValidos[i] ){
          return true;}}
    return false;
}

bool validaLetra (char letra){
  char letrasValidas[] = "abcdefghijklmopqrstuvxyzABCDEFGHYJKLMNOPQRTSUVXYZ";
  char caracteresEspeciais[] = "àèìòùáéíóúýâêîôûãñõçÀÈÌÒÙÁÉÍÓÚÝÂÊÎÔÛÃÑÕÇ";

  for(int i = 0; letrasValidas[i] != '\0'; i++){
      if( letra == letrasValidas[i] ){
          return true;}}

  for(int i = 0; caracteresEspeciais[i] != '\0'; i++){
      if( letra == caracteresEspeciais[i] ){
          return true;}}

    return false;
}
