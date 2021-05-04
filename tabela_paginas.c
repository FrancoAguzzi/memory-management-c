
#include <stdbool.h>

long counter = 0;
long counterProcessId = 0;
#define NUMERO_PROCESSOS 10

typedef struct
{
    int idTabela;
    int idProcesso;
    int *paginas;
} TabelaPaginas;

typedef struct
{
    TabelaPaginas *tabelas;
    int tamMaximoProcesso;
    int tamMemoria;
    int tamPagina;
    int *paginas;
    char *memoria;
} GerenciadorDeMemoria;

GerenciadorDeMemoria gerenciadorDeMemoria;

// typedef struct LINKED_LIST
// {
//     TabelaPaginas Atual;
//     struct LINKED_LIST *Prox;
// };

// struct LINKED_LIST *memoria;

GerenciadorDeMemoria *FuncaoConstrutoraGerenciadorDeMemoria(GerenciadorDeMemoria *GerenciadorDeMemoria,
                                                            int tamPagina, int tamMemoria,
                                                            int tamMaximoProcesso)
{
    GerenciadorDeMemoria->tamPagina = tamPagina;
    GerenciadorDeMemoria->tamMemoria = tamMemoria;
    GerenciadorDeMemoria->tamMaximoProcesso = tamMaximoProcesso;
    return GerenciadorDeMemoria;
}

TabelaPaginas *FuncaoConstrutoraTabela(TabelaPaginas *Objeto, int tProcesso, int tPagina, int idProcesso)
{
    int numeroPaginas = ceil((float)tProcesso / (float)tPagina);
    Objeto->paginas = (int *)malloc(numeroPaginas * tPagina * sizeof(BYTE) + sizeof(Objeto));
    Objeto->idTabela = counter;
    Objeto->idProcesso = idProcesso;
    counter = counter++;
    return Objeto;
}

void PopularPaginasTabela(TabelaPaginas tabela){
    char randomChar = criarNumeroRandom(255);
    
}

int VisualizarMemoria()
{
    // Percorre a memória do gerenciador de memória
    // Exibe o número de bytes alocados em cada página;

    gerenciadorDeMemoria.memoria

    printf("Visualização de tabela:\n\n");
    printf("ID: %f\n", tabelaAtual.idTabela);
}

int CriarNumeroRandom(int max)
{
    return rand() % max;
}

int AdicionarTabela(TabelaPaginas tabela)
{
    // adicionar tabela na lista encadeada
    // atualizar memoria.Atual
}

void CriarMemoria(int tamanhoMemoria)
{
    // criar array de char[] tamanho sendo igual ao tamanho_memoria
    gerenciadorDeMemoria.memoria = (char *)malloc(tamanhoMemoria * sizeof(char));
}

int CriarPaginas(int numeroPaginas, int tamanhoPaginas)
{
    // criar n paginas (numero_paginas) de tamanho tamanho_paginas (int)
}

int AlocarEspaco(char a, int endereco)
{
    gerenciadorDeMemoria.memoria[endereco] = a;
}

int DestruirProcesso(int processId){
    
}

int CriarProcesso(int tamanhoProcesso, int processId)
{
    TabelaPaginas *tabela;
    //cria processo de tamanho tamanhoProcesso
    tabela = FuncaoConstrutoraTabela(&tabela, tamanhoProcesso, gerenciadorDeMemoria.tamPagina);
    PopularPaginasTabela(tabela, processId);
    AdicionarTabela(tabela);
}

int main(int argc, char *argv[])
{
    int tamMemoria = argv[0];
    int tamPagina = argv[1];
    int tamMaxProcesso = argv[2];
    int randTamanhoProcesso;
    // dar exception se numero_paginas == 0
    int numeroPaginas = tamMemoria / tamPagina;

    FuncaoConstrutoraGerenciadorDeMemoria(&gerenciadorDeMemoria, tamPagina,
                                          tamMemoria, tamMaxProcesso);

    CriarMemoria(tamMemoria);
    CriarPaginas(numeroPaginas, tamPagina);

    for (int i = 0; i < NUMERO_PROCESSOS; i++)
    {
        randTamanhoProcesso = CriarNumeroRandom(tamMaxProcesso * 2);
        // criar processo (pega rand_tamanho_max_processo para testar se rand_tamanho_processo > t_max_processo, cria paginas necessarias, alocar paginas necessarias)
        CriarProcesso(randTamanhoProcesso, i);

        // Informa o tamanho do processo em bytes na sua criação
        // mostrar paginas livres
    }
    VisualizarMemoria(tabela);

    return 0;
}