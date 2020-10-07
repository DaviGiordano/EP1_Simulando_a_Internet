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
    //delete[] roteadores; //tem que deletar o ponteiro, nao? Nao
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

//Retorna um Roteador com o endereco informado, dentre aqueles no vetor, ou entao retorna NULL, se nao houver roteador com esse endereco
Roteador* Rede::getRoteador(int endereco){
    for(int i = 0; i<this->quantidadeDeRoteadores; i++){
        if(this->roteadores[i]->getEndereco() == endereco){
            return this->roteadores[i];
        }
    }
    return NULL;
}
//chama o metodo processar de cada roteador dentro da rede, uma �nica vez
void Rede::passarTempo(){

    for (int i = 0; i < this->quantidadeDeRoteadores; i++){

        this->roteadores[i]->processar();
    }
}

//Imprime informa��es b�sicas sobre a rede, e chama o m�todo imprimir de um roteador especificado
//LEMBRAR DE RETIRAR, POR PRECAUCAO
void Rede::imprimir(int endereco){
    cout << "+++ REDE +++" << endl;
    cout << "\tQuantidade de roteadores: " << this->quantidadeDeRoteadores << endl << endl;
    roteadores[endereco]->imprimir();

}

