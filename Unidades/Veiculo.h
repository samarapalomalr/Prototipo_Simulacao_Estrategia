#ifndef VEICULO_H
#define VEICULO_H

#include "Unidade.h"

// Classe derivada representando uma unidade
class Veiculo : public Unidade {
private:
    int blindagem;
    int potenciaDeFogo;

public:
    Veiculo();

    // Retorna o poder de ataque do veículo
    int getPoderAtaque() const override;
};

#endif
