#include <stdio.h>
#include <stdlib.h>
#include "Lista_publica.h"

int main(int argc, char **argv) {

int Resultado;
int i = 0;

//Lista de números
lista_t *listaNumeros = NULL;
listaNumeros = CriarLista(sizeof(int), 10000, &Resultado);

//Necessário inserir um elementos na lista para satisfazer uma das validações do "InserePos"
InserirInicio(listaNumeros, (int)100, &Resultado);

 printf("Inserindo elementos em uma posicao da lista\n");
    for(i = 0; i<=10000; i++) {
        int *k = (int*)malloc(sizeof(int));
        *k = i;
        InserirPos(listaNumeros, *k, i, &Resultado);  //Jeito correto de enviar e receber os dados
        //printf("Numero inserido na posicao %d da lista: %d\n",i, (int)BuscarPos(listaNumeros, i, &Resultado));
    }

    printf("\n\n");

int aux = 0;
printf("\nRemovendo elementos em uma posicao da lista\n");
    for (aux=3000; aux>0; aux--) {
        void* dado;
        dado = RemoverPos(listaNumeros, aux, &Resultado);
        printf("Elemento removido da posicao %d: %d\n",aux, (int)dado);
        }

    printf("\n");

    printf("Numero de saltos ao INSERIR em uma posicao foi de: %d\n", numero_saltos_insere());
    printf("Numero de saltos ao REMOVER em uma posicao foi de: %d\n", numero_saltos_remove());
  
}