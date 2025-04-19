#include "Exercito.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

// Inicializa o exército e adiciona unidades
Exercito::Exercito(const std::string& nome)
    : nome(nome), vitorias(0), empates(0), derrotas(0) {
    
    // Semente do gerador de números aleatórios baseada no nome
    std::srand(static_cast<unsigned>(std::time(0)) + nome.length());

    adicionarUnidade();
}

// Inicializa cinco unidades
void Exercito::adicionarUnidade() {
    std::srand(static_cast<unsigned>(std::time(0)));

    // Adiciona duas unidades de Infantaria
    for (int i = 0; i < 2; ++i) {
        unidades.push_back(std::make_unique<Infantaria>());
    }

    // Adiciona duas unidades de Veículo
    for (int i = 0; i < 2; ++i) {
        unidades.push_back(std::make_unique<Veiculo>());
    }

    // Adiciona uma unidade de Aeronave
    unidades.push_back(std::make_unique<Aeronave>());
}

// Retorna os resultados das batalhas do exército
std::string Exercito::getResultados() const {
    return "Vitórias: " + std::to_string(vitorias) +
           ", Empates: " + std::to_string(empates) +
           ", Derrotas: " + std::to_string(derrotas);
}

// Exibe informações sobre todas as unidades do exército
void Exercito::imprimeUnidades() const {
    
    for (size_t i = 0; i < unidades.size(); ++i) {
        std::cout << "Unidade " << i + 1
                  << " (" << unidades[i]->getNome() << ")" 
                  << std::endl;

    }
}

// Histórico de Batalhas
void Exercito::registrarResultado(char resultado) {
    switch (resultado) {
        case 'V': vitorias++; break;
        case 'E': empates++; break;
        case 'D': derrotas++; break;
        default:
            std::cerr << "Resultado inválido! Use 'V', 'E' ou 'D'." << std::endl;
    }
}

void Exercito::zerarResultados() {
    vitorias = 0;
    empates = 0;
    derrotas = 0;
}

// Retorna a lista de unidades do exército
const std::vector<std::unique_ptr<Unidade>>& Exercito::getUnidades() const {
    return unidades;
}

// Retorna o nome do exército
std::string Exercito::getNome() const {
    return nome;
}







