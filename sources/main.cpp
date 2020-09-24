#include <iostream>
#include <string>
#include "Datagrama.h"
#include "Fila.h"
using namespace std;

//no vídeo sobre construtores e destrutures ele adicionou esses parâmetros. Você sabe o que são?
main(int argc, char **argv){


    //TESTANDO MÉTODO bool Datagrama::ativo

    Datagrama *pacotePrimeiro = new Datagrama(1,2,78,"oi");
    Datagrama *pacoteSegundo = new Datagrama(3,4,0,"tchau");
    Datagrama *pacoteTerceiro = new Datagrama(2,7,5,"Feliz");
    Datagrama *pacoteQuarto = new Datagrama (6,7,1,"Natal");
    //cout << "Pacote Ativo: " << endl;
    //pacoteAtivo->imprimir();
    //cout << "Pacote Inativo: " <<endl;
   // pacoteInativo->imprimir();

    Fila *filaTeste = new Fila(3);

    cout << "teste 1" << endl;
    filaTeste->enqueue(pacotePrimeiro);
    filaTeste->enqueue(pacoteSegundo);
    filaTeste->enqueue(pacoteTerceiro);
 //PRECISAMOS testarrr maiss!!
    filaTeste->enqueue(pacoteQuarto);
    filaTeste->imprimir();

}
