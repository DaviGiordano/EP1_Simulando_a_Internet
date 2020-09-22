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

// ==========================================================================

// GETTERS ==================================================================

int Datagrama::getOrigem() {
    return this->origem;
}

int Datagrama::getDestino() {
    return this->destino;
}

int Datagrama::getTtl() {
    return this->ttl;
}

string Datagrama::getDado() {
    return this->dado;
}

// ==========================================================================

// Processa o datagrama decrementando o Time To Live (TTL) dele em 1
void Datagrama::processar() {
    this->ttl -= 1;
}

// Retorna true caso o datagrama estiver ativo e false caso contrário

bool Datagrama::ativo() {
    return this->ttl >= 0;
}

// Imprime as informações do datagrama
void Datagrama::imprimir() {
    cout << "origem - " << this->origem << endl;
    cout << "destino - " << this->destino << endl;
    cout << "ttl - " << this->ttl << endl;
    cout << "dado - " << this->dado << endl;
    cout << "ativo - " << this->ativo() << endl;
}