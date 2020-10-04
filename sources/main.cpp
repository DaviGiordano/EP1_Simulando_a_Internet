#include <iostream>
#include <string>
#include "Datagrama.h"
#include "Fila.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"

using namespace std;


main(int argc, char **argv){



    //Datagramas dummys
    Datagrama *pacotePrimeiro = new Datagrama(1,3,7,"DadoUM");

    Datagrama *pacoteSegundo = new Datagrama(2,4,1,"DadoDOIS");

    Datagrama *pacoteTerceiro = new Datagrama(5,2,2,"DadoTRES");

    Datagrama *pacoteQuarto = new Datagrama (4,5,2,"DadoQUATRO");

    Datagrama *pacoteQuinto = new Datagrama (3,6,5,"DadoCINCO");

    Roteador *roteadorPrimeiro= new Roteador(1);
    Roteador *roteadorSegundo = new Roteador(2);
    Roteador *roteadorTerceiro = new Roteador(3);
    Roteador *roteadorQuarto = new Roteador(4);


    roteadorPrimeiro->getTabela()->setPadrao(roteadorSegundo);
    roteadorPrimeiro->getTabela()->mapear(4,roteadorQuarto);

    roteadorSegundo->getTabela()->setPadrao(roteadorQuarto);
    roteadorSegundo->getTabela()->mapear(3,roteadorTerceiro);

    roteadorPrimeiro->receber(pacotePrimeiro);
    roteadorPrimeiro->receber(pacoteSegundo);

    roteadorSegundo->receber(pacoteTerceiro);
    roteadorSegundo->receber(pacoteQuarto);

    roteadorPrimeiro->processar();
    roteadorPrimeiro->processar();

    roteadorSegundo->processar();
    roteadorSegundo->processar();

    roteadorSegundo->imprimir();
    roteadorPrimeiro->imprimir();



}
