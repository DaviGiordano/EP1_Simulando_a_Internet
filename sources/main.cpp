#include <iostream>
#include <string>
#include "Datagrama.h"
#include "Datagrama.cpp"
#include "Fila.h"
#include "Fila.cpp"
#include "Roteador.h"
#include "Roteador.cpp"
#include "TabelaDeRepasse.h"
#include "TabelaDeRepasse.cpp"
#include "Rede.h"
#include "Rede.cpp"

using namespace std;


main(int argc, char **argv){
    int vetor[] = {1, 2, 3, 4};

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

    vetorDeRoteadores[0] = roteadorPrimeiro;
    vetorDeRoteadores[1] = roteadorSegundo;
    vetorDeRoteadores[2] = roteadorTerceiro;
    vetorDeRoteadores[3] = roteadorQuarto;
    vetorDeRoteadores[4] = roteadorQuinto;
    vetorDeRoteadores[5] = roteadorSexto;

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
