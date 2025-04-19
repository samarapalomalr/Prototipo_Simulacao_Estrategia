#include "Campanha.h"
#include <iostream>
#include <fstream> 
#include <ctime>

// Construtor
Campanha::Campanha(Exercito& exercitoA, Exercito& exercitoB)
    : exercitoA(exercitoA), exercitoB(exercitoB) {
        std::srand(static_cast<unsigned>(std::time(0)));
    // Data aleatória em 2025
    dataCampanha = Date(1 + std::rand() % 30, 1 + std::rand() % 12, 2025); 
    }

// Simula batalha de ida e volta entre os dois exércitos
void Campanha::simularBatalhas(Exercito* exercitoA, Exercito* exercitoB, int numBatalhas) {
    // Garante que os contadores de vitórias sejam zerados antes do início da simulação
    exercitoA->zerarResultados();
    exercitoB->zerarResultados();

    Date dataBatalha;
    for (int i = 0; i < numBatalhas; ++i) {
        // Batalha de ida
        Batalha batalhaIda(dataBatalha, *exercitoA, *exercitoB);
        batalhaIda.calcularResultados();
        adicionarBatalha(batalhaIda);

        // Atualiza os contadores com base no vencedor
        if (batalhaIda.getVencedor() == exercitoA) {
            exercitoA->registrarResultado('V');
            exercitoB->registrarResultado('D');
        } else if (batalhaIda.getVencedor() == exercitoB) {
            exercitoB->registrarResultado('V');
            exercitoA->registrarResultado('D');
        } else {
            exercitoA->registrarResultado('E');
            exercitoB->registrarResultado('E');
        }

        // Batalha de volta
        Batalha batalhaVolta(dataBatalha, *exercitoB, *exercitoA);
        batalhaVolta.calcularResultados();
        adicionarBatalha(batalhaVolta);

        // Atualiza os contadores com base no vencedor
        if (batalhaVolta.getVencedor() == exercitoA) {
            exercitoA->registrarResultado('V');
            exercitoB->registrarResultado('D');
        } else if (batalhaVolta.getVencedor() == exercitoB) {
            exercitoB->registrarResultado('V');
            exercitoA->registrarResultado('D');
        } else {
            exercitoA->registrarResultado('E');
            exercitoB->registrarResultado('E');
        }
    }

    std::cout << std::endl << " *** " << numBatalhas * 2 << " batalhas simuladas (ida e volta) *** " << std::endl; 
}

// Geração de relatório da campanha
void Campanha::gerarTabelaDePosicoes() const {
    int vitoriasA = 0, vitoriasB = 0;

    // Contando as vitórias de cada exército
    for (const auto& batalha : batalhas) {
        if (batalha.getVencedor() == &exercitoA) {
            vitoriasA++;
        } else if (batalha.getVencedor() == &exercitoB) {
            vitoriasB++;
        }
    }

    // Determinando o número da próxima campanha
    static int numeroBatalha = 1;

    // Abrindo o arquivo em modo append (adicionar sem sobrescrever)
    std::ofstream arquivo("tabela_posicoes.txt", std::ios::app);
    
    // Verificando se o arquivo foi aberto corretamente
    if (arquivo.is_open()) {
        arquivo << "\n======================================================================\n";
        arquivo << "BATALHA " << numeroBatalha << "\n";
        arquivo << "=======================================================================\n";
        arquivo << exercitoA.getNome() << " venceu " << vitoriasA << " batalhas.\n";
        arquivo << exercitoB.getNome() << " venceu " << vitoriasB << " batalhas.\n";

        arquivo << "\n";
        // Determinando o vencedor da campanha
        if (vitoriasA > vitoriasB) {
            arquivo  << exercitoA.getNome() << " é o vencedor da campanha! \n";
        } else if (vitoriasB > vitoriasA) {
            arquivo  << exercitoB.getNome() << " é o vencedor da campanha! \n";
        } else {
            arquivo << "A campanha terminou empatada!\n";
        }

        arquivo.close(); 
    } else {
        std::cout << std::endl << "Erro ao abrir o arquivo de saída!" << std::endl;
    }
    numeroBatalha++;
}

void Campanha::mostrarExercitoMaisDestrutivo() const {
    int vitoriasA = 0, vitoriasB = 0;

    // Contando as vitórias de cada exército
    for (const auto& batalha : batalhas) {
        if (batalha.getVencedor() == &exercitoA) {
            vitoriasA++;
        } else if (batalha.getVencedor() == &exercitoB) {
            vitoriasB++;
        }
    }

    // Determinando o vencedor da campanha
    if (vitoriasA > vitoriasB) {
        std::cout << std::endl << "\n" << exercitoA.getNome() << " causou mais destruição na campanha!" << std::endl;
    } else if (vitoriasB > vitoriasA) {
        std::cout << std::endl << "\n" << exercitoB.getNome() << " causou mais destruição na campanha!" << std::endl;
    } else {
        std::cout << "\n\nAmbos os exercitos ganharam umas das batalhas de ida e volta \n";
    }
}


// Adiciona uma batalha ao vetor de batalhas
void Campanha::adicionarBatalha(const Batalha& batalha) {
    batalhas.push_back(batalha);
}

// Mostra os resultados das batalhas registradas
void Campanha::mostrarResultados() const {
    std::cout << "*** Resultado da batalha de ida e de volta ***" << std::endl;
    for (const auto& batalha : batalhas) {
        std::cout << std::endl << batalha.getResultado();
    }
}

// Exibe a data da campanha
void Campanha::mostrarDataCampanha() const {
    std::cout << "Data da Campanha: " << dataCampanha.FormatarData() << std::endl;
}










