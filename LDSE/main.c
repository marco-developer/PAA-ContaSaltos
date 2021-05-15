#include <stdio.h>
#include <stdlib.h>
#include "lista_publico.h"

int main (void) {
    
    int resultado, saltosIn = 0, saltosRem = 0;
    int* valorInserido = malloc(sizeof(int*));
    int* valorRemovido = malloc(sizeof(int*));
    // int* valorBuscado = malloc(sizeof(int*));   

    //criar lista
    pLista lista = criarLista(sizeof(int *), &resultado);
    
    for(int i=0;i<10000;i++) {
        printf("Inserindo elemento %d\n", i);
        // inserirFim(lista, &i, valorInserido, &resultado, &saltosIn);
        inserirPos(lista, &i, valorInserido, i, &resultado, &saltosIn);
        printf("Valor inserido: %d \n\n", *valorInserido);
    }
    
    printf("\nRemovendo elementos...\n");
    for(int i=2999;i>=0;i--) {
        // valorBuscado = buscarPos(lista, i, &resultado);
        printf("Removendo elemento armazenado na posicao %d. \n", i);
        removerPos(lista, valorRemovido, i, &resultado, &saltosRem);
    }
    
    printf("\n=-=-=-=\n");
    printf("Total de saltos Insercao: %d\n", saltosIn);
    printf("Total de saltos Remocao : %d\n", saltosRem);

    // destruir lista
    destruirLista(lista, &resultado);
    if(resultado == 0) {
        printf("Lista destruída!\n");
    }

}