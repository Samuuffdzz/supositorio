#include "arbol.hpp"

void Arbol::insertar(string pal, Pagina* pag) {
    if (!raiz) {
        raiz = new Nodo(pal, pag);
        return;
    }

    raiz->insertar(pal, pag);
}

list<Pagina*> Arbol::buscar(string pal) {
    if (!raiz) return list<Pagina*>();
    return raiz->buscar(pal);
}