#ifndef CAMPANHA_H
#define CAMPANHA_H

#include "/home/usuario/Tp1POO/Exercito/Exercito.h"
#include "/home/usuario/Tp1POO/Batalha/Batalha.h"
#include "/home/usuario/Tp1POO/Batalha/Date.h"
#include <vector>
#include <iostream>
#include <fstream> 

class Campanha {
private:
    // Lista de batalhas realizadas
    std::vector<Batalha> batalhas; 
    
    
    Exercito& exercitoA;
    Exercito& exercitoB;
    Date dataCampanha;  

public:
    Campanha(Exercito& exercitoA, Exercito& exercitoB);

    void simularBatalhas(Exercito* exercitoA, Exercito* exercitoB, int numBatalhas);
    
    void gerarTabelaDePosicoes() const;
    
    void mostrarExercitoMaisDestrutivo() const;

    void adicionarBatalha(const Batalha& batalha);

    void mostrarResultados() const;

    void mostrarDataCampanha() const;

};

#endif




