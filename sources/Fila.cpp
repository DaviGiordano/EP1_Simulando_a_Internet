#include "Fila.h"


// Inicializa a fila e constroi um vetor de datagramas com espaço tamanho 
Fila::Fila(int tamanho) :
tamanho (tamanho)
{
    this->vetorDeDatagramas = new Datagrama *[tamanho + 1];
}

Fila::~Fila()
{
}

