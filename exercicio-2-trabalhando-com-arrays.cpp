#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Inicializa a semente para números aleatórios

    int array[100]; // Cria um array de 100 elementos

    // Preenche o array com valores aleatórios entre 1 e 20
    for(int i = 0; i < 100; i++) {
        array[i] = 1 + rand() % 20;
    }

    int frequencia[20] = {0}; // Cria um array para contar a frequência de cada número

    // Conta a frequência de cada número no array
    for(int i = 0; i < 100; i++) {
        frequencia[array[i] - 1]++;
    }

    int maxFrequencia = 0;
    int numerosMaisFrequentes[20] = {0};
    int index = 0;

    // Encontra os números mais frequentes
    for(int i = 0; i < 20; i++) {
        if(frequencia[i] > maxFrequencia) {
            maxFrequencia = frequencia[i];
            numerosMaisFrequentes[0] = i + 1;
            index = 1;
        }
        else if(frequencia[i] == maxFrequencia) {
            numerosMaisFrequentes[index] = i + 1;
            index++;
        }
    }

    // Imprime os resultados
    cout << "Frequência dos números:" << endl;
    for(int i = 0; i < 20; i++) {
        cout << "Número " << i+1 << " aparece " << frequencia[i] << " vezes." << endl;
    }

    cout << "Número(s) mais frequente(s): ";
    for(int i = 0; i < index; i++) {
        cout << numerosMaisFrequentes[i] << " ";
    }
    cout << endl;

    return 0;
}
