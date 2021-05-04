#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

long counter = 0;
long counterProcessId = 0;
#define NUMERO_PROCESSOS 10

typedef struct
{
    long idTabela;
    long idProcesso;
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

void FuncaoConstrutoraGerenciadorDeMemoria(GerenciadorDeMemoria *GerenciadorDeMemoria,
                                                            int tamPagina, int tamMemoria,
                                                            int tamMaximoProcesso)
{
    int numeroPaginas = tamMemoria / tamPagina;
    GerenciadorDeMemoria->tabelas = (TabelaPaginas *)malloc(numeroPaginas * sizeof(TabelaPaginas));
    GerenciadorDeMemoria->tamPagina = tamPagina;
    GerenciadorDeMemoria->tamMemoria = tamMemoria;
    GerenciadorDeMemoria->tamMaximoProcesso = tamMaximoProcesso;
}

int CriarNumeroRandom(int max)
{
    return rand() % max + 1;
}

int LinkarTabelaComMemoria(TabelaPaginas* tabela) {
    printf("%d\n", sizeof(tabela->paginas));
    for (int i = 0; i < sizeof(tabela->paginas); i++) {
        for (int j = 0; j < sizeof(gerenciadorDeMemoria.memoria); j++) {
            if (!gerenciadorDeMemoria.memoria[j].estaCheio) {
                tabela->paginas[i] = j;
            }
        }
    }
}

TabelaPaginas FuncaoConstrutoraTabela(int tProcesso, int tPagina, int idProcesso)
{
    TabelaPaginas Objeto;
    // int numeroPaginas = ceil((float)tProcesso / (float)tPagina);
    Objeto.paginas = (int *)malloc(tProcesso * tPagina * sizeof(int));
    printf("Tam proc %d pag %d pags %d\n", tProcesso, tPagina, sizeof(Objeto.paginas));
    Objeto.idTabela = counter;
    Objeto.idProcesso = idProcesso;
    printf("Tam proc %d pag %d pags %d\n", tProcesso, tPagina, sizeof(Objeto.paginas));
    counter++;
    return Objeto;
}

void PopularPaginasTabela(TabelaPaginas* tabela){
    for (int i = 0; i < sizeof(tabela->paginas); i++) {
        char randomChar = CriarNumeroRandom(255);
        gerenciadorDeMemoria.memoria[tabela->paginas[i]].valor = randomChar;
        gerenciadorDeMemoria.memoria[tabela->paginas[i]].estaCheio = true;
    }
}

int VisualizarMemoria()
{
    // Percorre a memória do gerenciador de memória
    // Exibe o número de bytes alocados em cada página
}

int AdicionarTabela(TabelaPaginas tabela)
{
    for (int i = 0; i < sizeof(gerenciadorDeMemoria.tabelas); i++) {
        if (gerenciadorDeMemoria.tabelas[i].idProcesso == -1) {
            // teste para ver se espaço está sendo utilizado
            gerenciadorDeMemoria.tabelas[i] = tabela;
        }
    }
}

void CriarMemoria(int tamanhoMemoria)
{
    gerenciadorDeMemoria.memoria = (Byte *)malloc(tamanhoMemoria * sizeof(Byte));
}

int CriarPaginas(int numeroPaginas, int tamanhoPaginas)
{
    // criar n paginas (numero_paginas) de tamanho tamanho_paginas (int)
}

int AlocarEspaco(char a, int endereco)
{
    gerenciadorDeMemoria.memoria[endereco].valor = a;
}

int DestruirProcesso(int processId){
    
}

void MostrarMemoriaLivre() {
    for (int i = 0; i < sizeof(gerenciadorDeMemoria.memoria); i++) {
        if (!gerenciadorDeMemoria.memoria[i].estaCheio) {
            printf("|_| %d", i);
        }
    }
}

int CriarProcesso(int tamanhoProcesso, int processId)
{
    // RAISE EXCEPTION: tamanhoProcesso maior que tamanho maximo
    printf("Criando processo %d\n", processId);
    TabelaPaginas tabela = FuncaoConstrutoraTabela(tamanhoProcesso, gerenciadorDeMemoria.tamPagina, processId);
    LinkarTabelaComMemoria(&tabela);
    PopularPaginasTabela(&tabela);
    AdicionarTabela(tabela);
    printf("Tamanho do processo %d: %d\n", processId, tamanhoProcesso);
    MostrarMemoriaLivre();
}

int main(int argc, char *argv[])
{
    if(argc != 4) {
        printf("Uso: %s <tamanho memoria> <tamanho pagina> <tamanho processo>\n", argv[0]);
        exit(1);
    }
    int tamMemoria = atoi(argv[1]);
    int tamPagina = atoi(argv[2]);
    int tamMaxProcesso = atoi(argv[3]);
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

    // VisualizarMemoria(tabela);

    for (int i = 0; i < NUMERO_PROCESSOS; i++)
    {
        DestruirProcesso(i);
    }

    return 0;
}

// TODO
// Visualizar Memória (Pedro)
// Destruir processos e desalocar memória (Patrick)
// Mostrar memoria livre (Franco)
// Exceptions (Luiz)
// Criar Páginas (preencher array de tabelaPaginas deixando processId NULL)