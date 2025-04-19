#include "Veiculo.h"

Veiculo::Veiculo() : Unidade("Veiculo") { 
    poderAtaque = 40 + std::rand() % (80 - 40 + 1); // 40 a 80
    blindagem = 30 + std::rand() % (70 - 30 + 1); // 30 a 70
    potenciaDeFogo = 20 + std::rand() % (50 - 20 + 1); // 20 a 50
}

// Retorna um num inteiro de 0 a 100 com o poder de ataque dessa unidade
int Veiculo::getPoderAtaque() const {
    return ((poderAtaque * 5) + (blindagem * 4) + (potenciaDeFogo * 1)) / 10 + (std::rand() % 10);
}


