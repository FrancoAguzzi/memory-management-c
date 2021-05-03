
#include <stdbool.h>

long counter = 0;

typedef struct {
    int id_tabela;
    int tamanho_memoria;
    int tamanho_pagina;
    int tamanho_max_processo;
    int (*visualizar)(int);
} TabelaPaginas;

int VisualizarTabela(int id);
TabelaPaginas* FuncaoConstrutora(TabelaPaginas * Objeto, int t_memoria, int t_pagina, int t_max_processo);

TabelaPaginas* FuncaoConstrutora(TabelaPaginas * Objeto, int t_memoria, int t_pagina, int t_max_processo) {
    Objeto->id_tabela = counter;
	Objeto->tamanho_memoria = t_memoria;
	Objeto->tamanho_pagina = t_pagina;
	Objeto->tamanho_max_processo = t_max_processo;
	Objeto->visualizar = VisualizarTabela(Objeto->id_tabela);
    counter = counter++;
    return Objeto;
}

int VisualizarTabela(int id) {
    // pega lista encadeada de tabelas no gerenciador de memória
    TabelaPaginas tabela_atual;
    bool found;
    found = false;
    while (!found) {
        if (tabela_atual.id_tabela == id) {
            found = true;
        } else {
            tabela_atual = tabela_atual.prox_tabela;
        };
    }
    printf("Visualização de tabela:\n\n");
    printf("ID: %f\n", tabela_atual.id_tabela);
}

int CriarNumeroRandom(int max)
{
  return rand() % max;
}

int main(int argc, char *argv[]) {
    TabelaPaginas* tabela;
    int param1 = argv[0];
    int param2 = argv[1];
    int param3 = argv[2];

    for (int i = 0; i < 10; i++) {
        // 10 por enquanto
        tabela = FuncaoConstrutora(&tabela, CriarNumeroRandom(param1), CriarNumeroRandom(param2), CriarNumeroRandom(param3));
    }

    FuncaoConstrutora(&tabela, param1, param2, param3);
    return 0;
}