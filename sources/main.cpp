#include <iostream>
#include <string>
#include "Datagrama.h"
#include "Fila.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include "Rede.h"

using namespace std;


main(int argc, char **argv){

    Roteador *roteadorPrimeiro= new Roteador(1);
    Roteador *roteadorSegundo = new Roteador(2);
    Roteador *roteadorTerceiro = new Roteador(3);
    Roteador *roteadorQuarto = new Roteador(4);
    Roteador *roteadorQuinto = new Roteador(5);
    Roteador *roteadorSexto = new Roteador(6);

    roteadorPrimeiro->getTabela()->mapear(4,roteadorQuarto);
    roteadorPrimeiro->getTabela()->setPadrao(roteadorSegundo);


    roteadorSegundo->getTabela()->mapear(1,roteadorPrimeiro);
    roteadorSegundo->getTabela()->mapear(3,roteadorTerceiro);
    roteadorSegundo->getTabela()->setPadrao(roteadorQuinto);


    roteadorTerceiro->getTabela()->mapear(6,roteadorSexto);
    roteadorTerceiro->getTabela()->setPadrao(roteadorSegundo);


    roteadorQuarto->getTabela()->mapear(1,roteadorPrimeiro);
    roteadorQuarto->getTabela()->setPadrao(roteadorQuinto);


    roteadorQuinto->getTabela()->mapear(4,roteadorQuarto);
    roteadorQuinto->getTabela()->mapear(6,roteadorSexto);
    roteadorQuinto->getTabela()->setPadrao(roteadorSegundo);


    roteadorSexto->getTabela()->mapear(3,roteadorTerceiro);
    roteadorSexto->getTabela()->setPadrao(roteadorQuinto);


    Roteador** vetorDeRoteadores = new Roteador*[6];

    vetorDeRoteadores[1] = roteadorPrimeiro;
    vetorDeRoteadores[2] = roteadorSegundo;
    vetorDeRoteadores[3] = roteadorTerceiro;
    vetorDeRoteadores[4] = roteadorQuarto;
    vetorDeRoteadores[5] = roteadorQuinto;
    vetorDeRoteadores[6] = roteadorSexto;

    Rede* rede = new Rede(vetorDeRoteadores, 6);

    rede->enviar("DadoUm", roteadorPrimeiro, 4, 3);
    //rede->enviar("DadoDois", roteadorSegundo, 2, 3);
    //rede->enviar("DadoTres", roteadorTerceiro, 1, 3);
    //rede->enviar("DadoQuatro", roteadorQuarto, 5, 3);
    //rede->enviar("DadoCinco", roteadorQuinto, 1, 3);
    //rede->enviar("DadoSeis", roteadorSexto, 4, 3);
    rede->passarTempo();
    rede->imprimir(1);


}
