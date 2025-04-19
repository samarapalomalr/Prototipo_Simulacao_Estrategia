#include "Aeronave.h"

Aeronave::Aeronave() : Unidade("Aeronave") {  
    poderAtaque = 50 + std::rand() % (90 - 50 + 1); // 50 a 90
    manobrabilidade = 30 + std::rand() % (70 - 30 + 1); // 30 a 70
    alcance = 20 + std::rand() % (50 - 20 + 1); // 20 a 50
}

// Retorna um num inteiro de 0 a 100 com o poder de ataque dessa unidade
int Aeronave::getPoderAtaque() const {
    return ((poderAtaque * 5) + (manobrabilidade * 3) + (alcance * 2)) / 10 + (std::rand() % 10);
}


