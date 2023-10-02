/*A seguinte expressão em C++ gera um valor inteiro aleatório entre 0 e 255:
rand()%256. Utilizando esta expressão desenvolva uma aplicação que:
a. Simule a captura de uma imagem de 640 por 480 pixels, onde a
intensidade de iluminação é representada como um valor inteiro entre
0 (preto ou sem iluminação) e 255 (branco ou totalmente iluminado).
Pesquise mais sobre imagens em tons de cinza;
b. Um histograma permite analisar a distribuição de frequências de cada
intensidade em uma imagem. Pesquise mais sobre histogramas e
implemente o código para construir o histograma da imagem que foi
gerada;*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Função para gerar um valor inteiro aleatório entre 0 e 255
int gerarValorAleatorio() {
    return rand() % 256;
}

// Função para criar um histograma de uma imagem
vector<int> criarHistograma(const vector<vector<int>>& imagem) {
    vector<int> histograma(256, 0); // Inicialize o histograma com 256 elementos, todos com valor 0

    // Preencha o histograma com as frequências das intensidades de iluminação na imagem
    for (const vector<int>& linha : imagem) {
        for (int intensidade : linha) {
            histograma[intensidade]++;
        }
    }

    return histograma;
}

int main() {
    // Inicialize a semente para geração de números aleatórios com o tempo atual
    srand(static_cast<unsigned>(time(nullptr)));

    // Simule a captura de uma imagem de 640x480 pixels
    const int largura = 640;
    const int altura = 480;
    vector<vector<int>> imagem(altura, vector<int>(largura));

    // Preencha a imagem com valores de intensidade de iluminação aleatórios
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            imagem[i][j] = gerarValorAleatorio();
        }
    }

    // Crie o histograma da imagem
    vector<int> histograma = criarHistograma(imagem);

    // Imprima o histograma
    for (int i = 0; i < histograma.size(); i++) {
        cout << "Intensidade " << i << ": " << histograma[i] << " pixels" << endl;
    }

    return 0;
}
