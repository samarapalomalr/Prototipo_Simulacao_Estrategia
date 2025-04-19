#include "Batalha.h"


// Construtor que inicializa a batalha com uma data e dois exércitos
Batalha::Batalha(const Date& data, Exercito& exercitoA, Exercito& exercitoB)
    : data(data), exercitoA(exercitoA), exercitoB(exercitoB), resultadoA(0), resultadoB(0) {}


// Retorna o resultado do ataque do Exército A e do Exército B
int Batalha::ataqueExercitoA() const {
    return resultadoA;
}

int Batalha::ataqueExercitoB() const {
    return resultadoB;
}

// Retorna uma string representando o resultado da batalha
std::string Batalha::getResultado() const {
    return exercitoA.getNome() + " " + std::to_string(resultadoA) + 
           " x " + std::to_string(resultadoB) + " " + exercitoB.getNome();
}

// Calcula o poder total de um exército somando o poder de ataque de todas as unidades
int Batalha::calcularPoderTotal(const Exercito& exercito) const {
    int poderTotal = 0;
    for (const auto& unidade : exercito.getUnidades()) {
        poderTotal += unidade->getPoderAtaque();
    }
    return poderTotal;
}

// Calcula os resultados da batalha e atualiza os estados dos exércitos
void Batalha::calcularResultados() {
    // Reinicia os contadores de resultados antes de calcular a nova batalha
    exercitoA.zerarResultados();
    exercitoB.zerarResultados();

    resultadoA = calcularPoderTotal(exercitoA);
    resultadoB = calcularPoderTotal(exercitoB);

    if (resultadoA > resultadoB) { // Exército A venceu
        exercitoA.registrarResultado('V');
        exercitoB.registrarResultado('D');
        for (const auto& unidade : exercitoB.getUnidades()) {
            unidade->somaDestruicao();
        }
    } else if (resultadoB > resultadoA) { // Exército B venceu
        exercitoB.registrarResultado('V');
        exercitoA.registrarResultado('D');
        for (const auto& unidade : exercitoA.getUnidades()) {
            unidade->somaDestruicao();
        }
    } else { // Empate
        exercitoA.registrarResultado('E');
        exercitoB.registrarResultado('E');
    }
}

// Retorna uma referência ao Exército A e ao Exército B
const Exercito& Batalha::getExercitoA() const {
    return exercitoA;
}

const Exercito& Batalha::getExercitoB() const {
    return exercitoB;
}

// Retorna um ponteiro para o exército vencedor ou nullptr em caso de empate
const Exercito* Batalha::getVencedor() const {
    if (resultadoA > resultadoB) {
        return &exercitoA;
    } else if (resultadoB > resultadoA) {
        return &exercitoB;
    }
    return nullptr; // Empate
}









