#ifndef REDE_H

#define REDE_H
#include <string>
#include "Roteador.h"

class Rede {
private:
    Roteador **roteadores;
    int quantidadeDeRoteadores;
public:
    Rede(Roteador **roteadores, int quantidadeDeRoteadores);
    ~Rede();

    Roteador *getRoteador(int endereco);

    void enviar(string texto, Roteador* origem, int destino, int ttl);
    void passarTempo();
    void imprimir(int endereco);
};

#endif
