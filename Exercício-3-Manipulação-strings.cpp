#include <iostream>
#include <string>
using namespace std;

void separarData(string data) {
    size_t pos = 0;
    string token;
    while ((pos = data.find('/')) != string::npos) {
        token = data.substr(0, pos);
        cout << token << endl;
        data.erase(0, pos + 1);
    }
    cout << data << endl;
}

bool validarData(string data) {
    int dia, mes, ano;
    if (sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano) == 3) {
        if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 1000 && ano <= 9999) {
            return true;
        }
    }
    return false;
}

void imprimirDataExtenso(string data) {
    string meses[12] = {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    int dia, mes, ano;
    if (sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano) == 3) {
        cout << dia << " de " << meses[mes - 1] << " de " << ano << endl;
    }
}

int main() {
    string data;
    cout << "Digite uma data no formato dd/mm/aaaa: ";
    getline(cin, data);

    // a. Imprimir dia, mês e ano separadamente
    separarData(data);

    // b. Verificar se a data fornecida é válida
    if (validarData(data)) {
        cout << "Data válida!" << endl;

        // c. Imprimir a data por extenso
        imprimirDataExtenso(data);
    } else {
        cout << "Data inválida!" << endl;
    }

    return 0;
}
