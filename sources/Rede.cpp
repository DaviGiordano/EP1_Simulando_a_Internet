#include "Rede.h"
#include "Roteador.h"
#include "Datagrama.h"
#include <string>
#include <iostream>

using namespace std;

Rede::Rede(Roteador **roteadores, int quantidadeDeRoteadores) :
roteadores (roteadores), quantidadeDeRoteadores (quantidadeDeRoteadores) {
}

Rede::~Rede() {
}

/**
 * Cria um datagrama e o direciona para o roteador origem para comecar sua transmissao ate o roteador destino.
 */
void Rede::enviar(string texto, Roteador* origem, int destino, int ttl) {
    // criando datagrama
    Datagrama *novoDatagrama = new Datagrama(origem->getEndereco(), destino, ttl, texto);

    // Enviando datagrama ao Roteador origem para comecar a transmissao
    origem->receber(novoDatagrama);
}

