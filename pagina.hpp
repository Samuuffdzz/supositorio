// #pragma once

#ifndef __PAGINA__
#define __PAGINA__

#include <iostream>

using namespace std;

class Pagina {
    friend class DicPaginas;
    friend class TablaHash;
    friend class Nodo;
private:
    int rel;
    string url, titulo;
public:
    Pagina() = default;
    Pagina(const Pagina& p) { rel = p.rel, url = p.url, titulo = p.titulo; }
    void leer();
    void escribir(int insertions);
};

#endif