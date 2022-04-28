#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define NASC 11
#include "LucasFigueredo20212160031.h"
int q1(char data[NASC]){
  int datavalida = 0;
  int Dia, Mes, Ano;
  char sDia[3],
       sMes[3],
       sAno[5];
  int i;
  
  //Validar Caracteres//
  for (int c = 0; data[c] != '\0'; c++)
   if( data[c] < '/' || data[c] > '9'){
     //puts("Erro caractere;");
    	return 0;}

  for( i = 0; data[i] != '/'; i++){
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2){
    sDia[i] = '\0';
  }
  else{
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
    return 0;
  }

  j = j + 1;
  i = 0;

//Processo para quebrar o ano//
  for( ; data[j] != '\0'; j++){
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4){
    sAno[i] = '\0';
  }
  else{
    return 0;
    }

    Dia = atoi(sDia);
    Mes = atoi(sMes);
    Ano = atoi(sAno);

    if (Mes < 0 || Mes > 12){
            return 0;
    }
    if (Dia < 0 || Dia > 31){
            return 0;
    }

    if(  Dia > 0 && Dia <= 31 && Mes > 0 && Mes <= 12){
        if( ( Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11 ) && Dia > 30  ){
            return 0;}}
            if(Ano%4==0 && (Ano%100!=0 || Ano%400==0)){
                if ((Mes == 2) && Dia > 29){
                    return 0;}}
                    else{
                        if (Mes == 2 && Dia > 28){
                        return 0;}}
  datavalida = 1;
  return datavalida;
}
int q2(char dataInicial[NASC], char dataFinal[NASC]){
  int DiaI, MesI, AnoI, DiaF, MesF, AnoF;
  int qtdDias, qtdMeses, qtdAnos;
  char sDia[3],
       sMes[3],
       sAno[5],
       sDiaF[3],
       sMesF[3],
       sAnoF[5];
  int i;
  int retorno = 0;
  for (int c = 0; dataInicial[c] != '\0'; c++)
   if( dataInicial[c] < '/' || dataInicial[c] > '9'){
    	return 0;}
  for (int d = 0; dataFinal[d] != '\0'; d++)
   if( dataFinal[d] < '/' || dataFinal[d] > '9'){
    	return 0;}
  //Validar Data Inicial
  for( i = 0; dataInicial[i] != '/'; i++){
    sDia[i] = dataInicial[i];
  }
  if (i == 1 || i == 2){
    sDia[i] = '\0';
  }
  else{
    return 0;
  }
  int j = i + 1;
  i = 0;

//Processo para quebrar o mês//
  for( ; dataInicial[j] != '/'; j++){
    sMes[i] = dataInicial[j];
    i++;
  }
  if (i == 1 || i == 2){
    sMes[i] = '\0';
  }
  else{
    return 0;
  }
  j = j + 1;
  i = 0;

//Processo para quebrar o ano//
  for( ; dataInicial[j] != '\0'; j++){
    sAno[i] = dataInicial[j];
    i++;
  }

  if (i == 2 || i == 4){
    sAno[i] = '\0';
  }
  else{
    return 0;
    }
    DiaI = atoi(sDia);
    MesI = atoi(sMes);
    AnoI = atoi(sAno);

    if (MesI < 0 || MesI > 12){
            return 0;
    }
    if (DiaI < 0 || DiaI > 31){
            return 0;
    }
    if(DiaI > 0 && DiaI < 32 && MesI > 0 && MesI < 13){
        if( ( MesI == 4 || MesI == 6 || MesI == 9 || MesI == 11 ) && (DiaI > 30)  ){
            return 0;}}
            if(AnoI%4==0 && (AnoI%100!=0 || AnoI%400==0)){
                if ((MesI == 2) && DiaI > 29){
                    return 0;}}
                    else{
                        if ((MesI == 2) && (DiaI > 28)){
                        return 0;}}
  //Validar Data Final
  for( i = 0; dataFinal[i] != '/'; i++){
    sDiaF[i] = dataFinal[i];
  }
  if (i == 1 || i == 2){
    sDiaF[i] = '\0';
  }
  else{
    return 0;
  }
  j = i + 1;
  i = 0;

//Processo para quebrar o mês//
  for( ; dataFinal[j] != '/'; j++){
    sMesF[i] = dataFinal[j];
    i++;
  }
  if (i == 1 || i == 2){
    sMesF[i] = '\0';
  }
  else{
    return 0;
  }
  j = j + 1;
  i = 0;

//Processo para quebrar o ano//
  for( ; dataFinal[j] != '\0'; j++){
    sAnoF[i] = dataFinal[j];
    i++;
  }

  if (i == 2 || i == 4){
    sAnoF[i] = '\0';
  }
  else{
    return 0;
    }
    DiaF = atoi(sDiaF);
    MesF = atoi(sMesF);
    AnoF = atoi(sAnoF);

    if (MesF < 0 || MesF > 12){
            return 0;
    }
    if (DiaF < 0 || DiaF > 31){
            return 0;
    }
    if(DiaF > 0 && DiaF < 32 && MesF > 0 && MesF < 13){
        if( ( MesF == 4 || MesF == 6 || MesF == 9 || MesF == 11 ) && (DiaF > 30)  ){
            return 0;}}
            if(AnoF%4==0 && (AnoF%100!=0 || AnoF%400==0)){
                if ((MesF == 2) && DiaF > 29){
                    return 0;}}
                    else{
                        if ((MesF == 2) && (DiaF > 28)){
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
  if (AnoI > AnoF){
    return 0;
  }
  
    qtdDias = DiaF - DiaI;
    qtdMeses = MesF - MesI;
    qtdAnos = AnoF - AnoI;
    retorno = 1;
    printf("Retorno %d\n", retorno);
    printf("Dias: %d\n", qtdDias);
    printf("Meses: %d\n", qtdMeses);
    printf("Anos: %d\n", qtdAnos);
    return retorno;
}
int q3(char* texto, char c, int isCaseSensitive){
    int qtdOcorrencias;
    char busca = c;
    qtdOcorrencias = 0;
    if (isCaseSensitive != 1){
      if( (c >= 65) && (c <= 90) ){
          busca -= ('A' - 'a');}
      else if( (c >= 97) && (c <= 122) ){
          busca += ('A' - 'a');}
      }   
            for(int i = 0; i < strlen(texto); i++){
                if ((texto[i] == c) || (busca == texto[i] && isCaseSensitive != 1)){
                    qtdOcorrencias++;
                }
            }
     return qtdOcorrencias;
}
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int aux1=0;
    char fraseB[250]={0};
    char buscaB[50]={0};
    int tamPalavra;
    int qtdOcorrencias = 0;
    tamPalavra = strlen(strBusca);
    for(int i = 0; strTexto[i] != '\0' ;i++ ){
        int j = 0;
        int cont = 0;
        int m = i;

        while ((strTexto[m] == strBusca[j]))
        {
            cont++;
            j++;
            m++;
        }
        if(cont == tamPalavra){
            posicoes[aux1] = i+1;
            aux1++;
            posicoes[aux1] = i + tamPalavra;
            aux1++;
            qtdOcorrencias++;
            i++;
        }
}
    return qtdOcorrencias;
}
int q5(int num){
  int aux, inverso;
  inverso = 0;
    for (;num != 0;){
        aux = num % 10;
        inverso = inverso*10 + aux;
        num = num/10;
    }
  return inverso;
}
int q6(int numerobase, int numerobusca){
    int qtdOcorrencias;
    int  i = 0, invertido, busca, contDig = 0;
    int digNum[11] = {0}, digBusca[11]={0};

    for (;numerobase != 0;){
    qtdOcorrencias = 0;
        digNum[i] = numerobase % 10;
        invertido = invertido*10 + digNum[i];
        numerobase = numerobase/10;
        i++;
    }
    for (int l = 0 ;numerobusca != 0; l++){
        digBusca[l] = numerobusca % 10;
        busca = busca*10 + digBusca[l];
        numerobusca = numerobusca/10;
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
