#include "dicpaginas.hpp"

void DicPaginas::insertar(Pagina nueva) { tabla.insertar(nueva); }

void DicPaginas::insertar(string pal, Pagina* pag) { arbol.insertar(pal, pag); }

Pagina* DicPaginas::consultar(string url) { return tabla.consultar(url); }

list<Pagina*> DicPaginas::buscar(string pal) { return arbol.buscar(pal); }

int DicPaginas::numElem() { return tabla.numElem(); }