#ifndef ROTEADOR_H
#define ROTEADOR_H

#include <string>

#include "TabelaDeRepasse.h"
#include "Fila.h"
#include "Datagrama.h"

#define TAMANHO_FILA 3
//Defino isso aqui ou no Roteador?

class TabelaDeRepasse; //protótipo da TabelaDeRepasse

class Roteador
{
private:
    TabelaDeRepasse* tabela;
    Fila* fila;
    int endereco;
    string ultimoDadoRecebido; //inicializar como "" aqui ou no construtor?

public:
    TabelaDeRepasse();
    ~TabelaDeRepasse();

    TabelaDeRepasse* getTabela();
    Fila *getFila();
    int getEndereco();
    string getUltimoDadoRecebido();

    void receber(Datagrama* d);
    void processar();

    void imprimir();
};

#endif // ROTEADOR_H
