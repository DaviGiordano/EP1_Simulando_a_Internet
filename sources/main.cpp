#include <iostream>
#include <string>
#include "Datagrama.h"
#include "Fila.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include "Rede.h"

using namespace std;

#define NUMERO_DE_ROTEADORES_NA_REDE 6
void telaDeEnviarDatagrama(Rede *rede);
void enviarDatagrama(int enderecoOrigem, int enderecoDestino, int ttl, string dado, Rede *rede);
void imprimeMensagemDeErro();
void telaDePassarTempo(Rede *rede);
int telaInicial();

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

    vetorDeRoteadores[0] = roteadorPrimeiro;
    vetorDeRoteadores[1] = roteadorSegundo;
    vetorDeRoteadores[2] = roteadorTerceiro;
    vetorDeRoteadores[3] = roteadorQuarto;
    vetorDeRoteadores[4] = roteadorQuinto;
    vetorDeRoteadores[5] = roteadorSexto;

    Rede* rede = new Rede(vetorDeRoteadores, 6);

    int tela;
    do {
        tela = telaInicial();
        switch (tela)
        {
        case 1:
            /* ENVIAR O DATAGRAMA */
            telaDeEnviarDatagrama(rede);
            break;
        case 2:
            telaDePassarTempo(rede);
            break;
        default:
            break;
        }
    } while (tela != 3);
    return 0;
}

int telaInicial() {
    int tela;
    cout << "Simulador de Rede" << endl << 
        "---" << endl << 
        "1) Enviar um datagrama" << endl <<
        "2) Passar tempo" << endl <<
        "3) Sair" << endl <<
        "Escolha uma opcao: ";

    cin >> tela;
    cout << endl;

    return tela;
}

// Imprime as informacoes dessa tela e captura as entradas
void telaDeEnviarDatagrama(Rede *rede) {
    int enderecoRoteadorOrigem, enderecoRoteadorDestino, ttl;
    string mensagem;

    cout << "Endereco do roteador de origem: ";
    cin >> enderecoRoteadorOrigem;
    cout << endl;

    cout << "Endereco de destino: ";
    cin >> enderecoRoteadorDestino;
    cout << endl;

    cout << "TTL: ";
    cin >> ttl;
    cout << endl;

    cout << "Mensagem: ";
    cin >> mensagem;
    cout << endl;

    Roteador *origem = rede->getRoteador(enderecoRoteadorOrigem);

    // enviando o datagrama
    origem != NULL ? rede->enviar(mensagem, origem, enderecoRoteadorDestino, ttl) : imprimeMensagemDeErro();
}

void imprimeMensagemDeErro() {
    cout << "Erro: origem desconhecida";
}

void telaDePassarTempo(Rede *rede) {
    int tempo, instante;
    cout << "Quantidade de tempo: ";
    cin >> tempo;
    cout << endl;


    for (instante = 0; instante < tempo; instante++) {
        cout << "Instante " << instante << endl << "---" << endl;
        rede->passarTempo();
    }
    
}


