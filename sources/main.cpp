#include <iostream>
#include <string>
#include "Datagrama.h"
#include "Fila.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include "Rede.h"

using namespace std;

#define NUMERO_DE_ROTEADORES_NA_REDE 6
//Devolve um roteador com o endereco especificado
Roteador* criarRoteador(int endereco);
void definirPadrao(Roteador* rBase, Roteador* rPadrao);
void definirAdjacente(Roteador* rBase, int endereco, Roteador* radjacente);
void deletador(Roteador *vetorDeRoteadores[], int quantidadeDeRoteadores, Rede *rede);
void telaDeEnviarDatagrama(Rede *rede);
void enviarDatagrama(int enderecoOrigem, int enderecoDestino, int ttl, string dado, Rede *rede);
void imprimeMensagemDeErro();
void telaDePassarTempo(Rede *rede);
int telaInicial();

main(int argc, char **argv){

    //criar os roteadores
    Roteador* r1 = criarRoteador(1);
    Roteador* r2 = criarRoteador(2);
    Roteador* r3 = criarRoteador(3);
    Roteador* r4 = criarRoteador(4);
    Roteador* r5 = criarRoteador(5);
    Roteador* r6 = criarRoteador(6);

    //definir os roteadores padr�o
    definirPadrao(r1,r2);
    definirPadrao(r2,r5);
    definirPadrao(r3,r2);
    definirPadrao(r4,r5);
    definirPadrao(r5,r2);
    definirPadrao(r6,r5);

    //definir os roteadores Ajacentes
    definirAdjacente(r1,4,r4);
    definirAdjacente(r2,1,r1);
    definirAdjacente(r2,3,r3);
    definirAdjacente(r3,6,r6);
    definirAdjacente(r4,1,r1);
    definirAdjacente(r5,4,r4);
    definirAdjacente(r5,6,r6);
    definirAdjacente(r6,3,r3);

    //criar vetor de roteadores
    Roteador** vetorDeRoteadores = new Roteador*[6];

    //preencher vetor de roteadores
    vetorDeRoteadores[0] = r1;
    vetorDeRoteadores[1] = r2;
    vetorDeRoteadores[2] = r3;
    vetorDeRoteadores[3] = r4;
    vetorDeRoteadores[4] = r5;
    vetorDeRoteadores[5] = r6;

    //r1->imprimir();
    //criar rede com tais roteadores
    Rede* rede = new Rede(vetorDeRoteadores, 6);

    int tela;
    do {
        tela = telaInicial();
        switch (tela)
        {
        case 1:
            // ENVIAR O DATAGRAMA
            telaDeEnviarDatagrama(rede);
            break;
        case 2:
            telaDePassarTempo(rede);
            break;
        default:
            break;
        }
    } while (tela != 3);

    deletador(vetorDeRoteadores, 6, rede);

    return 0;
}

void deletador(Roteador *vetorDeRoteadores[], int quantidadeDeRoteadores, Rede *rede) {

    for (int i = 0; i < quantidadeDeRoteadores; i++) {
        delete vetorDeRoteadores[i];
    }

    delete[] vetorDeRoteadores;
    delete rede;
}

Roteador* criarRoteador(int endereco){
    return new Roteador(endereco);
}

void definirPadrao(Roteador* rBase, Roteador* rPadrao){
    rBase->getTabela()->setPadrao(rPadrao);
}

void definirAdjacente(Roteador* rBase, int endereco, Roteador* rAdjacente){
    rBase->getTabela()->mapear(endereco, rAdjacente);
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
    //cout << endl;

    cout << "Endereco de destino: ";
    cin >> enderecoRoteadorDestino;
    //cout << endl;

    cout << "TTL: ";
    cin >> ttl;
    //cout << endl;

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


    for (instante = 1; instante <= tempo; instante++) {
        cout << "Instante " << instante << endl << "---" << endl;
        rede->passarTempo();
    }

}


