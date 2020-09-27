#include "TabelaDeRepasse.h"
#include "Roteador.h"
#include <iostream>
#define MAXIMO_TABELA 5
using namespace std;

// CONSTRUTOR E DESTRUTOR ===================================================

TabelaDeRepasse::TabelaDeRepasse(){
    this->enderecos = new int[MAXIMO_TABELA];
    this->adjacentes = new Roteador*[MAXIMO_TABELA]; //foda de testar o roteador porque ele simplesmente nao existe ainda kk
    this->roteadorPadrao = NULL; //ponteiro para roteador apontando para NULL, check.
}

TabelaDeRepasse::~TabelaDeRepasse() {
    delete[] this->adjacentes;
    delete[] this->enderecos;
}

// GETTERS E SETTERS=========================================================

Roteador** TabelaDeRepasse::getAdjacentes() {
    return this->adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    return this->quantidadeDeAdjacentes;
}

void TabelaDeRepasse::setPadrao(Roteador *padrao) {
    this->roteadorPadrao = padrao;
}

Roteador* TabelaDeRepasse::getDestino(int endereco) {
    for (int i = 0; i < this->quantidadeDeAdjacentes; i++) { //percorra os enderecos mapeados
        if (endereco == this->enderecos[i]) { //se o endereco foi mapeado
            return this->adjacentes[i]; //retorne o roteador de indice correspondente
        }
    }//se saiu do for sem encontrar o endereco desejado
    return this->roteadorPadrao; //retorne o padrao
}

//OUTROS METODOS=============================================================

bool TabelaDeRepasse::mapear(int endereco, Roteador *adjacente) {
    if (this->quantidadeDeAdjacentes == MAXIMO_TABELA) {
        // JA FORAM MAPEADOS TODOS OS ENDERECOS POSSIVEIS NA TABELA
        return false;
    } else {
        // FALTA GENTE PRA SER MAPEADA
        // procura se esse endereco ja ta na tabela
        for (int i = 0; i < this->quantidadeDeAdjacentes; i++) {
            if (this->enderecos[i] == endereco) {
                // neste caso, o endereco ja esta na tabela
                this->adjacentes[i] = adjacente; // trocando o roteador ligado ao endereco que ja esta na tabela
                return true; // sai da funcao imediatamente sem incrementar o valor de this->quantidadeDeAdjacentes
            }
        }
        // Se sobreviveu a esse for significa que o endereco nao esta mapeado, vamos mapea-lo
        this->enderecos[this->quantidadeDeAdjacentes] = endereco; // Colocando na proxima posicao o endereco
        this->adjacentes[this->quantidadeDeAdjacentes] = adjacente; // Colocando na proxima posicao o roteador
        this->quantidadeDeAdjacentes += 1; // aumentando a quantidade de enderecados
        return true;
    }
}

void TabelaDeRepasse::imprimir(){
    cout << this->quantidadeDeAdjacentes << endl;
    this->roteadorPadrao->imprimir(); //supondo que um roteador possui um metodo imprimir
    for(int i = 0; i < this->quantidadeDeAdjacentes; i++){
        cout << "Indice - " << i << endl;
        cout << "Endereco - " << this-enderecos[i] << endl;
        cout << "Roteador - ";
        this->adjacentes[i]->imprimir();
    }
}
