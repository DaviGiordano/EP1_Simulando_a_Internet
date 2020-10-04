#include "Rede.h"
#include "Roteador.h"
#include <string>
#include <iostream>

Rede::Rede(Roteador **roteadores, int quantidadeDeRoteadores) :
roteadores (roteadores), quantidadeDeRoteadores (quantidadeDeRoteadores) {
}

Rede::~Rede() {
}

