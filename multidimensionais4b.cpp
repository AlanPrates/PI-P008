/*Como parte do exercício 3 foi se trabalhou com a geração de strings
aleatórias. Modifique a sua implementação para:
a. Em vez de gerar apenas duas strings, gerar uma lista de 10 strings
aleatórias;
b. Substitua o primeiro caractere de cada string por maiúscula;
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

// Função para gerar uma string aleatória com n caracteres em minúsculas
string gerarStringAleatoria(int n) {
    string randomString;
    const string caracteres = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < n; i++) {
        randomString += caracteres[rand() % caracteres.length()];
    }

    return randomString;
}

// Função para transformar o primeiro caractere da string em maiúscula
void tornarPrimeiroCaractereMaiuscula(string& str) {
    if (!str.empty()) {
        str[0] = toupper(str[0]);
    }
}

int main() {
    // Inicialize a semente para geração de números aleatórios com o tempo atual
    srand(static_cast<unsigned>(time(nullptr)));

    // Gerar e armazenar 10 strings aleatórias em uma lista
    vector<string> listaDeStrings;

    for (int i = 0; i < 10; i++) {
        string randomString = gerarStringAleatoria(10);
        tornarPrimeiroCaractereMaiuscula(randomString);
        listaDeStrings.push_back(randomString);
    }

    // Ordenar a lista em ordem alfabética
    sort(listaDeStrings.begin(), listaDeStrings.end());

    // Imprimir as strings em ordem alfabética
    cout << "Strings em ordem alfabética:" << endl;
    for (const string& str : listaDeStrings) {
        cout << str << endl;
    }

    return 0;
}
