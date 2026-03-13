#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool validarNumero(string s) {

    int estado = 12;

    for (char c : s) {

        switch (estado) {

            case 12:
                if (isdigit(c))
                    estado = 13;
                else
                    return false;
                break;

            case 13:
                if (isdigit(c))
                    estado = 13;
                else if (c == '.')
                    estado = 14;
                else if (c == 'E' || c == 'e')
                    estado = 16;
                else
                    return false;
                break;

            case 14:
                if (isdigit(c))
                    estado = 15;
                else
                    return false;
                break;

            case 15:
                if (isdigit(c))
                    estado = 15;
                else if (c == 'E' || c == 'e')
                    estado = 16;
                else
                    return false;
                break;

            case 16:
                if (c == '+' || c == '-')
                    estado = 17;
                else if (isdigit(c))
                    estado = 18;
                else
                    return false;
                break;

            case 17:
                if (isdigit(c))
                    estado = 18;
                else
                    return false;
                break;

            case 18:
                if (isdigit(c))
                    estado = 18;
                else
                    return false;
                break;
        }
    }

    if (estado == 13 || estado == 15 || estado == 18)
        return true;
    else
        return false;
}

int main() {

    string entrada;

    cout << "Ingresa un numero: ";
    cin >> entrada;

    if (validarNumero(entrada))
        cout << "Numero valido" << endl;
    else
        cout << "Numero invalido" << endl;

    return 0;
}
