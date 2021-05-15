#include <stdio.h>
#include <stdlib.h>
#include "ldde_publica.h"

int main (void) {
    pldde lista = NULL;
    int hops;
    

    if(CriarLista(&lista, sizeof(int)) == ERRO){
        printf("Erro ao criar a lista!\n");
        exit(1);
    }

    printf("Inserindo elementos...\n");
    for(int i=0;i<10000;i++) {
        hops = 0;
        printf("Valor de i: %d\n", i);
        hops = InserirPos(lista, (void *) &i, i);
        printf("Elemento %d, inserido na posicao %d. \n", *(int *) BuscarPos(lista, i), i);
        printf("saltos: %d\n", hops);
    }

    // printf("\nListando elementos...\n");
    // for(int i=0;i<10000;i++) {
    //     printf("Elemento na posicao %d: %d\n", i, *(int *) BuscarPos(lista, i));
    // }

    for(int i=3000;i>=0;i--) {
        hops = 0;
        printf("Removendo elemento %d, armazenado na posicao %d. \n", *(int *) BuscarPos(lista, i), i);
        hops = RemoverPos(lista, i);
        printf("Saltos: %d\n\n", hops);
    }

    if(DestruirLista(&lista) == ERRO){
        printf("Erro ao destruir a lista!\n");
        exit(1);
    }

}