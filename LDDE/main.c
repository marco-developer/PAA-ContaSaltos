#include <stdio.h>
#include <stdlib.h>
#include "ldde_publica.h"

int main (void) {
    pldde lista = NULL;
    int saltosIn = 0, saltosRem = 0;
    

    if(CriarLista(&lista, sizeof(int)) == ERRO){
        printf("Erro ao criar a lista!\n");
        exit(1);
    }

    printf("Inserindo elementos...\n");
    for(int i=0;i<10000;i++) {
        printf("Valor de i: %d\n", i);
        InserirPos(lista, (void *) &i, i, &saltosIn);
        // printf("Elemento %d, inserido na posicao %d. \n", *(int *) BuscarPos(lista, i), i);
        printf("Elemento inserido na posicao %d. \n", i);
    }

    for(int i=3000;i>=0;i--) {
        printf("Removendo elemento %d, armazenado na posicao %d. \n", *(int *) BuscarPos(lista, i), i);
        RemoverPos(lista, i, &saltosRem);
    }
    
    printf("\n=-=-=-=\n");
    printf("Total de saltos Insercao: %d\n", saltosIn);
    printf("Total de saltos Remocao : %d\n", saltosRem);

    if(DestruirLista(&lista) == ERRO){
        printf("Erro ao destruir a lista!\n");
        exit(1);
    }

}