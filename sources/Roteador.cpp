#include <iostream>
#include <string>

#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include "Datagrama.h"

#define TAMANHO_FILA 3
//Defino isso aqui ou no Roteador?

using namespace std;

Roteador::Roteador(int endereco): endereco (endereco){

}


/*já tinha feito antes, quando tentava testar a TabelaDeRepasse*/
TabelaDeRepasse* Roteador::getTabela(){
    return this->tabela;
}
