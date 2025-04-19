#include "Date.h"

Date::Date() : dia(1), mes(1), ano(1970) {}

Date::Date(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {
    if (!validarData()) {
        throw std::invalid_argument("Data inválida");
    }
}

// Valida a data
bool Date::validarData() const {
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > 31) return false;

    if (mes == 2) {
        if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
            if (dia > 29) return false; // Ano bissexto
        } else if (dia > 28) return false; // Não bissexto
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return false;

    return true;
}

// Avança a data
void Date::AvancarDias(int dias) {
    while (dias > 0) {
        dia += 1;
        if (!validarData()) {
            dia -= 1;
            break;
        }
        dias--;
    }
}

// Gera uma data aleatória
void Date::RandomizarData() {
    std::random_device rd;
    std::uniform_int_distribution<int> distDia(1, 31);
    std::uniform_int_distribution<int> distMes(1, 12);
    std::uniform_int_distribution<int> distAno(1900, 2100);

    do {
        dia = distDia(rd);
        mes = distMes(rd);
        ano = distAno(rd);
    } while (!validarData());
}

// Seta a data
void Date::setData(int novoDia, int novoMes, int novoAno) {
    dia = novoDia;
    mes = novoMes;
    ano = novoAno;

    if (!validarData()) {
        throw std::invalid_argument("Data inválida");
    }
}

// Formata a data
std::string Date::FormatarData() const {
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(ano);
}





