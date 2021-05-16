#include "lista_interface.h"

#include <stdio.h>

int main() {
    Lista* lista;
    int res;
    int * dado;
    
    res = listaCriar(&lista);

    printf("\nIniciada a inserção dos 10000 elementos na lista.\n");
        
    for (int i=0; i<10000; i++){
        //printf("%d ",i);
        res = listaInserirPos(lista, i, sizeof(int), &i);
        //if (res == SUCESSO) {printf(" OK,  ");}
    }

    printf("\nConcluído!\nNúmero de saltos: %d", contador);

    printf("\nIniciada a remoção dos 3000 elementos na lista.\n");
    contador = 0;  // Para zerar a contagem
    
    for (int i=2999; i>=0; i--){
        //printf("%d ",i);
        res = listaRemoverPos(lista, i, &dado);
        //if (res == SUCESSO) {printf(" OK,  ");}
    }

    printf("\nConcluído!\nNúmero de saltos: %d", contador);




    /*

    printf("Criar lista: %d\n", res);

    int num[] = {10, 7, 3};
    double num2[] = {2.7, -11.111};
    char str[] = "teste";

    res = listaInserirInicio(lista, sizeof(double), &num2[0]);
    // 2.7
    printf("Inserir %f: %d \n", num2[0], res);

    res = listaInserirFim(lista, sizeof(int), &num[0]);
    // 2.7 10
    printf("Inserir %d: %d \n", num[0], res);

    res = listaInserirInicio(lista, sizeof(int), &num[1]);
    // 7 2.7 10
    printf("Inserir %d: %d \n", num[1], res);

    res = listaInserirFim(lista, sizeof(double), &num2[1]);
    // 7 2.7 10 -11.111
    printf("Inserir %f: %d \n", num2[1], res);

    res = listaInserirPos(lista, 2, sizeof(int), &num[2]);
    // 7 2.7 3 10 -11.111
    printf("Inserir %d: %d \n", num[2], res);

    res = listaInserirPos(lista, 3, sizeof(str), str);
    // 7 2.7 3 "teste" 10 -11.111
    printf("Inserir %s: %d \n", str, res);

    printf("\n");
  
    int int_val;
    double double_val;
    char str_val[10];

    res = listaBuscarInicio(lista, &int_val);
    printf("Buscar inicio: %d\n%d\n", res, int_val);

    res = listaBuscarFim(lista, &double_val);
    printf("Buscar fim: %d\n%f\n", res, double_val);

    printf("\n");

    int types[] = {0, 1, 0, 2, 0, 1};
    for (int i = 0; i < listaTamanho(lista); ++i) {
        if (types[i] == 0) {
            res = listaBuscarPos(lista, i, &int_val);
            printf("Buscar pos %d: %d\n%d\n", i, res, int_val);
        } else if (types[i] == 1) {
            res = listaBuscarPos(lista, i, &double_val);
            printf("Buscar pos %d: %d\n%f\n", i, res, double_val);
        } else {
            res = listaBuscarPos(lista, i, str_val);
            printf("Buscar pos %d: %d\n%s\n", i, res, str_val);
        }
    }

    printf("\n");

    res = listaRemoverPos(lista, 3, &str_val);
    // 7 2.7 3 10 -11.111
    printf("Remover pos 3: %d\n%s\n", res, str_val);

    res = listaRemoverPos(lista, 3, &int_val);
    // 7 2.7 3 -11.111
    printf("Remover pos 3: %d\n%d\n", res, int_val);

    res = listaRemoverInicio(lista, &int_val);
    // 2.7 3 -11.111
    printf("Remover inicio: %d\n%d\n", res, int_val);

    res = listaRemoverFim(lista, &double_val);
    // 2.7 3
    printf("Remover fim: %d\n%f\n", res, double_val);

    printf("\n");

    */

    res = listaDestruir(&lista);

    return 0;
}