
#define ERRO 1;
#define SUCESSO 0;

typedef struct descritor *pLista; 

pLista criarLista(int tamanho_dados, int *resultado); 

void inserirInicio(pLista lista, void *elemento,  void *valorInserido, int *resultado, int *saltos); 
void inserirFim(pLista lista, void *elemento, void *valorInserido, int *resultado, int *saltos); 
void inserirPos(pLista lista, void *elemento, void *valorInserido, int pos, int *resultado, int *saltos);  // 0- primeira posicao

void removerInicio(pLista lista, void *valorRemovido, int *resultado, int *saltos);
void removerFim(pLista lista, void *valorRemovido, int *resultado, int *saltos);
void removerPos(pLista lista, void *valorRemovido, int post, int *resultado, int *saltos);

void* buscarInicio(pLista lista, int *resultado);
void* buscarFim(pLista lista, int *resultado);
void* buscarPos(pLista lista, int pos, int *resultado);

void destruirLista(pLista lista, int *resultado);

void imprimir(pLista lista);


