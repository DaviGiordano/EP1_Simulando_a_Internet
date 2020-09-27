#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "TabelaDeRepasse.h"

class TabelaDeRepasse; //protótipo da TabelaDeRepasse

class Roteador{
    Roteador(int key);
private:
    TabelaDeRepasse* tabela;
    int key;//INVENTADO
public:
    TabelaDeRepasse* getTabela();
    int getKey();//INVENTADO
    void imprimir();
};

#endif // ROTEADOR_H
