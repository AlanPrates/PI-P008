/*
cio 4: Manipulando arrays multidimensionais
● A seguinte expressão em C++ gera um valor inteiro aleatório entre 0 e 255:
rand()%256. Utilizando esta expressão desenvolva uma aplicação que:
a. Simule a captura de uma imagem de 640 por 480 pixels, onde a
intensidade de iluminação é representada como um valor inteiro entre
0 (preto ou sem iluminação) e 255 (branco ou totalmente iluminado).
Pesquise mais sobre imagens em tons de cinza;
b. Um histograma permite analisar a distribuição de frequências de cada
intensidade em uma imagem. Pesquise mais sobre histogramas e
implemente o código para construir o histograma da imagem que foi
gerada;
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    // Inicializa a semente para a função rand() com base no tempo atual
    srand(static_cast<unsigned int>(time(nullptr)));

    // Tamanho da imagem (640x480)
    const int largura = 640;
    const int altura = 480;

    // Matriz para representar a imagem (intensidades de iluminação)
    vector<vector<int>> imagem(altura, vector<int>(largura));

    // Preenche a matriz da imagem com valores aleatórios de 0 a 255
    for (int i = 0; i < altura; i++) 
    {
        for (int j = 0; j < largura; j++) 
        {
            imagem[i][j] = rand() % 256;
        }
    }

    // Cria um vetor para armazenar o histograma (inicializado com zeros)
    vector<int> histograma(256, 0);

    // Calcula o histograma da imagem
    for (int i = 0; i < altura; i++) 
    {
        for (int j = 0; j < largura; j++) 
        {
            histograma[imagem[i][j]]++;
        }
    }

    // Imprime o histograma
    cout << "Histograma da imagem:" << endl;
    for (int i = 0; i < 256; i++) 
    {
        cout << "Intensidade " << i << ": " << histograma[i] << " pixels" << endl;
    }

    return 0;
}