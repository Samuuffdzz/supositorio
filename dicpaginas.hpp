// #pragma once

#ifndef __DIC_PAGINAS__
#define __DIC_PAGINAS__

#include <list>

#include "pagina.hpp"
#include "tablahash.hpp"
#include "arbol.hpp"

using namespace std;

class DicPaginas {
private:
    TablaHash tabla;
    Arbol arbol;
public:
    DicPaginas() = default;
    void insertar(Pagina nueva);
    void insertar(string pal, Pagina* pag);
    Pagina* consultar(string url);
    list<Pagina*> buscar(string pal);
    int numElem();
};

#endif