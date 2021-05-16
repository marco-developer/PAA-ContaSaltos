#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ldde_privada.h"

int CriarLista(pldde *lista, int tamanho_dados){

    /* Aloca o espa�o e verifica o sucesso */
    pldde tmp_lista = (pldde) malloc(sizeof(ldde));
    if(tmp_lista == NULL){
        printf("Erro: Aloca��o de mem�ria para cria��o da lista falhou!\n");
        return ERRO;
    }

    /* Inicializa os ponteiros da lista */
    tmp_lista->tamanho_dados = tamanho_dados;
    tmp_lista->inicio = tmp_lista->fim = NULL;
    tmp_lista->quantidade_nos = 0;

    /* Atualiza o ponteiro externo */
    *lista = tmp_lista;
    return SUCESSO;
}

int ReiniciarLista(pldde lista){
    /* Caso a lista n�o exista, informa o erro */
    if(lista == NULL){
        printf("Erro: Ponteiro para lista nulo, lista j� destru�da ou n�o iniciada!\n");
        return ERRO;
    }
    
    /* Percorre a lista removendo os n�s */
    noLdde * no = NULL; 
    while(lista->inicio != NULL){
        no = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(no->dados);
        free(no);
    }
    return SUCESSO;
}

int DestruirLista(pldde *lista){
    /* Chama a Reinicializa��o da lista para limpar todos os n�s */
    if(ReiniciarLista(*lista) == ERRO)
        return ERRO;

    /* Dest�i o descritor da lista */
    free(*lista);
    *lista = NULL;
    return SUCESSO; 
}

/* Fun��o wrapper para inser��o no in�cio utilizando a InserirPos */
int InserirInicio(pldde lista, void * elemento, int *saltos){
    return InserirPos(lista, elemento, 0, saltos);
}

/* Fun��o wrapper para inser��o no final utilizando a InserirPos */
int InserirFim(pldde lista, void * elemento, int *saltos){
    return InserirPos(lista, elemento, lista->quantidade_nos, saltos);
}

int InserirPos(pldde lista, void * elemento, int posicao, int *saltos){
    int i = 0;
    noLdde * atual = (noLdde *) malloc(sizeof(noLdde));
    
    /* Se a posi��o informada for maior que a quantidade de n�s, retorna erro */
    if(posicao > lista->quantidade_nos){
        printf("Erro: Posi��o inexistente!\n");
        return ERRO;
    }

    /* Aloca o espa�o para o novo n� e verifica sucesso */
    noLdde * novo_no = (noLdde *) malloc(sizeof(noLdde));
    if(novo_no == NULL){
        printf("Erro: Aloca��o de mem�ria para cria��o de n� falhou!\n");
        return ERRO;
    }

    /* Inicializa os ponteiros do novo n� */
    novo_no->prox = novo_no->ant = NULL;
    
    /* Aloca o espa�o para os dados e verifica sucesso */ 
    novo_no->dados = (void *) malloc(lista->tamanho_dados);
    if(novo_no->dados == NULL){
        printf("Erro: Aloca��o de mem�ria para o dado falhou!\n");
        return ERRO;
    }

    /* Copia o novo elemento para o n� */
    
    memcpy(novo_no->dados, elemento, lista->tamanho_dados);

    /* Percorre a lista para encontrar o elemento na posi��o especificada */
    atual = lista->inicio; 
    for(i = 0; i < posicao; i++){
        atual = atual->prox;
        *saltos = *saltos + 1; // MAM
    }

    /* Caso o valor do n� seja nulo, ent�o a inser��o deve ser no final ou n�o h� elementos na lista */
    if(atual == NULL){
        /* Atualiza os ponteiros de acordo com o caso espec�fico */
        if(posicao == 0){
            lista->inicio = lista->fim = novo_no;
        }else{
            novo_no->ant = lista->fim;
            lista->fim->prox = novo_no;
            lista->fim = novo_no;
        }
        *saltos = *saltos + 1; // MAM
        lista->quantidade_nos++;

        return SUCESSO;
    }

    /* Atualiza os ponteiros caso a inser��o seja de fato no meio da lista */
    novo_no->prox = atual;
    novo_no->ant = atual->ant;
    atual->ant = novo_no;

    /* Se o elemento foi inserido no in�cio (para o caso em que j� haviam elementos na lista), o */
    /* ponteiro da lista deve ser atualizado */
    if(posicao == 0)
        lista->inicio = novo_no;

    lista->quantidade_nos++;

    return SUCESSO; 
}

/* Fun��o wrapper para buscar no in�cio utilizando a BuscarPos */
void * BuscarInicio(pldde lista){
    return lista->inicio->dados;
}

/* Fun��o wrapper para buscar no fim utilizando a BuscarPos */
void * BuscarFim(pldde lista){
    return lista->fim->dados;
}

void * BuscarPos(pldde lista, int posicao){
    int i = 0;
    noLdde * atual = NULL;

    /* Percorre a lista buscando pelo n� na posi��o informada */
    atual = lista->inicio; 
    for(i = 0; i < posicao && atual->prox != NULL; i++){
        atual = atual->prox;
    }

    /* Caso o n� seja nulo, ent�o a posi��o informada n�o existe */
    if(atual == NULL){
        printf("Erro: Posi��o inexistente!\n");
        return NULL;
    }

    return atual->dados;
}

/* Fun��o wrapper para remover do in�cio utilizando a RemoverPos */
int RemoverInicio(pldde lista,int *saltos){
    return RemoverPos(lista, 0, saltos);
}

/* Fun��o wrapper para remover do fim utilizando a RemoverPos */
int RemoverFim(pldde lista, int *saltos){
    return RemoverPos(lista, lista->quantidade_nos - 1, saltos);
}

int RemoverPos(pldde lista, int posicao, int *saltos){
    int i = 0;
    noLdde * atual = NULL;
    
    /* Caso a posi��o informada seja maior ou igual � quantidade de n�s, retorna erro */
    if(posicao >= lista->quantidade_nos){
        printf("Erro: Posi��o inexistente!\n");
        return ERRO;
    }

    printf("QTD NOS LISTA: %d\n", lista->quantidade_nos);
    /* Percorre a lista procurando pelo elemento na posi��o informada */
    atual = lista->inicio; 
    for(i = 0; i < posicao; i++){
        atual = atual->prox;
        *saltos = *saltos + 1; // MAM
    }

    /* Atualiza os ponteiros de acordo com o caso espec�fico (in�cio, fim ou meio) */
    if(posicao == 0){

        if(lista->quantidade_nos>1){
            lista->inicio = atual->prox;
        }
        lista->inicio->ant = NULL;
    }else if(posicao == lista->quantidade_nos - 1){
        lista->fim = atual->ant;
        lista->fim->prox = NULL;
    }else{
        noLdde * aux = atual->prox;
        atual->ant->prox = aux;
        atual->prox->ant = atual->ant;
    }

    if(lista->quantidade_nos>1){
        free(atual->dados);
        free(atual);
    }

    lista->quantidade_nos--;
    return SUCESSO;
}
