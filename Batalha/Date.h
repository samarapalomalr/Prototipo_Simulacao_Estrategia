#ifndef DATE_H
#define DATE_H

#include <string>
#include <random>
#include <stdexcept>

class Date {
private:
    int dia;
    int mes;
    int ano;

    // Método para validar se a data é válida
    bool validarData() const;

public:
    Date();
    Date(int dia, int mes, int ano); 

    void AvancarDias(int dias); 
    void RandomizarData(); 
    void setData(int novoDia, int novoMes, int novoAno); 
    std::string FormatarData() const; 
};

#endif





