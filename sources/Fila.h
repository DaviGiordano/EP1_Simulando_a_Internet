#ifndef FILA_H

#define FILA_H
#include "Datagrama.h"
class Fila
{
private:
    int inicio = 0;
    int fim = 0;
    int tamanho;
    Datagrama **vetorDeDatagramas;
public:
    Fila(int tamanho);
    ~Fila();

    bool enqueue(Datagrama *d);
    Datagrama *dequeue();
    bool isEmpty();

    void imprimir();
};



#endif