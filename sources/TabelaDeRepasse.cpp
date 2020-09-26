#include "TabelaDeRepasse.h"
#include "Roteador.h"
#include <iostream>
#define MAXIMO_TABELA 5

// CONSTRUTOR E DESTRUTOR ===================================================
// o construtor tem que alocar os atributos que sao vetores 



// GETTERS E SETTERS=========================================================


//OUTROS METODOS=============================================================

bool TabelaDeRepasse::mapear(int endereco, Roteador *adjacente) {
    if (this->quantidadeDeAdjacentes == MAXIMO_TABELA) {
        // JA FORAM MAPEADOS TODOS OS ENDERECOS POSSIVEIS NA TABELA  
        return false;
    } else {
        // FALTA GENTE PRA SER MAPEADA
        // procura se esse endereco ja ta na tabela
        for (int i = 0; i < this.quantidadeDeAdjacentes; i++) {
            if (this->enderecos[i] == endereco) {
                // neste caso, o endereco ja esta na tabela
                this->adjacentes[i] = adjacente; // trocando o roteador ligado ao endereco que ja esta na tabela
                return true ; // sai da funcao imediatamente sem incrementar o valor de this->quantidadeDeAdjacentes
            }
        }
        // Se sobreviveu a esse for significa que o endereco nao esta mapeado, vamos mapea-lo
        this->enderecos[this->quantidadeDeAdjacentes] = endereco; // Colocando na proxima posicao o endereco
        this->adjacentes[this->quantidadeDeAdjacentes] = adjacente; // Colocando na proxima posicao o roteador
        this->quantidadeDeAdjacentes += 1; // aumentando a quantidade de enderecados
        return true
    }
}