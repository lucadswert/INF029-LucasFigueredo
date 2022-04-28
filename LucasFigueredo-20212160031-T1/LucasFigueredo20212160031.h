#ifndef TRABALHO1_LUCASFIGUEREDO20212160031_H
#define TRABALHO1_LUCASFIGUEREDO20212160031_H
#define NASC 11

int q1(char data[]);
int q2(char* dataInicial, char* dataAtual);
int q3(char* texto , char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);

//Funções Q1 e Q2
int validaDataQ1(char *validar);
int validaDataQ2(char *dataInicial, char *dataFinal);
char data[NASC],dataInicial[NASC], dataFinal[NASC] ;
int datavalida;

// Funções Q3
char c;
char texto[250];
int isCaseSensitive;

//Funções Q4
char strTexto[250], strBusca[50];

// Q5
int num;

//Q6
int numerobase, numerobusca;

#endif  // TRABALHO1_LUCASFIGUEREDO20212160031_H
