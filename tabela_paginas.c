
#include <stdbool.h>

long counter = 0;
#define NUMERO_PROCESSOS 10

typedef struct {
    int id_tabela;
    int id_processo;
    int* paginas;
} TabelaPaginas;

typedef unsigned char BYTE;

typedef struct LINKED_LIST
{
  TabelaPaginas Atual;
  struct LINKED_LIST *Prox;
};

struct LINKED_LIST* memoria;

TabelaPaginas* FuncaoConstrutoraTabela(TabelaPaginas * Objeto, int t_processo, int t_pagina);

TabelaPaginas* FuncaoConstrutoraTabela(TabelaPaginas * Objeto, int t_processo, int t_pagina) {
    int numero_paginas = ceil((float)t_processo / t_pagina);
    Objeto->paginas = (int*)malloc(numero_paginas * t_pagina * sizeof(BYTE) + sizeof(Objeto));
    Objeto->id_tabela = counter;
    counter = counter++;
    return Objeto;
}

int VisualizarMemoria() {
    // pega lista encadeada de tabelas no gerenciador de memória
    TabelaPaginas tabela_atual;
    // tabela_atual recebe LINKED_LIST.Atual
    bool found;
    found = false;
    while (tabela_atual->Prox) {
        
    }
    printf("Visualização de tabela:\n\n");
    printf("ID: %f\n", tabela_atual.id_tabela);
}

int CriarNumeroRandom(int max)
{
  return rand() % max;
}

int AdicionarTabela(TabelaPaginas tabela) {
    // adicionar tabela na lista encadeada
    // atualizar memoria.Atual
}

int CriarMemoria(int tamanho_memoria) {
    // criar array de char[] tamanho sendo igual ao tamanho_memoria
}

int CriarPaginas(int numero_paginas, int tamanho_paginas) {
    // criar n paginas (numero_paginas) de tamanho tamanho_paginas (int)
}

int main(int argc, char *argv[]) {
    TabelaPaginas* tabela;
    int tam_memoria = argv[0];
    int tam_pagina = argv[1];
    int tam_max_processo = argv[2];
    int rand_tamanho_processo;
    // dar exception se numero_paginas == 0
    int numero_paginas = tam_memoria / tam_pagina;
    CriarMemoria(tam_memoria);
    CriarPaginas(numero_paginas, tam_pagina);

    for (int i = 0; i < NUMERO_PROCESSOS; i++) {
        rand_tamanho_processo = CriarNumeroRandom(tam_max_processo * 2);
        // criar processo (pega rand_tamanho_max_processo para testar se rand_tamanho_processo > t_max_processo, cria paginas necessarias, alocar paginas necessarias)
        tabela = FuncaoConstrutoraTabela(&tabela, rand_tamanho_processo, tam_pagina);
        AdicionarTabela(tabela);
        // Informa o tamanho do processo em bytes na sua criação
        // mostrar paginas livres
    }
    VisualizarMemoria(tabela);

    return 0;
}