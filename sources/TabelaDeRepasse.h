#ifndef TABELADEREPASSE_H

#define TABELADEREPASSE_H


#include "Roteador.h"

class Roteador; //prototipo da Roteador

class TabelaDeRepasse
{
private:
    int quantidadeDeAdjacentes = 0;
    int *enderecos;
    Roteador **adjacentes;
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
