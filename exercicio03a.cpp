/*
Implemente uma aplicação em C que:
a. Leia do teclado uma string no formato dd/mm/aaaa, ao alguma
variação desse formato (Ex. 5/12/2022, 05/02/23, 07/5/2024), e
imprima na tela por separado dia, mês e ano.
b. Modifique o exemplo anterior de forma a verificar se a data fornecida
é uma data válida (Ex. 31/02/1990 e 24/15/2002 não são datas
válidas);
c. Modifique a aplicação de forma que, se for uma data válida, imprima
a data por extenso (Ex. para 5/12/2022 imprimir 5 de dezembro de
2022)

*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Função para verificar se um ano é bissexto
bool ehBissexto(int ano) 
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Função para verificar se uma data é válida
bool ehDataValida(int dia, int mes, int ano) 
{
    if (mes < 1 || mes > 12)
        return false;

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ehBissexto(ano))
        diasNoMes[2] = 29;

    return dia >= 1 && dia <= diasNoMes[mes];
}

int main() 
{
    string data;
    cout << "Digite uma data no formato dd/mm/aaaa: ";
    getline(cin, data);

    int dia, mes, ano;
    char separator;

    stringstream ss(data);
    ss >> dia >> separator >> mes >> separator >> ano;

    if (ss && ehDataValida(dia, mes, ano)) 
    {
        cout << "Data valida." << endl;

        // Array de nomes dos meses
        string nomesMeses[] = 
        {"", "janeiro", "fevereiro", "março", "abril", "maio", "junho",
                               "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

        cout << "Data por extenso: " << dia << " de " << nomesMeses[mes] << " de " << ano << endl;
    } 
    else 
    {
        cout << "Data invalida." << endl;
    }

    return 0;
}