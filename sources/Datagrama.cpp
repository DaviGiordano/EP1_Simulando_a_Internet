#include "Datagrama.h"
#include <iostream>
#include <string>
using namespace std;

// CONSTRUTOR E DESTRUTOR ===================================================

Datagrama::Datagrama(int origem, int destino, int ttl, string dado) :
origem (origem), destino (destino), ttl (ttl), dado (dado)
{
}

Datagrama::~Datagrama()
{
}


// Processa o datagrama decrementando o Time To Live (TTL) dele em 1
void Datagrama::processar() {
    this->ttl -= 1;
}

// Retorna true caso o datagrama estiver ativo e false caso contrario
bool Datagrama::ativo(){
    return (this->getTtl() > 0);
}

// GETTERS ==================================================================
int Datagrama::getOrigem(){
    return this->origem;
}

int Datagrama::getDestino(){
    return this->destino;
}

int Datagrama::getTtl(){
    return this->ttl;
}

string Datagrama::getDado(){
    return this->dado;
}

// Imprime as informacoes do datagrama
void Datagrama::imprimir(){
    cout << "dado - " << this->getDado() << endl;
    cout << "origem - " << this->getOrigem() << endl;
    cout << "destino - " << this->getDestino() << endl;
    cout << "ttl - " << this->getTtl() << endl;
    cout << "ativo - " << this->ativo() << endl;
    cout << endl; // '\n'
}

