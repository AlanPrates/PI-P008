/*A seguinte expressão em C++ gera um valor inteiro aleatório entre 1 e 20: 1
+ rand()%20. Utilizando esta expressão desenvolva uma aplicação que:
a. Preencha um array com 100 elementos de tipo int, com valores
aleatoriamente gerados entre 1 e 20;
b. Utilize um array de 20 posições para determinar quantas vezes se
repete cada um dos possíveis valores gerados no array;
c. Determine qual ou quais os números que mais vezes aparecem no
array*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    
    srand(time(0));

    const int tamanhoArray = 100;
    const int valorMaximo = 20;

    int array[tamanhoArray];
    int contagem[valorMaximo] = {0};

    // Preenche o array com valores aleatórios entre 1 e 20
    for (int i = 0; i < tamanhoArray; i++)
    {
        array[i] = 1 + rand() % valorMaximo;
        contagem[array[i] - 1]++; 
    }

    // Encontra o valor (ou valores) que mais vezes aparecem
    int maxContagem = 0;
    int valorMaisFrequente = 0;

    for (int i = 0; i < valorMaximo; i++)
    {
        if (contagem[i] > maxContagem)
        {
            maxContagem = contagem[i];
            valorMaisFrequente = i + 1;
        }
    }

    // Imprime os resultados
    cout << "Array gerado com " << tamanhoArray << " elementos:" << endl;
    for (int i = 0; i < tamanhoArray; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Contagem de cada valor:" << endl;
    for (int i = 0; i < valorMaximo; i++)
    {
        cout << i + 1 << ": " << contagem[i] << " vezes" << endl;
    }

    cout << "Valor mais frequente: " << valorMaisFrequente << " (aparece " << maxContagem << " vezes)" << endl;

    return 0;
}
