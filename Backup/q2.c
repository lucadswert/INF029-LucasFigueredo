#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define NASC 12

int validaData( char*, char* );
int validaCaracData (char*);
int DiaI, MesI, AnoI, DiaF, MesF, AnoF;
char data[NASC], dataFinal[NASC];
int datavalida;

int main( ){
  printf("===================================\n"
         "||      DATA DE NASCIMENTO       ||\n"
         "===================================\n");
  printf("- Digite a data de nascimento:\n-> ");
  fgets(data, NASC, stdin);
  printf("- Digite a data atual:\n-> ");
  fgets(dataFinal, NASC, stdin);
  validaData(data, dataFinal);

if (datavalida == 1){
    return 1;
  }
  else{
    return 0;
  }
}

int validaData(char *dataI, char *dataF){
  int DifDia, DifMes, DifAno;
  char sDia[3],
       sMes[3],
       sAno[5],
       sDiaF[3],
       sMesF[3],
       sAnoF[5];
  int i;

  validaCaracData(dataI);
  validaCaracData(dataF);

  //Validar Data Inicial
  for( i = 0; dataI[i] != '/'; i++){
    sDia[i] = dataI[i];
  }
  if (i == 1 || i == 2){
    sDia[i] = '\0';
  }
  else{
    puts ("ERRO NO DIA INICIAL!");
    return 0;
  }
  int j = i + 1;
  i = 0;

//Processo para quebrar o mês//
  for( ; dataI[j] != '/'; j++){
    sMes[i] = dataI[j];
    i++;
  }

  if (i == 1 || i == 2){
    sMes[i] = '\0';
  }
  else{
    puts ("ERRO NO MES INICIAL!");
    return 0;
  }

  j = j + 1;
  i = 0;

//Processo para quebrar o ano//
  for( ; dataI[j] != '\n'; j++){
    sAno[i] = dataI[j];
    i++;
  }

  if (i == 2 || i == 4){
    sAno[i] = '\0';
  }
  else{
    puts ("ERRO NO ANO INICIAL!");
    return 0;
    }

    DiaI = atoi(sDia);
    MesI = atoi(sMes);
    AnoI = atoi(sAno);

    if (MesI < 0 || MesI > 12){
        puts("Data Inicial Invalida");
            puts("\n");
            return 0;
    }
    if (DiaI < 0 || DiaI > 31){
        puts("Data Inicial Invalida");
            puts("\n");
            return 0;
    }

    if(  DiaI > 0 && DiaI <= 31 && MesI > 0 && MesI <= 12){
        if( ( MesI == 4 || MesI == 6 || MesI == 9 || MesI == 11 ) && DiaI > 30  ){
            puts("Data Inicial Invalida");
            puts("\n");
            return 0;}}
            if(AnoI%4==0 && (AnoI%100!=0 || AnoI%400==0)){
                if ((MesI == 2) && DiaI > 29){
                    puts("Data Inicial Invalida");
                    puts("\n");
                    return 0;}}
                    else{
                        if (MesI == 2 && DiaI > 28){
                        puts("Data Inicial Invalida");
                        puts("\n");
                        return 0;}}

  //Validar Data Final
  int c;
  for( c = 0; dataF[c] != '/'; c++){
    sDiaF[c] = dataF[c];
  }
  if (c == 1 || c == 2){
    sDiaF[c] = '\0';
  }
  else{
    puts ("ERRO NO DIA ATUAL!");
    return 0;
  }
  int k = c + 1;
  c = 0;

//Processo para quebrar o mês//
  for( ; dataF[k] != '/'; k++){
    sMesF[c] = dataF[k];
    c++;
  }

  if (c == 1 || c == 2){
    sMesF[c] = '\0';
  }
  else{
    puts ("ERRO NO MES ATUAL!");
    return 0;
  }

  k = k + 1;
  c = 0;

//Processo para quebrar o ano//
  for( ; dataF[k] != '\n'; k++){
    sAnoF[c] = dataF[k];
    c++;
  }

  if (c == 2 || c == 4){
    sAnoF[c] = '\0';
  }
  else{
    puts ("ERRO NO ANO ATUAL!");
    return 0;
    }

    DiaF = atoi(sDiaF);
    MesF = atoi(sMesF);
    AnoF = atoi(sAnoF);

  if (MesF < 0 || MesF > 12){
        puts("Data Atual Invalida");
            puts("\n");
            return 0;
    }
    if (DiaF < 0 || DiaF > 31){
        puts("Data Atual Invalida");
            puts("\n");
            return 0;
    }

    if(  DiaF > 0 && DiaF <= 31 && MesF > 0 && MesF <= 12){
        if( ( MesF == 4 || MesF == 6 || MesF == 9 || MesF == 11 ) && DiaF > 30  ){
            puts("Data Atual Invalida");
            puts("\n");
            return 0;}}
            if(AnoF%4==0 && (AnoF%100!=0 || AnoF%400==0)){
                if ((MesF == 2) && DiaF > 29){
                    puts("Data Atual Invalida");
                    puts("\n");
                    return 0;}}
                    else{
                        if (MesF == 2 && DiaF > 28){
                        puts("Data Atual Invalida");
                        puts("\n");
                        return 0;}}

    if(DiaF < DiaI)
    {
        if (MesF == 3)
        {
            if ((AnoF % 4 == 0 && AnoF % 100 != 0) || (AnoF % 400 == 0))
            {
                DiaF += 29;
            }

            else
            {
                DiaF += 28;
            }
        }
        else if (MesF == 5 || MesF == 7 || MesF == 10 || MesF == 12)
        {
           DiaF += 30;
        }
        else
        {
           DiaF += 31;
        }

        MesF = MesF - 1;
    }
    if (MesF < MesI)
    {
        MesF += 12;
        AnoF -= 1;
    }

    DifDia = DiaF - DiaI;
    DifMes = MesF - MesI;
    DifAno = AnoF - AnoI;
    printf("\nAte a data atual sao: %d anos %02d meses e %02d dias.\n", DifAno, DifMes, DifDia);

    datavalida = 1;
    return datavalida;
}

int validaCaracData (char* data){
for (int d = 0; data[d] != '\n'; d++)
   if( data[d] < '/' || data[d] > '9'){
        puts("Caractere invalido");
        puts("\n");
    	return 0;}
    return 1;
}
