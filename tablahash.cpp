#include "tablahash.hpp"
#include "pagina.hpp"

#include <assert.h>
#include <list>

using namespace std;

TablaHash::TablaHash() { tabla.assign(b, list<Pagina>()); }

void TablaHash::insertar(Pagina nueva, bool reset) {
    int idx = h(nueva.url);

    list<Pagina>::iterator it = tabla[idx].begin();
    while (it != tabla[idx].end() && it->url < nueva.url) ++it;

    if (it != tabla[idx].end() && it->url == nueva.url) {
        *it = nueva;
        return;
    }

    tabla[idx].insert(it, nueva);
    if (!reset) {
        ++n;
        if (n > (b << 1)) reestructurar();
    }
}

void TablaHash::insertar(Pagina nueva) {
    insertar(nueva, false);
}

Pagina* TablaHash::consultar(string url) {
    int idx = h(url);

    for (Pagina& p : tabla[idx]) if (p.url == url) return &p;
    return nullptr;
}

int TablaHash::numElem() { return n; }