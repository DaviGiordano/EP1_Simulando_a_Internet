#include <iostream>
#include "Roteador.h"
#include "TabelaDeRepasse.h"

using namespace std;

Roteador::Roteador(int key): key (key){
}

TabelaDeRepasse* Roteador::getTabela(){
    return this->tabela;
}
