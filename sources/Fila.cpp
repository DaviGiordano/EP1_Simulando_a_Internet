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

bool Fila::enqueue(Datagrama *d) {
        // condicao para fila cheia 
    if ( (this->inicio == 0 && this->fim == this->tamanho + 1 ) || this->fim + 1 == this->inicio) {
        // caso cheia, retorna falso
        return false;
    } else {
        // caso contrario, adiciona datagrama no fim da fila
        this->vetorDeDatagramas[this->fim] = d;

        // e atualiza o valor de fim
        if (this->fim == tamanho + 1) {
            this->fim = 0;
        } else  {
            this->fim += 1;
        }
        return true;
    }
}

