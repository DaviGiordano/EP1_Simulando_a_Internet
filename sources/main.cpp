#include <iostream>
#include <string>
#include "Datagrama.h"
#include "Fila.h"
using namespace std;

//no vídeo sobre construtores e destrutures ele adicionou esses parâmetros. Você sabe o que são?
main(int argc, char **argv){



    //Datagramas dummys
    Datagrama *pacotePrimeiro = new Datagrama(1,2,78,"Primeiro");
    Datagrama *pacoteSegundo = new Datagrama(3,4,0,"Segundo");
    Datagrama *pacoteTerceiro = new Datagrama(2,7,5,"Terceiro");
    Datagrama *pacoteQuarto = new Datagrama (6,7,1,"Quarto");
    Datagrama *pacoteQuinto = new Datagrama (9,10,5,"Quinto");
    //fila com tres posicoes validas
    Fila *filaTeste = new Fila(3);

    cout<< filaTeste->enqueue(pacotePrimeiro)<<endl;
    cout<<filaTeste->enqueue(pacoteSegundo)<<endl;
    cout<<filaTeste->enqueue(pacoteTerceiro)<<endl;
    cout<<filaTeste->enqueue(pacoteQuarto)<<endl; //FALSE esperado, deu true
    cout<<filaTeste->enqueue(pacoteQuinto)<<endl;
    /*problema: ele me deixou inserir um quarto pacote*/
    /*Não me deixou inserir o quinto, bom*/
    filaTeste->imprimir();

}
