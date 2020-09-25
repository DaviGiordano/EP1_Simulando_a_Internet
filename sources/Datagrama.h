#ifndef DATAGRAMA_H

#define DATAGRAMA_H
#include <string>
using namespace std;
class Datagrama
{
private:
    int origem;
    int destino;
    int ttl;
    string dado;
public:
    Datagrama(int origem, int destino, int ttl, string dado);
    ~Datagrama();

    // GETTERS
    int getOrigem();
    int getDestino();
    int getTtl();
    string getDado();

    // USABILIDADE DO DATAGRAMA

    // Processa o datagrama decrementando o Time To Live (TTL) dele em 1
    void processar();
    //retorna true se Ttl > 0. Retorna false se Ttl <= 0
    bool ativo();

    // FUNÇÃO TESTE
    void imprimir();

};



#endif
