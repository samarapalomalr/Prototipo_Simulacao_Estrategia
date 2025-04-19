#ifndef AERONAVE_H
#define AERONAVE_H

#include "Unidade.h"

// Classe derivada representando uma unidade
class Aeronave : public Unidade {
private:
    int manobrabilidade;
    int alcance;

public:
    Aeronave(); 
    
    // Retorna o poder de ataque da aeronave
    int getPoderAtaque() const override;
};

#endif
