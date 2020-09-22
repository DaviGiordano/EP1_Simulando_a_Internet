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
    void processar();
    bool ativo(); 

    // FUNÇÃO TESTE
    void imprimir();

};



#endif