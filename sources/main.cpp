#include <iostream>
#include <string>
#include "Datagrama.h"
using namespace std;

//no v�deo sobre construtores e destrutures ele adicionou esses par�metros. Voc� sabe o que s�o?
main(int argc, char **argv){


    //TESTANDO M�TODO bool Datagrama::ativo

    Datagrama *pacoteAtivo = new Datagrama(1,2,78,"oi");
    Datagrama *pacoteInativo = new Datagrama(3,4,0,"tchau");
    cout << "Pacote Ativo: " << endl;
    pacoteAtivo->imprimir();
    cout << "Pacote Inativo: " <<endl;
    pacoteInativo->imprimir();


}
