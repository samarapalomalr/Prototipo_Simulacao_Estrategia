#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Exercito/Exercito.h"
#include "Batalha/Batalha.h"
#include "Batalha/Date.h"
#include "Campanha/Campanha.h"

int main() {
    // Inicializa o gerador de números aleatórios
    std::srand(static_cast<unsigned>(std::time(0))); 
    Date dataBatalha(1, 1, 2025);

    // Criando os exércitos
    Exercito exercitoA("Exercito A");
    Exercito exercitoB("Exercito B");
    Exercito exercitoC("Exercito C");

    
    Campanha campanha1(exercitoA, exercitoB);
    Campanha campanha2(exercitoB, exercitoC);
    Campanha campanha3(exercitoA, exercitoC);

    std::cout << "\n ======== CAMPANHA SENDO INICIALIZADA ======== \n";
    campanha1.mostrarDataCampanha();

    // Exibindo unidades de cada exército para confirmar inicialização correta
    std::cout << "\n * Unidades do " << exercitoA.getNome() << " *\n";
    exercitoA.imprimeUnidades();

    std::cout << "\n * Unidades do " << exercitoB.getNome() << " *\n";
    exercitoB.imprimeUnidades();

    std::cout << "\n * Unidades do " << exercitoC.getNome() << " *\n";
    exercitoC.imprimeUnidades();

    // === BATALHA 1: Exército A vs Exército B ===
    std::cout << "\n=== BATALHA 1: " << exercitoA.getNome() << " vs " << exercitoB.getNome() << " ===\n";
    campanha1.simularBatalhas(&exercitoA, &exercitoB, 1);
    std::cout <<"\n";
    campanha1.mostrarResultados();
    campanha1.mostrarExercitoMaisDestrutivo();
    campanha1.gerarTabelaDePosicoes();

    // === BATALHA 2: Exército B vs Exército C ===
    std::cout << "\n=== BATALHA 2: " << exercitoB.getNome() << " vs " << exercitoC.getNome() << " ===\n";
    campanha2.simularBatalhas(&exercitoB, &exercitoC, 1);
    std::cout <<"\n";
    campanha2.mostrarResultados();
    campanha2.mostrarExercitoMaisDestrutivo();
    campanha2.gerarTabelaDePosicoes();

    // === BATALHA 3: Exército A vs Exército C ===
    std::cout << "\n=== BATALHA 3: " << exercitoA.getNome() << " vs " << exercitoC.getNome() << " ===\n";
    campanha3.simularBatalhas(&exercitoA, &exercitoC, 1);
    std::cout <<"\n";
    campanha3.mostrarResultados();
    campanha3.mostrarExercitoMaisDestrutivo();
    campanha3.gerarTabelaDePosicoes();

    std::cout << "\n=== Campeonato Concluído! Confira o arquivo tabela_posicoes.txt para os resultados ===\n";

    return 0;
}


