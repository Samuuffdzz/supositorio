// #pragma once

#ifndef __ARBOL__
#define __ARBOL__

#include "nodo.hpp"

class Arbol {
private:
    Nodo *raiz;
    int n;
    void RSI(Nodo*& u) { u = u->RSI(); }
    void RSD(Nodo*& u) { u = u->RSD(); }
public:
    Arbol() : raiz(nullptr), n(0) {}
    ~Arbol() { delete raiz; }
    void insertar(string pal, Pagina *pag);
    list<Pagina*> buscar(string pal);
    int numElem() { return n; }
};

#endif