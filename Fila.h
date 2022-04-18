class Fila
{
private:
    struct elemento
    {
        string nomeArquivo;
        int qntFolhas;
        int idArquivo;
        elemento *proximoElemento;
    };
    typedef elemento *PonteiroElemento;
    PonteiroElemento inicio;
    PonteiroElemento fim;
    int numeroFolhasDisponiveis;

public:
    Fila();
    bool vazia();
    bool cheia();
    // alterar
    bool inserir(string nomeArquivo, int numPaginas, int idArquivo);
    bool remover(int &auxValor);
    // implementar
    string listar();
    int listarFolhas();
    bool inserirFolhas(int auxFolhas);
    bool imprimir();
};