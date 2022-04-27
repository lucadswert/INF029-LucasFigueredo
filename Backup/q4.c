#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void minusculo(char *s1, char s2[]);
int main()
{
    int qtdOcorrencias = 0;
    char frase[250];
    char fraseB[250];
    char busca[50];
    char buscaB[50];
    int res[50] = {0};
    int tamPalavra;

    printf("Insira uma frase de ate 250 caracteres:\n-> ");
    fgets(frase, 250, stdin);
    minusculo(frase, fraseB);

    printf("Insira uma palavra para buscar:\n-> ");
    scanf("%s", busca);
    minusculo(busca, buscaB);

    tamPalavra = strlen(buscaB);

    for(int i = 0; fraseB[i] != '\0';){
        int aux;
        int j = 0;
        int cont = 0;

        while ((fraseB[i] == buscaB[j]))
        {
            cont++;
            i++;
            j++;
        }
        if(cont == tamPalavra){
            res[aux] = i - tamPalavra + 1;
            aux++;
            res[aux] = i;
            aux++;
            qtdOcorrencias++;
            cont = 0;
        }
        else
            i++;
}
    printf ("A palavra inserida aparece %d vezes\n", qtdOcorrencias);
    for(int k = 0; res[k] != 0 ; k++){
        printf ("\n============================================================\n");
        printf ("A palavra comeca na pos: %d e termina em %d\n", res[k], res[k+1]);
        printf ("============================================================\n");
        k++;
    }
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
