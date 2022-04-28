#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define NASC 12

bool validaData( char* );
bool validaCaracData (char*);
int Dia, Mes, Ano;
char data[NASC];
int datavalida;

int main( ){
  printf("===================================\n"
         "||      DATA DE NASCIMENTO       ||\n"
         "===================================\n");
  printf("- Digite a data de nascimento:\n-> ");
  fgets(data, NASC, stdin);
  validaData(data);

  if (datavalida == 1){
    return 1;
  }
  else{
    return 0;
  }
}

bool validaData(char *data){
  char sDia[3],
       sMes[3],
       sAno[5];
  int i;

  validaCaracData(data);

  for( i = 0; data[i] != '/'; i++){
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2){
    sDia[i] = '\0';
  }
  else{
    puts ("Data invalida");
    return 0;
  }
  int j = i + 1;
  i = 0;

//Processo para quebrar o mês//
  for( ; data[j] != '/'; j++){
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2){
    sMes[i] = '\0';
  }
  else{
    puts ("Data invalida");
    return 0;
  }

  j = j + 1;
  i = 0;

//Processo para quebrar o ano//
  for( ; data[j] != '\n'; j++){
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4){
    sAno[i] = '\0';
  }
  else{
    puts ("Data invalida");
    return 0;
    }

    Dia = atoi(sDia);
    Mes = atoi(sMes);
    Ano = atoi(sAno);

    if (Mes < 0 || Mes > 12){
        puts("Data invalida");
            puts("\n");
            return 0;
    }
    if (Dia < 0 || Dia > 31){
        puts("Data invalida");
            puts("\n");
            return 0;
    }

    if(  Dia > 0 && Dia <= 31 && Mes > 0 && Mes <= 12){
        if( ( Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11 ) && Dia > 30  ){
            puts("Data invalida");
            puts("\n");
            return 0;}}
            if(Ano%4==0 && (Ano%100!=0 || Ano%400==0)){
                if ((Mes == 2) && Dia > 29){
                    puts("Data invalida");
                    puts("\n");
                    return 0;}}
                    else{
                        if (Mes == 2 && Dia > 28){
                        puts("Data invalida");
                        puts("\n");
                        return 0;}}
    datavalida = 1;
    return datavalida;
}

bool validaCaracData (char* data){
for (int c = 0; data[c] != '\n'; c++)
   if( data[c] < '/' || data[c] > '9'){
        puts("Data invalida");
        puts("\n");
    	return 0;}
    return 1;
}
