#ifndef UNIDADE_H
#define UNIDADE_H

#include <string>

// Classe base para todas as unidades
class Unidade {
protected:
    int poderAtaque; 
    int destruicoes; 
    std::string nome;

public:
    explicit Unidade(const std::string& nome);  

    virtual ~Unidade(); 
    
    // Método virtual puro para obter o poder de ataque da unidade
    virtual int getPoderAtaque() const = 0;

    void somaDestruicao();

    int getDestruicoes() const;

    std::string getNome() const;  
};

#endif
