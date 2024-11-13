// #pragma once

#ifndef __NODO__
#define __NODO__

#include <string>
#include <list>

#include "pagina.hpp"

class Nodo {
private:
    int h;
    string pal;
    list<Pagina*> l;
    Nodo *lft, *rgt;
    int alturaLft() { return lft ? lft->h : -1; }
    int alturaRgt() { return rgt ? rgt->h : -1; }
    void actAltura() { h = max(alturaLft(), alturaRgt()) + 1; }
public:
    Nodo(string p, Pagina* pg) : h(0), pal(p), l(pg ? list<Pagina*>({pg}) : list<Pagina*>()), lft(nullptr), rgt(nullptr) {}
    Nodo(string p) : Nodo(p, nullptr) {}
    Nodo() : Nodo("", nullptr) {}
    ~Nodo() { delete lft; delete rgt; }
    void insertar(const string& pal, Pagina* pag);
    list<Pagina*> buscar(const string& pal);
    Nodo* RSI();
    Nodo* RSD();
};

#endif