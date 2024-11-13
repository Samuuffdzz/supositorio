#include <iostream>
#include <sstream>
#include <string>

#include "dicpaginas.hpp"

using namespace std;

string normalizar(const string& s);
void insertar(DicPaginas& dic);
void buscar_url(DicPaginas& dic);
void buscar_pal(DicPaginas& dic);
void buscar_and(DicPaginas& dic);
void buscar_or(DicPaginas& dic);
void autocompletar(DicPaginas& dic);

int main() {
    DicPaginas dic;
    char op = '#';

    while (op != '$' && cin >> op) {
        switch (op) {
            case 'i':
                insertar(dic);
                break;
            case 'u':
                buscar_url(dic);
                break;
            case 'b':
                buscar_pal(dic);
                break;
            case 'a':
                buscar_and(dic);
                break;
            case 'o':
                buscar_or(dic);
                break;
            case 'p':
                autocompletar(dic);
                break;
            case 's':
                cout << "Saliendo...\n";
                op = '$'; // Caracter que indica al bucle principal que debe terminar
                break;
            default: cout << "Entrada no admitida\n"; break;
        }
    }
}

string normalizar(const string& s) {
    string const enye ("ñ");

    int n = s.size();
    string r ("");

    for (int i = 0; i < n; ++i) {
        if (s[i] == -61) {
            switch (s[i + 1]) {
                case (char) 0xa1: r +=  'a'; break;
                case (char) 0x81: r +=  'a'; break;
                case (char) 0xa9: r +=  'e'; break;
                case (char) 0x89: r +=  'e'; break;
                case (char) 0xad: r +=  'i'; break;
                case (char) 0x8d: r +=  'i'; break;
                case (char) 0xb3: r +=  'o'; break;
                case (char) 0x93: r +=  'o'; break;
                case (char) 0xba: r +=  'u'; break;
                case (char) 0x9a: r +=  'u'; break;
                case (char) 0xbc: r +=  'u'; break;
                case (char) 0x9c: r +=  'u'; break;
                case (char) 0xb1: r += enye; break;
                case (char) 0x91: r += enye; break;
                default: r += s.substr(i, 2);
            }
            ++i;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') r +=  char(tolower(s[i]));
        else r +=  s[i];
    }
    return r;
}

void insertar(DicPaginas& dic) {
    Pagina nueva;
    nueva.leer();
    
    string s;
    int cont = 0;
    Pagina *ref = new Pagina(nueva);
    while (cin >> s, s = normalizar(s), s != "findepagina") {
        dic.insertar(s, ref);
        ++cont;
    }

    dic.insertar(nueva);
    nueva.escribir(dic.numElem());
    cout << cont << " palabras\n";

    // delete ref;
}

void buscar_url(DicPaginas& dic) {
    string url; cin >> url;
    Pagina *pag = dic.consultar(url);

    if (!pag) {
        cout << "u " << url << "\nTotal: 0 resultados\n";
    } else {
        cout << "u " << url << '\n';
        pag->escribir(1);
        cout << "Total: 1 resultados\n";
    }
}

void buscar_pal(DicPaginas& dic) {
    string pal; cin >> pal;
    pal = normalizar(pal);

    // cout << "b " << pal << "\nTotal: 0 resultados\n";

    list<Pagina*> lst = dic.buscar(pal);

    cout << "b " << pal << '\n';

    // cerr << lst.size() << '\n';

    int cont = 0;
    for (Pagina *p : lst) p->escribir(++cont);

    cout << "Total: " << cont << " resultados\n";
}

void buscar_and(DicPaginas& dic) {
    string line;
    getline(cin, line);
    istringstream ss(line);

    cout << "a";

    string s;
    while (ss >> s) cout << ' ' << normalizar(s);

    cout << "\nTotal: 0 resultados\n";
}

void buscar_or(DicPaginas& dic) {
    string line;
    getline(cin, line);
    istringstream ss(line);

    cout << "o";

    string s;
    while (ss >> s) cout << ' ' << normalizar(s);

    cout << "\nTotal: 0 resultados\n";
}

void autocompletar(DicPaginas& dic) {
    string prefix; cin >> prefix;

    cout << "p " << normalizar(prefix) << "\nTotal: 0 resultados\n";
}