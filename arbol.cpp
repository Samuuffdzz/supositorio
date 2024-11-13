#include "arbol.hpp"

void Arbol::insertar(string pal, Pagina* pag) {
    if (!raiz) {
        raiz = new Nodo(pal, pag);
        return;
    }

    raiz->insertar(pal, pag);
    int h_lft = raiz->alturaLft(), h_rgt = raiz->alturaRgt();
    if (h_lft > h_rgt + 1) raiz = raiz->RSI();
    if (h_rgt > h_lft + 1) raiz = raiz->RSD();
}

list<Pagina*> Arbol::buscar(string pal) {
    if (!raiz) return list<Pagina*>();
    return raiz->buscar(pal);
}
