/*Implemente uma aplicação em C que:
a. Leia do teclado uma string no formato dd/mm/aaaa, ao alguma
variação desse formato (Ex. 5/12/2022, 05/02/23, 07/5/2024), e
imprima na tela por separado dia, mês e ano.
b. Modifique o exemplo anterior de forma a verificar se a data fornecida
é uma data válida (Ex. 31/02/1990 e 24/15/2002 não são datas
válidas);
c. Modifique a aplicação de forma que, se for uma data válida, imprima
a data por extenso (Ex. para 5/12/2022 imprimir 5 de dezembro de
2022)*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Função para verificar se um ano é bissexto
bool ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Função para verificar se uma data é válida
bool dataValida(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12)
        return false;
    if (dia < 1)
        return false;
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return dia <= 31;
        case 4: case 6: case 9: case 11:
            return dia <= 30;
        case 2:
            if (ehBissexto(ano))
                return dia <= 29;
            else
                return dia <= 28;
    }
    return false;
}

// Função para obter o nome do mês por extenso
string obterNomeDoMes(int mes) {
    string nomesMeses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho",
                           "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    return nomesMeses[mes - 1];
}

int main() {
    string data;
    
    cout << "Digite uma data no formato dd/mm/aaaa: ";
    cin >> data;
    
    // Use stringstream para extrair o dia, mês e ano da string
    stringstream ss(data);
    int dia, mes, ano;
    char delimiter;
    ss >> dia >> delimiter >> mes >> delimiter >> ano;
    
    // Verifique se a data é válida
    if (dataValida(dia, mes, ano)) {
        cout << "Data válida." << endl;
        cout << "Dia: " << dia << endl;
        cout << "Mês: " << mes << endl;
        cout << "Ano: " << ano << endl;
        
        // Imprima a data por extenso
        cout << dia << " de " << obterNomeDoMes(mes) << " de " << ano << endl;
    } else {
        cout << "Data inválida." << endl;
    }
    
    return 0;
}
