#include <iostream>
#include <string>
#include "Datagrama.h"
using namespace std;

//no vídeo sobre construtores e destrutures ele adicionou esses parâmetros. Você sabe o que são?
main(int argc, char **argv){


    //TESTANDO MÉTODO bool Datagrama::ativo

    Datagrama *pacoteAtivo = new Datagrama(1,2,78,"oi");
    Datagrama *pacoteInativo = new Datagrama(3,4,0,"tchau");
    cout << "Pacote Ativo: " << endl;
    pacoteAtivo->imprimir();
    cout << "Pacote Inativo: " <<endl;
    pacoteInativo->imprimir();


}
