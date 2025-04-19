#include "Infantaria.h"

Infantaria::Infantaria() : Unidade("Infantaria") {  
    poderAtaque = 30 + std::rand() % (60 - 30 + 1); // 30 a 60
    forca = 20 + std::rand() % (50 - 20 + 1); // 20 a 50
    velocidade = 10 + std::rand() % (40 - 10 + 1); // 10 a 40
}

// Retorna um num inteiro de 0 a 100 com o poder de ataque dessa unidade
int Infantaria::getPoderAtaque() const {
    return ((poderAtaque * 5) + (forca * 3) + (velocidade * 2)) / 10 + (std::rand() % 10);
}

