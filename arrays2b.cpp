/*A seguinte expressão em C++ gera um valor de ponto flutuante aleatório
entre 10 e 40: 1 + 30.0*(rand()%100)/3000.0. Supondo que se
deseja simular uma rede de estações meteorológicas, implemente uma
aplicação que:
a. Armazene num array as temperaturas reportadas por 250 estações
meteorológicas.
b. Determine a temperatura máxima e mínima reportadas;
c. Determine a temperatura média entre as 250 estações;
d. Um modelo de predição estima que, dentro de uma hora, as estações
que estão marcando temperatura acima da média vão ficar 1 grau
mais quente. Já as que estão marcando abaixo da média vão ficar 2
graus mais frias. Atualize o array com as temperaturas das estações,
de acordo com a previsão do modelo.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(0));

    const int numEstacoes = 250;
    double temperaturas[numEstacoes];
    double temperaturaMaxima = -100.0; 
    double temperaturaMinima = 100.0; 
    double somaTemperaturas = 0.0;

    // Preenche o array com temperaturas aleatórias entre 10 e 40
    for (int i = 0; i < numEstacoes; i++) {
        temperaturas[i] = 10.0 + 30.0 * (rand() % 100) / 100.0;

        // Atualiza a temperatura máxima e mínima
        if (temperaturas[i] > temperaturaMaxima) {
            temperaturaMaxima = temperaturas[i];
        }
        if (temperaturas[i] < temperaturaMinima) {
            temperaturaMinima = temperaturas[i];
        }

        // Soma as temperaturas para calcular a média posteriormente
        somaTemperaturas += temperaturas[i];
    }

    // Calcula a temperatura média
    double temperaturaMedia = somaTemperaturas / numEstacoes;

    cout << "Temperatura máxima reportada: " << temperaturaMaxima << " graus Celsius" << endl;
    cout << "Temperatura mínima reportada: " << temperaturaMinima << " graus Celsius" << endl;
    cout << "Temperatura média reportada: " << temperaturaMedia << " graus Celsius" << endl;

    // Atualiza as temperaturas de acordo com o modelo de predição
    for (int i = 0; i < numEstacoes; i++) {
        if (temperaturas[i] > temperaturaMedia) {
            temperaturas[i] += 1.0;
        } else {
            temperaturas[i] -= 2.0;
        }
    }

    cout << "Temperaturas atualizadas de acordo com o modelo de predição:" << endl;
    for (int i = 0; i < numEstacoes; i++) {
        cout << "Estação " << i + 1 << ": " << temperaturas[i] << " graus Celsius" << endl;
    }

    return 0;
}
