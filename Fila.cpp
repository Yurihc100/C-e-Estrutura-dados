#include "Fila.h"

Fila::Fila()
{
    inicio = NULL;
    fim = NULL;
}

bool Fila::vazia()
{
    return (inicio == NULL);
}

bool Fila::cheia()
{
    return false;
}

bool Fila::inserir(string nomeArquivo, int numPaginas, int idArquivo)
{
    // Inserir um arquivo na fila de impressão;
    // Altere o método inserir:
    PonteiroElemento p;
    p = new elemento;
    p->nomeArquivo = nomeArquivo;
    p->qntFolhas = numPaginas;
    p->idArquivo = idArquivo;

    if (vazia())
    {
        p->idArquivo = 1;
        inicio = p;
        fim = p;
    }
    else
    {
        p->idArquivo = fim->idArquivo++;
        fim->proximoElemento = p;
        fim = p;
    }
    p->proximoElemento = NULL;
    return true;
}

bool Fila::remover(int &auxValor)
{
    // Remover um arquivo da fila da impressão (imprimir);
    // Altere o método remover:
    PonteiroElemento p;

    if (vazia())
        return false;

    auxValor = inicio->idArquivo;

    p = inicio;
    inicio = inicio->proximoElemento;
    delete p;
    if (inicio == NULL)
        fim = NULL;
    return true;
}

string Fila::listar()
{
    // Implementar listagem da fila de impressão;
    // Retornar string no formato:
    // <idImpressao1> - <nomeArquivo1> - <folhas1>\n
    // <idImpressao2> - <nomeArquivo2> - <folhas2>\n
    //
    // Seu código aqui

    if (!vazia())
    {
        PonteiroElemento p = inicio;
        while (p->proximoElemento != NULL)
        {
            cout << "" << p->idArquivo << '-' << p->nomeArquivo << '-' << p->qntFolhas << endl;
            p = p->proximoElemento;
        }
    }
}

bool Fila::inserirFolhas(int auxFolhas)
{
    // Inserir mais folhas na impressora;
    // Seu código aqui
    numeroFolhasDisponiveis += auxFolhas;

    return true;
}

int Fila::listarFolhas()
{
    // Retorna o total de folhas disponíveis na impressora;
    // Seu código aqui

    return numeroFolhasDisponiveis;
}

bool Fila::imprimir()
{
    int controlePaginas = 0;
    if (!vazia())
    {
        PonteiroElemento p = inicio;
        while (p->proximoElemento != NULL)
        {
            controlePaginas += p->qntFolhas;
            p = p->proximoElemento;
        }
    }

    if (controlePaginas > listarFolhas())
    {
        return false;
    }

    numeroFolhasDisponiveis -= controlePaginas;
    inicio = NULL;
    fim = NULL;
}