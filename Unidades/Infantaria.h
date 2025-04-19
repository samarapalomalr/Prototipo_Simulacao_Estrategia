#ifndef INFANTARIA_H
#define INFANTARIA_H

#include "Unidade.h"

// Classe derivada representando uma unidade 
class Infantaria : public Unidade {
private:
    int forca;
    int velocidade;

public:
    Infantaria(); 

    // Retorna o poder de ataque da unidade de infantaria
    int getPoderAtaque() const override;
};

#endif


