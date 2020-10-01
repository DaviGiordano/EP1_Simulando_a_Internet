#include <iostream>
#include <string>
using namespace std;

#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include "Datagrama.h"
#include "Fila.h"

#define TAMANHO_FILA 3
//Defino isso aqui ou no Roteador?

using namespace std;

// CONSTRUTOR E DESTRUTOR ==================================================================

Roteador::Roteador(int endereco) : 
endereco (endereco) {
    this->fila = new Fila(TAMANHO_FILA); // inicializa Fila
    this->tabela = new TabelaDeRepasse();   // cria a tabela de repasse do roteador
}

Roteador::~Roteador() {
    delete this->tabela;
    delete this->fila;
}

// =========================================================================================


// GETTERS =================================================================================

/*ja tinha feito antes, quando tentava testar a TabelaDeRepasse*/
TabelaDeRepasse* Roteador::getTabela(){
    return this->tabela;
}
