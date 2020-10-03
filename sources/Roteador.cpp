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

Fila* Roteador::getFila() {
    return this->fila;
}

int Roteador::getEndereco() {
    return this->endereco;
}

string Roteador::getUltimoDadoRecebido() {
    return this->ultimoDadoRecebido;
}

TabelaDeRepasse* Roteador::getTabela(){
    return this->tabela;
}

// OUTROS METODOS ==========================================================================

// Adiciona um datagrama a fila caso ela nao esteja cheia, caso contrario, nao adiciona o datagrama
// e imprime uma mensagem de erro
void Roteador::receber(Datagrama *d) {
    if (!this->fila->enqueue(d)) {
        cout << "\tFila em " << this->endereco << " estourou" << endl;
    }
}

void Roteador::processar() {

    //tentar dequeue da fila do Roteador
    Datagrama* datagramaAtual = this->fila->dequeue();

    //Se datagramaAtual existir
    if(datagramaAtual){
        datagramaAtual->processar(); //TTL -= 1

        if(!datagramaAtual->ativo()){ //Se morreu
            cout << "\tDestruido por TTL: ";
            datagramaAtual->imprimir();

            delete datagramaAtual; //Delete

        } //se não morreu
        else if(datagramaAtual->getDestino() == this->endereco){ //se destino for esse endereço
            this->ultimoDadoRecebido = datagramaAtual->getDado(); //atribuir o dado
            cout << "\tRecebido";
            datagramaAtual->imprimir();
            delete datagramaAtual;

        }
        else { //se o destino não for esse endereço
            Roteador* proximoRoteador = this->tabela->getDestino(datagramaAtual->getDestino()); //descobrir endereço pela tRepasse

            if(proximoRoteador){ //se proximo roteador existir
                cout << "\tEnviado para " << proximoRoteador->endereco << ": ";
                datagramaAtual->imprimir();
                proximoRoteador->receber(datagramaAtual); //Enviar para o roteadorDestino

            }else { //se tabelaRepasse retornar NULL, por algum motivo que desconheco
                delete datagramaAtual;

            }
        }
    }
}

void Roteador::imprimir() {

    cout << "Endereco: " << this->endereco
         << ", Ultimo dado recebido: " << this->ultimoDadoRecebido << endl;
    cout << "FILA:" << endl;
    this->fila->imprimir();
    cout << "TABELA DE REPASSE:" << endl;
    this->tabela->imprimir();

}

// =========================================================================================
