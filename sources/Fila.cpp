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

bool Fila::enqueue(Datagrama *d) {
        // condicao para fila cheia
    if ( (this->inicio == 0 && this->fim == this->tamanho + 1 ) || this->fim + 1 == this->inicio) {
        // caso cheia, retorna falso
        return false;
    } else {
        // caso contrario, adiciona datagrama no fim da fila
        this->vetorDeDatagramas[this->fim] = d;

        // e atualiza o valor de fim
        if (this->fim == this->tamanho + 1) {
            this->fim = 0;
        } else  {
            this->fim += 1;
        }
        return true;
    }
}

bool Fila::isEmpty() {
    return this->inicio == this->fim;
}

Datagrama* Fila::dequeue(){
    if(this->isEmpty()){
        return NULL;
    } else {

        Datagrama* aux = this->vetorDeDatagramas[this->inicio];
        if(this->inicio == this->tamanho + 1){
            this->inicio = 0;
        } else {
            this->inicio += 1;
        }
        return aux;
    }
}
//!! Ainda tenho que fazer "dar a volta" quando necessário
void Fila::imprimir(){
    cout << "tamanho - " << this->tamanho << endl << endl;
    cout << "inicio - " << this->inicio << endl << endl;
    cout << "fim - " << this->fim << endl << endl;
    cout <<  "Fila, na ordem:" << endl << endl;

    for(int i = this->inicio; i != (this->fim - 1);){

        cout <<"Posicao no vetor: " << i << endl;
        vetorDeDatagramas[i]->imprimir();

        if(i == this->tamanho){
            i = 0;
        }
        else{
            i++;
        }
    }

    /*
    int i = this->inicio;
    while(i != this->fim){
        if(i == this->tamanho){
            i = 0;
        }else{ i++; }
        cout <<"Posição no vetor: " << i << endl;
        vetorDeDatagramas[i]->imprimir();
    }
    cout<< endl;
    */
}
