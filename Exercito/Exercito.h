#ifndef EXERCITO_H
#define EXERCITO_H

#include <string>
#include <vector>
#include <memory> // Para std::unique_ptr
#include "/home/usuario/Tp1POO/Unidades/Unidade.h"
#include "/home/usuario/Tp1POO/Unidades/Infantaria.h"
#include "/home/usuario/Tp1POO/Unidades/Veiculo.h"
#include "/home/usuario/Tp1POO/Unidades/Aeronave.h"

class Exercito {
private:
    std::string nome;

    // Lista de unidades 
    std::vector<std::unique_ptr<Unidade>> unidades;

    // Contadores
    int vitorias;
    int empates;
    int derrotas;

    void adicionarUnidade();

public:
    // Construtor e destrutor padrão
    Exercito(const std::string& nome);
    ~Exercito() = default;

    std::string getResultados() const;

    void imprimeUnidades() const;

    // Registra o resultado de uma batalha
    void registrarResultado(char resultado);

    // Reseta as contagens de vitórias, empates e derrotas
    void zerarResultados(); 

    const std::vector<std::unique_ptr<Unidade>>& getUnidades() const;
    std::string getNome() const;
};

#endif





