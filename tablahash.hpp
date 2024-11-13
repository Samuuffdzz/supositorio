// #pragma once

#ifndef __TABLA_HASH__
#define __TABLA_HASH__

#include "pagina.hpp"

#include <vector>
#include <list>

using namespace std;

class TablaHash {
private:
    int a = 71, b = 1000;
    vector<list<Pagina>> tabla;
    int n = 0;
    int h(string url) {
        int res = 0;
        for (char i : url) res = ((long long) a * res + i) % b;
        return (res + b) % b;
    }
    void reestructurar() {
        b <<= 1;
        vector<list<Pagina>> aux(b, list<Pagina>());

        // cerr << "i was here\n";

        swap(tabla, aux);

        for (int i = 0; i < (b >> 1); ++i) {
            for (Pagina& p : aux[i]) 
                insertar(p, true);
            aux[i].clear();
        }

        aux.clear();

        // cerr << aux.size() << ' ' << tabla.size() << '\n';
    }
public:
    TablaHash();
    void insertar(Pagina nueva, bool reset);
    void insertar(Pagina nueva);
    Pagina* consultar(string url);
    int numElem();
};

#endif