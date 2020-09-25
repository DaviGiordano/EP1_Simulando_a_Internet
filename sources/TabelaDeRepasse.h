#ifndef TABELADEREPASSE_H

#define TABELADEREPASSE_H
#define MAXIMO_TABELA 5

class TabelaDeRepasse
{
private:
    int enderecos[MAXIMO_TABELA];
    //coloquei o nome de 'adjacentes' em vez de roteadoresAdjacentes pq o get dele é getAdjacentes, tranquilo?
    Roteador* adjacentes[MAXIMO_TABELA];
    Roteador *roteadorPadrao;

public:
    TabelaDeRepasse();
    ~TabelaDeRepasse();

    bool mapear(int endereco, Roteador* adjacente);
    Roteador** getAdjacentes();
    int getQuantidadeDeAdjacentes();
    void setPadrao(Roteador *padrao);
    Roteador* getDestino(int endereco);
    void imprimir;
};
#endif // TABELADEREPASSE_H
