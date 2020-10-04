#include "Fila.h"
#include <iostream>
#include <string>
using namespace std;

// Inicializa a fila e constroi um vetor de datagramas com espaço tamanho
Fila::Fila(int tamanho) :
tamanho (tamanho)
{
    this->vetorDeDatagramas = new Datagrama *[this->tamanho + 1];
}

Fila::~Fila()
{
}

// Adiciona um datagrama na fila. Retorna false caso a fila estiver cheia e true se conseguiu adicionar o datagrama
bool Fila::enqueue(Datagrama *d) {
        // condicao para fila cheia

    if ( (this->inicio == 0 && this->fim == this->tamanho ) || this->fim + 1 == this->inicio) {
        // caso cheia, retorna falso
        return false;
    } else {
        // caso contrario, adiciona datagrama no fim da fila
        this->vetorDeDatagramas[this->fim] = d;

        // e atualiza o valor de fim
        if (this->fim == this->tamanho) {
            this->fim = 0;
        } else  {
            this->fim += 1;
        }
        return true;
    }
}

// Retorna true caso a fila estiver cheia e false caso contrario
bool Fila::isEmpty() {
    return this->inicio == this->fim;
}

// Retira um datagrama da fila. Retorna NULL caso a fila esteja vazia, e retorna o datagrama retirado caso contrario
Datagrama* Fila::dequeue(){
    if(this->isEmpty()){
        return NULL;
    } else {
        // TIRAR O DATAGRAMA
        Datagrama* datagramaRetirado = this->vetorDeDatagramas[this->inicio];
        if(this->inicio == this->tamanho){
            this->inicio = 0;
        } else {
            this->inicio += 1;
        }
        return datagramaRetirado;
    }
}

void Fila::imprimir(){
    cout << endl << "== FILA IMPRIMIR ==" << endl << endl;
    cout << "\ttamanho disponivel - " << this->tamanho << endl << endl;
    cout << "\tinicio - " << this->inicio << endl << endl;
    cout << "\tfim - " << this->fim << endl << endl;
    cout <<  "\tFila, na ordem:" << endl << endl;

    for(int i = this->inicio; i != (this->fim);){

        cout <<"\tPosicao " << i << " no vetor: ";
        vetorDeDatagramas[i]->imprimir();

        if(i == this->tamanho){
            i = 0;
        }
        else{
            i++;
        }
    }
    cout << endl << "== FIM FILA IMPRIMIR ==" << endl << endl;

}
