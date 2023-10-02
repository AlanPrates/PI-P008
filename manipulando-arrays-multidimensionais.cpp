#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Função para gerar uma string aleatória de comprimento especificado
string gerarStringAleatoria(int comprimento) {
    string caracteres = "abcdefghijklmnopqrstuvwxyz";
    string stringAleatoria;

    for (int i = 0; i < comprimento; i++) {
        int indice = rand() % caracteres.length();
        stringAleatoria += caracteres[indice];
    }

    return stringAleatoria;
}

int main() {
    // Seed para a função rand() baseada no tempo atual
    srand(time(0));

    // Parte a: Gerar uma lista de 10 strings aleatórias
    string listaDeStrings[10];
    for (int i = 0; i < 10; i++) {
        listaDeStrings[i] = gerarStringAleatoria(10); // Gerando strings de comprimento 10
    }

    // Parte b: Substituir o primeiro caractere de cada string por maiúscula
    for (int i = 0; i < 10; i++) {
        listaDeStrings[i][0] = toupper(listaDeStrings[i][0]);
    }

    // Exibir as strings resultantes
    cout << "Lista de Strings:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << listaDeStrings[i] << endl;
    }

    return 0;
}
