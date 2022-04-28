#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//renomeie o arquivo do include abaixo para PrimeiroUltimoNomeMATRICULA.h
#include "LucasFigueredo20212160031.h"

void testQ1(); // Okay
void testQ2(); //Problema no retorno
void testQ3(); // Okay
void testQ4(); // Okay
void testQ5(); // Okay
void testQ6(); // Okay

int main(){
    //printf("q1\n");
    //testQ1(); // 10 testes
    printf("q2\n");
    testQ2(); // 35 testes
    //printf("q3\n");
    //testQ3(); // 13 testes
    //printf("q4\n");
    //testQ4(); // 22 testes
   // printf("q5\n");
    //testQ5(); // 10 testes
    //printf("q6\n");
    //testQ6(); // 10 testes
}

void testQ1(){
    char data[NASC];
    strcpy(data,"29/02/2015");
    printf("%d\n",q1(data) == 0);
    strcpy(data,"29/02/2012");
    printf("%d\n",q1(data) == 1);
    strcpy(data,"9/13/2014");
    printf("%d\n",q1(data) == 0);
    strcpy(data,"45/4/2014");
    printf("%d\n",q1(data) == 0);
    strcpy(data,"12/1/15");
    printf("%d\n",q1(data) == 1);
    strcpy(data,"1/9/2016");
    printf("%d\n",q1(data) == 1);
    strcpy(data,"//2016");
    printf("%d\n",q1(data) == 0);
    strcpy(data,"1//20");
    printf("%d\n",q1(data) == 0);
    strcpy(data,"1/R/2016");
    printf("%d\n",q1(data) == 0);
    strcpy(data,"1/12/19");
    printf("%d\n",q1(data) == 1);

}

void testQ2(){
    char dataInicial[11], dataFinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    int retorno;
    DiasMesesAnos dma;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
printf("===========================\n");
    strcpy(dataInicial, "01/06/2015");
    strcpy(dataFinal, "01/06/2016");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 0);
    printf("%d\n", dma.qtdMeses == 0);
    printf("%d\n", dma.qtdAnos == 1);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
printf("===========================\n");
    strcpy(dataInicial,"01/30/2015");
    strcpy(dataFinal,"01/06/2016");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n",dma.retorno == 2);
printf("===========================\n");
    strcpy(dataInicial,"01/3/2015");
    strcpy(dataFinal,"40/06/2016");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n",dma.retorno == 3);
printf("===========================\n");
    strcpy(dataInicial,"01/06/2016");
    strcpy(dataFinal,"01/06/2015");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n",dma.retorno == 4);

    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
printf("===========================\n");
    strcpy(dataInicial,"06/06/2017");
    strcpy(dataFinal,"07/07/2017");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 1);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);

    //teste 4
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
printf("===========================\n");
    strcpy(dataInicial,"06/06/2017");
    strcpy(dataFinal,"05/07/2018");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 29);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);

    //teste 5
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
printf("===========================\n");
    strcpy(dataInicial,"26/07/2017");
    strcpy(dataFinal,"25/08/2017");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 30);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 0);

    //teste 6
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
printf("===========================\n");
    strcpy(dataInicial,"26/06/2017");
    strcpy(dataFinal,"26/07/2017");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 0);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);

    //teste 8
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
    printf("===========================\n");
    strcpy(dataInicial,"27/02/2016");
    strcpy(dataFinal,"03/03/2017");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 4);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);

    //teste 9
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
  printf("===========================\n");
    strcpy(dataInicial,"27/02/2015");
    strcpy(dataFinal,"03/03/2016");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 5);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);


    //teste 10
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
    printf("===========================\n");
    strcpy(dataInicial,"28/01/2016");
    strcpy(dataFinal,"29/02/2016");
    dma = q2(dataInicial, dataFinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 1);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);

}

void testQ3(){
    char texto[250];
    strcpy(texto,"Renato Lima Novais");
    printf("%d\n",q3(texto, 'a', 0) == 3);
    printf("%d\n",q3(texto, 'b', 0) == 0);
    printf("%d\n",q3(texto, 'l', 1) == 0);
    printf("%d\n",q3(texto, 'l', 0) == 1);
    printf("%d\n",q3(texto, 'L', 0) == 1);

    strcpy(texto,"Letícia, signifiCa fEliCIdADE");
    printf("%d\n",q3(texto, 'c', 0) == 3);
    printf("%d\n",q3(texto, 'C', 0) == 3);
    printf("%d\n",q3(texto, 'c', 1) == 1);
    printf("%d\n",q3(texto, 'C', 1) == 2);
    printf("%d\n",q3(texto, 'R', 0) == 0);
    printf("%d\n",q3(texto, 'e', 0) == 3);
    printf("%d\n",q3(texto, 'E', 1) == 2);
    printf("%d\n",q3(texto, 'S', 1) == 0);


}

void testQ4(){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i < 30; i++){
        posicoes[i] = -1;
    }
    printf("================================================================\n");
    strcpy(strTexto,"Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca,"rato");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n",posicoes[0]==5);
    printf("%d\n",posicoes[1]==8);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==37);


    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    printf("================================================================\n");
    strcpy(strTexto,"Ola, o mundo e muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca,"mui");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n",posicoes[0]==16);
    printf("%d\n",posicoes[1]==18);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==36);
    printf("%d\n",posicoes[4]==52);
    printf("%d\n",posicoes[5]==54);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    printf("================================================================\n");
    strcpy(strTexto,"Programar é legal?");
    strcpy(strBusca,"sim");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 0);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    printf("================================================================\n");
    strcpy(strTexto,"maraaaavilha, meu prograaaama funcionou");
    strcpy(strBusca,"aa");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 4);
    printf("%d\n",posicoes[0]==4);
    printf("%d\n",posicoes[1]==5);
    printf("%d\n",posicoes[2]==6);
    printf("%d\n",posicoes[3]==7);
    printf("%d\n",posicoes[4]==24);
    printf("%d\n",posicoes[5]==25);
    printf("%d\n",posicoes[6]==26);
    printf("%d\n",posicoes[7]==27);


}
void testQ5(){
    printf("%d\n",q5(345) == 543);
    printf("%d\n",q5(78) == 87);
    printf("%d\n",q5(3) == 3);
    printf("%d\n",q5(5430) == 345);
    printf("%d\n",q5(1000) == 1);
    printf("%d\n",q5(0) == 0);
    printf("%d\n",q5(707) == 707);
    printf("%d\n",q5(80) == 8);
    printf("%d\n",q5(8) == 8);
    printf("%d\n",q5(1234) == 4321);
}

void testQ6(){
    printf("%d\n",q6(34567368, 3) == 2);
    printf("%d\n",q6(34567368, 4576) == 0);
    printf("%d\n",q6(3539343, 3) == 4);
    printf("%d\n",q6(3539343, 39) == 1);
    printf("%d\n",q6(5444, 44) == 1);
    printf("%d\n",q6(54444, 44) == 2);
    printf("%d\n",q6(1234562354, 23) == 2);
    printf("%d\n",q6(1234, 13) == 0);
    printf("%d\n",q6(544444, 4) == 5);
    printf("%d\n",q6(1234562354, 32) == 0);

}
