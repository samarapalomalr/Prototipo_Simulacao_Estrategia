#include "Unidade.h"
#include <cstdlib>
#include <ctime>
#include <random>

// Construtor parametrizado que inicializa a unidade com um nome
Unidade::Unidade(const std::string& nome) 
    : destruicoes(0), nome(nome) {
    std::srand(std::time(0));  // Inicializa a semente do gerador de números aleatórios
}

// Destrutor virtual para permitir polimorfismo
Unidade::~Unidade() {}

// Incrementa o número de destruições realizadas pela unidade
void Unidade::somaDestruicao() {
    destruicoes++;
}

// Retorna o número de destruições realizadas
int Unidade::getDestruicoes() const {
    return destruicoes;
}

// Retorna o nome da unidade
std::string Unidade::getNome() const {
    return nome;
}


