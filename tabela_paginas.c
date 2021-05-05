#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

long counter = 0;
long counterProcessId = 0;
#define NUMERO_PROCESSOS 5

typedef struct
{
    long idTabela;
    int numeroPaginas;
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
    int numeroPaginas = ceil((float)tamMemoria / (float)tamPagina);
    GerenciadorDeMemoria->tabelas = (TabelaPaginas *)malloc(numeroPaginas * sizeof(TabelaPaginas));
    GerenciadorDeMemoria->tamPagina = tamPagina;
    GerenciadorDeMemoria->tamMemoria = tamMemoria;
    GerenciadorDeMemoria->tamMaximoProcesso = tamMaximoProcesso;
    GerenciadorDeMemoria->memoria = (Byte *)malloc(tamMemoria * sizeof(Byte));

    for(int i = 0; i < numeroPaginas; i++){
        GerenciadorDeMemoria->tabelas[i].idProcesso = -1;
    }
}

int CriarNumeroRandom(int max)
{
    return rand() % max + 1;
}

int LinkarTabelaComMemoria(TabelaPaginas* tabela) {
    for (int i = 0; i < tabela->numeroPaginas; i++) {
        for (int j = 0; j < gerenciadorDeMemoria.tamMemoria; j = j + gerenciadorDeMemoria.tamPagina) {
            if (!gerenciadorDeMemoria.memoria[j].estaCheio) {
                tabela->paginas[i] = j;
            }
        }
    }
}

TabelaPaginas FuncaoConstrutoraTabela(int tProcesso, int tPagina, long idProcesso)
{
    TabelaPaginas Objeto;
    int numeroPaginas = ceil((float)tProcesso / (float)tPagina);
    Objeto.paginas = (int *)malloc(numeroPaginas * sizeof(int));
    Objeto.numeroPaginas = numeroPaginas;
    Objeto.idTabela = counter;
    Objeto.idProcesso = idProcesso;
    counter++;
    return Objeto;
}

int NumeroPaginasLivres() {
    int count = 0;
    for (int i = 0; i < gerenciadorDeMemoria.tamMemoria; i = i + gerenciadorDeMemoria.tamPagina) {
        if (!gerenciadorDeMemoria.memoria[i].estaCheio) {
            count++;
        }
    }
    return count;
}

void PopularPaginasTabela(TabelaPaginas* tabela){
    for (int i = 0; i < tabela->numeroPaginas; i++) {
        for (int j = 0; j < gerenciadorDeMemoria.tamPagina; j++) {
            char randomChar = CriarNumeroRandom(255);
            gerenciadorDeMemoria.memoria[tabela->paginas[i] + j].estaCheio = true;
            gerenciadorDeMemoria.memoria[tabela->paginas[i] + j].valor = randomChar;
        }
    }
}

int VisualizarMemoria()
{
    // Percorre a memória do gerenciador de memória
    // Exibe o número de bytes alocados em cada página
}

int AdicionarTabela(TabelaPaginas tabela)
{
    for (int i = 0; i < (gerenciadorDeMemoria.tamMemoria / gerenciadorDeMemoria.tamPagina); i++) {
        if (gerenciadorDeMemoria.tabelas[i].idProcesso == -1) {
            // teste para ver se espaço está sendo utilizado
            gerenciadorDeMemoria.tabelas[i] = tabela;
        }
    }
}

int CriarPaginas(int numeroPaginas, int tamanhoPaginas)
{
    // criar n paginas (numero_paginas) de tamanho tamanho_paginas (int)
}

int DesalocarEspaco(int endereco)
{
    printf("Whuu\n");
    gerenciadorDeMemoria.memoria[endereco].estaCheio = false;
}

int DestruirProcesso(long processId){
    for (int i = 0; i < (gerenciadorDeMemoria.tamMemoria / gerenciadorDeMemoria.tamPagina); i++) {
            printf("Whoo %ld \n", gerenciadorDeMemoria.tabelas[i].idProcesso);
        if (gerenciadorDeMemoria.tabelas[i].idProcesso == processId) {
            // teste para ver se espaço está sendo utilizado
            gerenciadorDeMemoria.tabelas[i].idProcesso = -1;
            
            for (int j = 0; j < gerenciadorDeMemoria.tabelas[i].numeroPaginas; i++){
                DesalocarEspaco(gerenciadorDeMemoria.tabelas[i].paginas[i]);
                printf("Whii\n");
            }
            break;
        }
    }
}

void MostrarMemoriaLivre() {
    printf("\nMemória livre:\n");
    for (int i = 0; i < gerenciadorDeMemoria.tamMemoria; i++) {
        if (!gerenciadorDeMemoria.memoria[i].estaCheio) {
            printf("|_| %d\n", i);
        }
    }
    printf("\n");
}

int CriarProcesso(int tamanhoProcesso, long processId)
{
    printf("Criando processo %d...\n", processId);
    // RAISE EXCEPTION
    if (tamanhoProcesso > gerenciadorDeMemoria.tamMaximoProcesso) {
        printf("TAMANHO DO PROCESSO (%d bytes) EXCEDE TAMANHO MÁXIMO (%d bytes)\n", tamanhoProcesso, gerenciadorDeMemoria.tamMaximoProcesso);
        printf("Não foi possível criar processo %d.\n", processId);
        return 0;
    }
    // RAISE EXCEPTION
    if (NumeroPaginasLivres() < ceil((float)tamanhoProcesso / (float)gerenciadorDeMemoria.tamPagina)) {
        printf("TAMANHO DE MEMÓRIA LIVRE INSUFICIENTE PARA CRIAR CRIAR PROCESSO %d\n", processId);
        return 0;
    }
    TabelaPaginas tabela = FuncaoConstrutoraTabela(tamanhoProcesso, gerenciadorDeMemoria.tamPagina, processId);
    LinkarTabelaComMemoria(&tabela);
    PopularPaginasTabela(&tabela);
    AdicionarTabela(tabela);
    printf("Tamanho do processo %d: %d bytes\n", processId, tamanhoProcesso);
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

    // RAISE EXCEPTION
    if (tamPagina > tamMemoria) {
        printf("TAMANHO DA PÁGINA (%d bytes) EXCEDE TAMANHO DA MEMÓRIA (%d bytes)\n", tamPagina, tamMemoria);
        printf("Não foi possível criar páginas.");
        return 0;
    }
    int numeroPaginas = tamMemoria / tamPagina;

    FuncaoConstrutoraGerenciadorDeMemoria(&gerenciadorDeMemoria, tamPagina,
                                          tamMemoria, tamMaxProcesso);
    CriarPaginas(numeroPaginas, tamPagina);

    for (long i = 0; i < NUMERO_PROCESSOS; i++)
    {
        randTamanhoProcesso = CriarNumeroRandom(tamMaxProcesso * 2);
        CriarProcesso(randTamanhoProcesso, i + 1);
    }

    // VisualizarMemoria(tabela);

    printf("Destruindo processos...\n");
    for (long i = 0; i < NUMERO_PROCESSOS; i++)
    {
        printf("Destruindo processo %ld\n", i + 1);
        DestruirProcesso(i + 1);
        // MostrarMemoriaLivre();
    }

    return 0;
}

// TODO
// Visualizar Memória (Pedro)
// Destruir processos e desalocar memória (Patrick)
// Mostrar memoria livre (Franco)
// Exceptions (Luiz)
// Criar Páginas (preencher array de tabelaPaginas deixando processId NULL)