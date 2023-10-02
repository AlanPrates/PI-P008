/*A seguinte expressão em C++ gera caracteres aleatórios no intervalo das
letras minúsculas: ‘a’ + rand()%(‘z’ - ‘a’). Utilizando esta
expressão implemente uma aplicação em que:
a. Gere duas strings de forma aleatória com 10 caracteres;
b. Transforme o primeiro caractere de cada string em maiúscula;
c. Imprima as strings em ordem alfabética;*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Função para gerar uma string aleatória de tamanho especificado
string gerarStringAleatoria(int tamanho) {
    string str;
    for (int i = 0; i < tamanho; i++) {
        char caractere = 'a' + rand() % 26; // Gera um caractere aleatório entre 'a' e 'z'
        str += caractere;
    }
    return str;
}

// Função para converter o primeiro caractere de uma string em maiúscula
void converterPrimeiroCaractereMaiuscula(string& str) {
    if (!str.empty()) {
        str[0] = toupper(str[0]);
    }
}

int main() {
    // Inicialize a semente para geração de números aleatórios com o tempo atual
    srand(static_cast<unsigned>(time(nullptr)));

    // Gere duas strings aleatórias
    string str1 = gerarStringAleatoria(10);
    string str2 = gerarStringAleatoria(10);

    // Converta o primeiro caractere de cada string em maiúscula
    converterPrimeiroCaractereMaiuscula(str1);
    converterPrimeiroCaractereMaiuscula(str2);

    // Imprima as strings em ordem alfabética
    if (str1 < str2) {
        cout << str1 << endl;
        cout << str2 << endl;
    } else {
        cout << str2 << endl;
        cout << str1 << endl;
    }

    return 0;
}
