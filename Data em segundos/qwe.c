#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tm pegarDataSistema();

int calcularIdade(struct tm *dataAtual, struct tm *dataNascimento);

int main() {
    struct tm dataAtual = pegarDataSistema();

    struct tm dataNascimento = pegarDataSistema();
    dataNascimento.tm_mday = 8;     // Preencha esse campo
    dataNascimento.tm_mon = 10;      // Preencha esse campo
    dataNascimento.tm_year = 1996;     // Preencha esse campo

    int idade = calcularIdade(&dataAtual, &dataNascimento);

    printf("Você tem %i anos de idade. \n", idade);
    return EXIT_SUCCESS;
}

struct tm pegarDataSistema() {
    time_t temp = time(NULL);

    struct tm dataAtual = *localtime(&temp);
    dataAtual.tm_year += 1900;  // Compensa a forma como é contado o ano

    return dataAtual;
}

int calcularIdade(struct tm *dataAtual, struct tm *dataNascimento) {
    int idade = dataAtual->tm_year - dataNascimento->tm_year;

    /*
     * Verifica as condições para determinar se já fez aniversário.
     * Caso não tenha feito ainda, decrementamos a idade para compensar.
     */
    if (dataAtual->tm_mon < dataNascimento->tm_mon) {
        idade -= 1;
    } else if (dataAtual->tm_mon == dataNascimento->tm_mon) {
        if (dataAtual->tm_mday < dataNascimento->tm_mday) {
            idade -= 1;
        }
    }

    return idade;
} 