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
// Roteador* criarRoteador(int endereco);
Roteador** criarRoteadores(int vetorDeEnderecos[], int quantidadeDeRoteadores);
// void definirPadrao(Roteador* rBase, Roteador* rPadrao);
void definirPadroes(Roteador *matrizDeRotBaseERotOrigem[][2], int i);
void definirAdjacentes(Roteador *matrizDeRotBaseERotAdjacente[][2], int i, int vetorEnderecos[]);
// void definirAdjacente(Roteador* rBase, int endereco, Roteador* radjacente);

void telaDeEnviarDatagrama(Rede *rede);
void enviarDatagrama(int enderecoOrigem, int enderecoDestino, int ttl, string dado, Rede *rede);
void imprimeMensagemDeErro();
void telaDePassarTempo(Rede *rede);
int telaInicial();

main(int argc, char **argv){

    //criar os roteadores
    int enderecos[] = {1, 2, 3, 4, 5, 6};
    
    // Roteador* r1 = criarRoteador(1);
    // Roteador* r2 = criarRoteador(2);
    // Roteador* r3 = criarRoteador(3);
    // Roteador* r4 = criarRoteador(4);
    // Roteador* r5 = criarRoteador(5);
    // Roteador* r6 = criarRoteador(6);
    Roteador** vetorDeRoteadores = criarRoteadores(enderecos, 6);

    //definir os roteadores padr�o
    // definirPadrao(r1,r2);
    // definirPadrao(r2,r5);
    // definirPadrao(r3,r2);
    // definirPadrao(r4,r5);
    // definirPadrao(r5,r2);
    // definirPadrao(r6,r5);

    Roteador *matrizDeMapeamentoDePadroes[6][2] = {
        vetorDeRoteadores[0], vetorDeRoteadores[1],
        vetorDeRoteadores[1], vetorDeRoteadores[4], 
        vetorDeRoteadores[2], vetorDeRoteadores[1], 
        vetorDeRoteadores[3], vetorDeRoteadores[4], 
        vetorDeRoteadores[4], vetorDeRoteadores[1], 
        vetorDeRoteadores[5], vetorDeRoteadores[4] 
    };

    definirPadroes(matrizDeMapeamentoDePadroes, 6);

    //definir os roteadores Ajacentes

    Roteador *matrizDeMapeamentoDeAdjacentes[8][2] = {
        vetorDeRoteadores[0], vetorDeRoteadores[3],
        vetorDeRoteadores[1], vetorDeRoteadores[0], 
        vetorDeRoteadores[1], vetorDeRoteadores[2], 
        vetorDeRoteadores[2], vetorDeRoteadores[5], 
        vetorDeRoteadores[3], vetorDeRoteadores[0], 
        vetorDeRoteadores[4], vetorDeRoteadores[3],
        vetorDeRoteadores[4], vetorDeRoteadores[5],
        vetorDeRoteadores[5], vetorDeRoteadores[2] 
    };

    int vetorDeEnderecosAdjacentes[] = {4, 1, 3, 6, 1, 4, 6, 3};

    definirAdjacentes(matrizDeMapeamentoDeAdjacentes, 8, vetorDeEnderecosAdjacentes);


    // definirAdjacente(r1,4,r4);
    // definirAdjacente(r2,1,r1);
    // definirAdjacente(r2,3,r3);
    // definirAdjacente(r3,6,r6);
    // definirAdjacente(r4,1,r1);
    // definirAdjacente(r5,4,r4);
    // definirAdjacente(r5,6,r6);
    // definirAdjacente(r6,3,r3);

    //criar vetor de roteadores

    //preencher vetor de roteadores
    // vetorDeRoteadores[0] = r1;
    // vetorDeRoteadores[1] = r2;
    // vetorDeRoteadores[2] = r3;
    // vetorDeRoteadores[3] = r4;
    // vetorDeRoteadores[4] = r5;
    // vetorDeRoteadores[5] = r6;

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
    return 0;

}

// Roteador* criarRoteador(int endereco){
//     return new Roteador(endereco);
// }

Roteador** criarRoteadores(int vetorDeEnderecos[], int quantidadeDeRoteadores) {
    Roteador** vetorDeRoteadores = new Roteador*[quantidadeDeRoteadores];
    for (int i = 0; i < quantidadeDeRoteadores; i++) {
        vetorDeRoteadores[i] = new Roteador(vetorDeEnderecos[i]);
    }

    return vetorDeRoteadores;
}

// void definirPadrao(Roteador* rBase, Roteador* rPadrao){
//     rBase->getTabela()->setPadrao(rPadrao);
// }

void definirPadroes(Roteador *matrizDeRotBaseERotOrigem[][2], int i) {
    for (int linha = 0; linha < i; linha++) {
        matrizDeRotBaseERotOrigem[linha][0]->getTabela()->setPadrao(matrizDeRotBaseERotOrigem[linha][1]);
    }
}

// void definirAdjacente(Roteador* rBase, int endereco, Roteador* rAdjacente){
//     rBase->getTabela()->mapear(endereco, rAdjacente);
// }

void definirAdjacentes(Roteador *matrizDeRotBaseERotAdjacente[][2], int i, int vetorEnderecos[]) {
    for (int linha = 0; linha < i; linha++) {
        matrizDeRotBaseERotAdjacente[linha][0]->getTabela()->mapear(vetorEnderecos[linha], matrizDeRotBaseERotAdjacente[linha][1]);
    }
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


