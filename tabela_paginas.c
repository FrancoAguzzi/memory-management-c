
#include <stdbool.h>
#include <stdlib.h>

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
    bool estaCheio;
    char valor;
} Byte;

typedef struct
{
    TabelaPaginas *tabelas;
    int tamMaximoProcesso;
    int tamMemoria;
    int tamPagina;
    int *paginas;
    Byte *memoria;
} GerenciadorDeMemoria;

GerenciadorDeMemoria gerenciadorDeMemoria;

GerenciadorDeMemoria *FuncaoConstrutoraGerenciadorDeMemoria(GerenciadorDeMemoria *GerenciadorDeMemoria,
                                                            int tamPagina, int tamMemoria,
                                                            int tamMaximoProcesso)
{
    int numeroPaginas = ceil((float)tamMemoria / (float)tamPagina);
    GerenciadorDeMemoria->tabelas = (int *)malloc(numeroPaginas * sizeof(TabelaPaginas));
    GerenciadorDeMemoria->tamPagina = tamPagina;
    GerenciadorDeMemoria->tamMemoria = tamMemoria;
    GerenciadorDeMemoria->tamMaximoProcesso = tamMaximoProcesso;
    return GerenciadorDeMemoria;
}

int LinkarTabelaComMemoria(TabelaPaginas* tabela) {
    for (int i = 0; i < sizeof(tabela->paginas); i++) {
        for (int j = 0; j < sizeof(gerenciadorDeMemoria.memoria); j++) {
            if (!gerenciadorDeMemoria.memoria[j].estaCheio) {
                tabela->paginas[i] = j;
            }
        }
    }
}

TabelaPaginas *FuncaoConstrutoraTabela(TabelaPaginas *Objeto, int tProcesso, int tPagina, int idProcesso)
{
    int numeroPaginas = ceil((float)tProcesso / (float)tPagina);
    Objeto->paginas = (int *)malloc(numeroPaginas * tPagina * sizeof(char) + sizeof(Objeto));
    Objeto->idTabela = counter;
    Objeto->idProcesso = idProcesso;
    counter = counter++;
    return Objeto;
}

void PopularPaginasTabela(TabelaPaginas* tabela){
    for (int i = 0; i < sizeof(tabela->paginas); i++) {
        char randomChar = criarNumeroRandom(255);
        gerenciadorDeMemoria.memoria[tabela->paginas[i]].valor = randomChar;
        gerenciadorDeMemoria.memoria[tabela->paginas[i]].estaCheio = true;
    }
}

int VisualizarMemoria()
{
    // Percorre a memória do gerenciador de memória
    // Exibe o número de bytes alocados em cada página
}

int CriarNumeroRandom(int max)
{
    return rand() % max;
}

int AdicionarTabela(TabelaPaginas tabela)
{
    for (int i = 0; i < sizeof(gerenciadorDeMemoria.tabelas); i++) {
        if (gerenciadorDeMemoria.tabelas[i].idProcesso == NULL) {
            // teste para ver se espaço está sendo utilizado
            gerenciadorDeMemoria.tabelas[i] = tabela;
        }
    }
}

void CriarMemoria(int tamanhoMemoria)
{
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

void MostrarMemoriaLivre() {
    // printa memoria livre
}

int CriarProcesso(int tamanhoProcesso, int processId)
{
    // RAISE EXCEPTION: tamanhoProcesso maior que tamanho maximo 
    TabelaPaginas *tabela;
    tabela = FuncaoConstrutoraTabela(&tabela, tamanhoProcesso, gerenciadorDeMemoria.tamPagina, processId);
    LinkarTabelaComMemoria(tabela);
    PopularPaginasTabela(tabela);
    AdicionarTabela(*tabela);
    printf("Tamanho do processo %d: %d\n", processId, tamanhoProcesso);
    MostrarMemoriaLivre();
}

int main(int argc, char *argv[])
{
    int tamMemoria = argv[0];
    int tamPagina = argv[1];
    int tamMaxProcesso = argv[2];
    int randTamanhoProcesso;
    // RAISE EXCEPTION: numero_paginas == 0
    int numeroPaginas = tamMemoria / tamPagina;

    FuncaoConstrutoraGerenciadorDeMemoria(&gerenciadorDeMemoria, tamPagina,
                                          tamMemoria, tamMaxProcesso);

    CriarMemoria(tamMemoria);
    CriarPaginas(numeroPaginas, tamPagina);

    for (int i = 0; i < NUMERO_PROCESSOS; i++)
    {
        randTamanhoProcesso = CriarNumeroRandom(tamMaxProcesso * 2);
        CriarProcesso(randTamanhoProcesso, i);
    }
    VisualizarMemoria(tabela);

    return 0;
}

// TODO
// Visualizar Memória (Pedro)
// Destruir processos e desalocar memória (Patrick)
// Mostrar memoria livre (Franco)
// Exceptions (Luiz)
// Criar Páginas (preencher array de tabelaPaginas deixando processId NULL)