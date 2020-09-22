#include "Datagrama.h"
#include <iostream>
#include <string>
using namespace std;


Datagrama::Datagrama(int origem, int destino, int ttl, string dado) :
origem (origem), destino (destino), ttl (ttl), dado (dado)
{
}

Datagrama::~Datagrama()
{
}

//ativo implementação
bool Datagrama::ativo(){
    return (this->getTtl() > 0);
}

//Getters implementação
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

//Teste implementação
void Datagrama::imprimir(){
    cout << "dado - " << this->getDado() << endl;
    cout << "origem - " << this->getOrigem() << endl;
    cout << "destino - " << this->getDestino() << endl;
    cout << "ttl - " << this->getTtl() << endl;
    cout << "ativo - " << this->ativo() << endl;
    cout << endl; // '\n'
}
