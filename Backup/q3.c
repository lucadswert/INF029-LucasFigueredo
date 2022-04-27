#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>

char frase[250];
char fraseB[250];
char busca;
char buscaB;
int qtdOcorrencias;
int caseS;

void minusculo(char *s1, char s2[]);

int main() {
        setlocale(LC_ALL, "Portugues");
        printf("Insira uma frase de ate 250 caracteres:\n-> ");
        fgets(frase, 250, stdin);

        printf("Insira um caractere para buscar:\n-> ");
        scanf("%c", &busca);

        printf("Deseja realizar busca com CaseSensitive [1 p/ SIM / 0 p/ NAO]\n-> ");
        scanf("%d", &caseS);

        if (caseS == 1){
        for(int i = 0; frase[i] != '\0'; i++){
            if (frase[i] == busca){
                qtdOcorrencias++;
            }
        }
        }
        else{
        minusculo(frase, fraseB);
        buscaB = tolower(busca);
        for(int i = 0; fraseB[i] != '\0'; i++){
            if (fraseB[i] == buscaB){
                qtdOcorrencias++;
            }
        }
        }
        printf("\nA letra %c aparece, %d vezes\n", busca, qtdOcorrencias);

    return qtdOcorrencias;
}
void minusculo(char *s1, char s2[]){
    int j;
    for (int t = 0; s1[t] != '\0'; t++){
        if((s1[t] == 'ä') || (s1[t] == 'á') || (s1[t] == 'ã') || (s1[t] == 'â') || (s1[t] == 'à')){
            s1[t] = 'a';}
        if(s1[t] == 'ê'|| s1[t] == 'ë'|| s1[t] == 'é' || s1[t] == 'è'){
            s1[t] = 'e';}
        if(s1[t] == 'í'|| s1[t] == 'î'|| s1[t] == 'ï' || s1[t] == 'ì'){
            s1[t] = 'i';}
        if(s1[t] == 'ö'|| s1[t] == 'ó'|| s1[t] == 'ô' || s1[t] == 'ò' || s1[t] == 'õ'){
            s1[t] = 'o';}
        if(s1[t] == 'ü'|| s1[t] == 'ú'|| s1[t] == 'û' || s1[t] == 'ù'){
            s1[t] = 'u';}
        if(s1[t] == 'ç'){
            s1[t] = 'c';}
    }
    while(s1[j] != '\0'){
        s2[j] = tolower(s1[j]);
        j++;
    }
    s2[j] = '\0';
    }
