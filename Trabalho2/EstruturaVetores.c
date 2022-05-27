#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"

Vetor *vetorPrincipal[TAM];

int criarEstruturaAuxiliar(int posicao, int tamanho){
    posicao = posicao - 1;
    int retorno = 0;
    if(posicao<0 || posicao>9){
        retorno = POSICAO_INVALIDA;
    }else if(tamanho < 1){
        retorno = TAMANHO_INVALIDO;
    }else if(vetorPrincipal[posicao] != NULL){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }else{
        for(int i = 0; i<tamanho ;i++){
            vetorPrincipal[posicao] = criar_lista(vetorPrincipal[posicao]);
        }
        if(vetorPrincipal[posicao] == NULL){
            retorno = SEM_ESPACO_DE_MEMORIA;
        }else{
            retorno = SUCESSO;
        }
    }
    return retorno;
}

int inserirNumeroEmEstrutura(int posicao, int valor){

    int retorno = 0;
    posicao = posicao - 1;

    if(posicao<0 || posicao>= TAM){
          retorno = POSICAO_INVALIDA;
    }else{
        if (vetorPrincipal[posicao] != NULL){
            if (existeEspaco(posicao)){
                inserir_elemento(vetorPrincipal[posicao], valor);
                retorno = SUCESSO;
            }else{
                retorno = SEM_ESPACO;
            }
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

int excluirNumeroDoFinaldaEstrutura(int posicao){
    posicao = posicao - 1;
    int retorno = 0;

    if(posicao<0 || posicao>9){
        retorno = POSICAO_INVALIDA;
    }else if(vetorPrincipal[posicao] != NULL){
        if ((vetorPrincipal[posicao]->valido == 0)){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }else{
            Vetor* l = vetorPrincipal[posicao];
            Vetor* x;
            while (l != NULL){
                x = l ->prox;
                if(l->prox ==NULL || x->valido == 0){
                    vetorPrincipal[posicao] = removeElemento(vetorPrincipal[posicao],l->conteudo);
                    l =NULL;
                }else{
                    l = l -> prox;
                }
            }
            Vetor* anterior = NULL;
            Vetor* busca = vetorPrincipal[posicao];
            Vetor* novo = (Vetor*) malloc(sizeof(Vetor));
            while(busca != NULL){
                anterior = busca;
                busca = busca->prox;
            }
            novo->valido = 0;
            novo->prox = NULL;
            anterior->prox = novo;
            retorno = SUCESSO;
        }
    }else{
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    return retorno;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){

    posicao = posicao - 1;
    int retorno = 0;

    if(posicao<0 || posicao>9){
        retorno = POSICAO_INVALIDA;
    }else if(vetorPrincipal[posicao] == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
         if (vetorPrincipal[posicao]->valido == 0){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }else{
            if(buscaValor(vetorPrincipal[posicao],valor)){
                vetorPrincipal[posicao] = removeElemento(vetorPrincipal[posicao],valor);
                Vetor* anterior = NULL;
                Vetor* busca = vetorPrincipal[posicao];
                Vetor* novo = (Vetor*) malloc(sizeof(Vetor));
                while(busca != NULL){
                    anterior = busca;
                    busca = busca->prox;
                }
                novo->valido = 0;
                novo->prox = NULL;
                anterior->prox = novo;
                retorno = SUCESSO;
            }else{
                retorno = NUMERO_INEXISTENTE;
            }
        }
    }
    return retorno;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0;
    int i = 0;
    posicao = posicao - 1;
    if(posicao < 0 || posicao > 9){
        retorno = POSICAO_INVALIDA;
    }else if(vetorPrincipal[posicao] == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        Vetor* aux = vetorPrincipal[posicao];
        while(aux !=NULL){
            if(aux->valido == 1){
                vetorAux[i] = aux->conteudo;
                i++;
            }
            aux = aux->prox;
        }
        retorno = SUCESSO;
    }
    return retorno;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0;
    retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
    if(retorno == SUCESSO){
        ordenaVetor(vetorAux, getQuantidadeElementosEstruturaAuxiliar(posicao));
    }
    return retorno;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int retorno = 0;
    int i = 0;
    int j = 0;
    while(j < 10){
        Vetor* aux = vetorPrincipal[j];
        if(vetorPrincipal[j] != NULL){
            while(aux !=NULL){
                if(aux->valido){
                    vetorAux[i] = aux->conteudo;
                    i++;
                }
                aux = aux->prox;
            }
        }
        j++;
    }
    if(i>0){
        retorno = SUCESSO;
    }else{
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    return retorno;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int tamanho = 0;
    int retorno =  getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if(retorno == SUCESSO){
        for(int i = 0 ; i < 10; i++){
           if(vetorPrincipal[i] != NULL){
               tamanho = tamanho + getQuantidadeElementosEstruturaAuxiliar(i+1);
           }
        }
        ordenaVetor(vetorAux, tamanho);
    }
    return retorno;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    int retorno = 0;
    int quantidade = 0;
    posicao = posicao - 1;

    if(posicao<0 || posicao>9){
        retorno = POSICAO_INVALIDA;
    }else if(vetorPrincipal[posicao] == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        Vetor* l = vetorPrincipal[posicao];
        while(l!=NULL){
            if(l->valido){
                quantidade++;
            }
            l = l->prox;
        }
        retorno = quantidade;
    }
    return retorno;
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){
    No* dados = inicio;
    int i = 0;
    while(dados!=NULL){
        vetorAux[i] = dados->conteudo;
        dados = dados->prox;
        i++;
    }
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno = 0;
    int validade = 0;
    int tamVetAntes = 0;
    posicao = posicao - 1;
    Vetor * l = vetorPrincipal[posicao];
    for(;l!=NULL;){
        l= l->prox;
        tamVetAntes++;
    }
    novoTamanho = tamVetAntes + novoTamanho;

    if(posicao < 0 || posicao > 9){
        retorno = POSICAO_INVALIDA;
    }else if(novoTamanho<1){
        retorno = NOVO_TAMANHO_INVALIDO;
    }else if(vetorPrincipal[posicao] == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        Vetor * aux = vetorPrincipal[posicao];
        vetorPrincipal[posicao] = NULL;
        for(int i = 0; i<novoTamanho ;i++){
            vetorPrincipal[posicao] = criar_lista(vetorPrincipal[posicao]);
        }
        if(vetorPrincipal[posicao] == NULL){
            retorno = SEM_ESPACO_DE_MEMORIA;
            vetorPrincipal[posicao] = aux;
        }else{
            while(aux!= NULL){
                if(aux ->valido){
                    validade = inserirNumeroEmEstrutura(posicao +1,aux ->conteudo);
                    if(validade!=SUCESSO){
                        retorno = validade;
                        aux = NULL;
                    }else{
                       aux = aux ->prox;
                    }
                }else{
                  aux = aux ->prox;
                }
            }
            retorno = SUCESSO;
        }
    }
    return retorno;
}

No *montarListaEncadeadaComCabecote(){
    No* lista = NULL;
    int tamanho = 0;
    for(int i = 0; i < 10; i++){
        if(vetorPrincipal[i] != NULL){
            tamanho = tamanho + getQuantidadeElementosEstruturaAuxiliar(i+1);
        }
    }
    int vetor[tamanho];
    int aux = getDadosDeTodasEstruturasAuxiliares(vetor);
    for(int i = tamanho - 1 ; i > -1 ; i--){
        lista = inserir_lista_cabecote(lista,vetor[i]);
    }
    return lista;
}

void destruirListaEncadeadaComCabecote(No **inicio){
   /* No* destruir = *inicio;
    while(destruir != NULL){
        No * t = destruir->prox;
        free(destruir);
        destruir = t;
    }*/
    *inicio = NULL;
}

No* inserir_lista_cabecote(No* no , int i){
    No* novo = (No*)malloc(sizeof(No));
	novo->conteudo = i;
	novo->prox = no;
	return novo;
}

void inicializar(){
    for(int i = 0 ; i< 10 ; i++){
        vetorPrincipal[i] = NULL;
    }
}

void finalizar(){
    for(int i = 0 ; i < 10 ;i++){
        Vetor* p = vetorPrincipal[i];
        while (p!= NULL){
        Vetor* t = p ->prox;
        free(p);
        p = t;
    }
    }
}

Vetor* criar_lista(Vetor *l){
    Vetor* novo = (Vetor*) malloc(sizeof(Vetor));
    novo ->valido = 0;
    novo ->prox = l;
    return novo;
}

void inserir_elemento(Vetor *l, int numero){
    while(l != NULL){
        if(l->valido == 0){
            l ->conteudo = numero;
            l -> valido = 1;
            break;
        }
        l = l->prox;
    }
}

int existeEspaco(int posicao){
    int retorno = 0;
    Vetor* l = vetorPrincipal[posicao];
    while(l != NULL){
        if(l->valido == 0){
            retorno =1;
            break;
        }
        l = l->prox;
    }
    return retorno;
}

int buscaValor(Vetor* l, int v){
    Vetor* p = l;
    while(p!= NULL){
        if(p->conteudo == v){
                return 1;}

        else{
            return 0;
        }
    }
    return 0;
}

Vetor* removeElemento(Vetor* l,int v){
    Vetor* busca;
    Vetor* anterior = NULL;
    busca = l;

    while(busca != NULL){
        if(busca->conteudo == v){
           if (anterior != NULL){
				anterior->prox = busca -> prox;
				return l;
        }else{
        l = busca->prox;
        return l;
    }
    free(l);
    break;
    }
    anterior = busca;
    busca = busca->prox;
    }
    return NULL;
}

void ordenaVetor(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
    int chave = vetor[i];
    int j = i - 1;
    while (chave < vetor[j] && j >= 0) {
      vetor[j + 1] = vetor[j];
      --j;
    }
    vetor[j + 1] = chave;
  }
}
