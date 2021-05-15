#include <stdio.h>
#include <stdlib.h>
#include "lista_publico.h"

int main (void) {
    
    int resultado;
    int* valorInserido = malloc(sizeof(int*));
    int* valorRemovido = malloc(sizeof(int*));
    // int* valorBuscado = malloc(sizeof(int*));   

    //criar lista
    pLista lista = criarLista(sizeof(int *), &resultado);
    
    printf("Inserindo elementos...\n");
    for(int i=0;i<10000;i++) {
        inserirPos(lista, &i, valorInserido, i, &resultado);
        printf("Valor inserido: %d \n", *valorInserido);
    }

    // printf("\nListando elementos...\n");
    // for(int i=0;i<10;i++) {
    //     valorBuscado = buscarPos(lista, i, &resultado);
    //     printf("Valor buscado: %d \n", *valorBuscado);
    //     printf("Elemento na posicao %d: %d\n", i, *valorBuscado);
    // }

    printf("\nRemovendo elementos...\n");
    for(int i=3000;i>=0;i--) {
        // valorBuscado = buscarPos(lista, i, &resultado);
        printf("Removendo elemento armazenado na posicao %d. \n", i);
        removerPos(lista, valorRemovido, i, &resultado);
    }

    // destruir lista
    destruirLista(lista, &resultado);
    if(resultado == 0) {
        printf("Lista destruída!\n");
    }

}