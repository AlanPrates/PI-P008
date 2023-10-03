/*
A seguinte expressão em C++ gera um valor de ponto flutuante aleatório
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



int main() 
{
    // Inicialize o gerador de números aleatórios com o tempo atual
    srand(time(0));

    //A: Preencha um array com 100 elementos de int
    const int tamanhoVetor = 100;
    int vetor[tamanhoVetor];

    for (int i = 0; i < tamanhoVetor; i++) 
    {
        vetor[i] = 1 + rand() % 20; // Gera números aleatórios entre 1 e 20
    }

    //B: Use um array de 20 posições para contar as ocorrências
    int contador[20] = {0};

    for (int i = 0; i < tamanhoVetor; i++) 
    {
        contador[vetor[i] - 1]++; // Incrementa o contador correspondente
    }

    //C: Determine qual ou quais números aparecem mais vezes
    int maxOcorrencias = 0;

    for (int i = 0; i < 20; i++) 
    {
        if (contador[i] > maxOcorrencias) 
        {
            maxOcorrencias = contador[i];
        }
    }

    cout << "Numeros que mais vezes aparecem: ";

    for (int i = 0; i < 20; i++) 
    {
        if (contador[i] == maxOcorrencias) 
        {
           cout << i + 1 << " ";
        }
    }

    cout << "aparecem " << maxOcorrencias << " vezes." <<endl;

    return 0;
}