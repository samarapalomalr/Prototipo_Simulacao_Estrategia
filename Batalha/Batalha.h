#ifndef BATALHA_H
#define BATALHA_H

#include <iostream>
#include "/home/usuario/Tp1POO/Exercito/Exercito.h"
#include "Date.h"

class Batalha {
private:
    // Data da batalha
    Date data;

    Exercito& exercitoA;
    Exercito& exercitoB;

    int resultadoA;
    int resultadoB;

public:
    Batalha(const Date& data, Exercito& exercitoA, Exercito& exercitoB);

    int ataqueExercitoA() const;
    int ataqueExercitoB() const;

    std::string getResultado() const;

    int calcularPoderTotal(const Exercito& exercito) const;

    void calcularResultados();

    const Exercito& getExercitoA() const;
    const Exercito& getExercitoB() const;

    const Exercito* getVencedor() const;
};

#endif 







