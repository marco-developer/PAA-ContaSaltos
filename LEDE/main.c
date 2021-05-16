#include <stdio.h>
#include <stdlib.h>

#include "lista_publica.h"

int main(int argc, char* argv[]) {
  int tamanho = 10000;
  lLista lista = criarLista(tamanho, sizeof(int));
  int saltos_inserir = 0;
  int saltos_remover = 0;
  int i = 0;
  
  if (lista == 0) {
    printf("Erro ao criar a lista!\n");
    exit(1);
  }

  printf("[main.c] Inserindo elementos nas posições...\n");
  inserirInicio(lista, &i, &saltos_inserir);
  for (i=0; i<tamanho-1; i++) {
    inserirPos(lista, &i, i, &saltos_inserir);
    printf("[main.c] Inserindo elemento na posição %d: %d\n", i, i);
    printf("[main.c] Saltos: %d\n", saltos_inserir);
  }
  
  printf("\nRemovendo elementos das posições...\n");
  for(i=2999;i>=0;i--) {
    printf("[main.c] Removendo elemento armazenado na posicao %d. \n", i);
    removerPos(lista, i, &saltos_remover);
  }
  
  return 0;
}
