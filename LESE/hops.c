#include <stdio.h>
#include <stdlib.h>
#include "Lista_publica.h"

int main(int argc, char **argv) {

int Resultado;
int i = 0;

//Lista de números
lista_t *listaNumeros = NULL;
listaNumeros = CriarLista(sizeof(int), 10000, &Resultado);

 printf("Inserindo elementos no final da lista\n");
    for(i = 1; i<=10000; i++) {
        int *k = (int*)malloc(sizeof(int));
        *k = i;
        InserirFim(listaNumeros, *k, &Resultado);  //Jeito correto de enviar e receber os dados
        //printf("Numero inserido no final da lista: %d\n",(int)BuscarFim(listaNumeros, &Resultado));
    }
      printf("Numero de saltos ao INSERIR no final foi de: %d\n", numero_saltos_insere());

    printf("\n\n");


int aux = 0;
printf("\nRemovendo elementos no final da lista\n");
    for (aux=3000; aux>0; aux--) {
        void* dado;
        dado = RemoverFim(listaNumeros, &Resultado);
       // printf("Elemento removido do fim da lista: %d\n",(int)dado);
        }
        printf("Numero de saltos ao REMOVER no final foi de: %d\n", numero_saltos_remove());

    printf("\n## Destruindo a lista ##\n\n");
    DestruirLista(listaNumeros, &Resultado);
      
}