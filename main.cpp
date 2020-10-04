#include "rsa.h"

int main(int argc, const char** argv) {
    while (1) {
        cout << "||generacion de claves   = > 1 ||" << endl; 
        cout << "|| encriptacion          = > 2 ||" << endl;
        cout << "|| desencriptacion       = > 3 ||" << endl;
        cout << "|| salir del programa    = > 4 ||" << endl;
        cout << " " << endl;
        char opt;
        cin >> opt;

        if (opt == '1') {
            // generacion de claves
            RSA::generar();
        }
        else if (opt == '2') {
            // encriptacion
            string msg;
            InfInt e, n;

            cout << "Mensaje para encriptar: ";
            cin.ignore();
            getline(cin, msg);

            cout << "clave publica(e) => ";
            cin >> e;

            cout << "modulo(n) => ";
            cin >> n;

            auto r = RSA::encriptar(msg, e, n);
            for (auto n : r) {
                cout << n << " ";
            }
        }
        else if (opt == '3') {
            // desencriptacion
            string msg;
            InfInt d, n;

            cout << "Mensaje para desencriptar: ";
            cin.ignore();
            getline(cin, msg);

            cout << "clave privada(d) => ";
            cin >> d;

            cout << "modulo(n) => ";
            cin >> n;

            auto r = RSA::desencriptar(msg, d, n);
            cout << r;
        }
        else if (opt == '4') {
            break; // salir del programa
        }
        cout << "\n";
    }
    return 0;
}
