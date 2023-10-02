/*A seguinte expressão em C gera valores aleatórios de ponto flutuante entre 0
e 10: ((float)rand()/RAND_MAX)*10. Utilizando esta expressão implemente
uma aplicação que:
a. Simule as notas de uma turma de 15 alunos em uma avaliação e
guarde num array;
b. Simule as notas da mesma turma numa segunda avaliação e guarde
em um segundo array;
c. Compare as notas de cada aluno na segunda avaliação, em relação à
primeira, e imprima na tela as mensagens “Melhorou”, “Piorou” ou
“Manteve a nota” de acordo com o desempenho de cada aluno;
d. Preencha um um terceiro array com a média de cada aluno nas duas
avaliações.*/
#include <iostream>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

using namespace std;

int main() {
    const int numAlunos = 15;
    float notasAvaliacao1[numAlunos];
    float notasAvaliacao2[numAlunos];
    char desempenho[numAlunos];

    // Inicialize o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Preencha os arrays com notas aleatórias entre 0 e 10
    for (int i = 0; i < numAlunos; i++) {
        notasAvaliacao1[i] = ((float)rand() / RAND_MAX) * 10;
        notasAvaliacao2[i] = ((float)rand() / RAND_MAX) * 10;
    }

    // Compare as notas e determine o desempenho
    for (int i = 0; i < numAlunos; i++) {
        if (notasAvaliacao2[i] > notasAvaliacao1[i]) {
            desempenho[i] = 'M'; // Melhorou
        } else if (notasAvaliacao2[i] < notasAvaliacao1[i]) {
            desempenho[i] = 'P'; // Piorou
        } else {
            desempenho[i] = 'I'; // Manteve a nota (I de "Igual")
        }
    }

    // Calcule a média das notas
    float media[numAlunos];
    for (int i = 0; i < numAlunos; i++) {
        media[i] = (notasAvaliacao1[i] + notasAvaliacao2[i]) / 2;
    }

    // Imprima as notas e desempenho dos alunos
    cout << "Notas e desempenho dos alunos:" << endl;
    for (int i = 0; i < numAlunos; i++) {
        cout << "Aluno " << i + 1 << ": " << notasAvaliacao1[i] << " -> " << notasAvaliacao2[i] << " (";
        switch (desempenho[i]) {
            case 'M':
                cout << "Melhorou";
                break;
            case 'P':
                cout << "Piorou";
                break;
            case 'I':
                cout << "Manteve a nota";
                break;
        }
        cout << ")" << endl;
    }

    return 0;
}