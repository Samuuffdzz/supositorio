#include "pagina.hpp"

void Pagina::leer() {
    cin >> rel >> url;
    getline(cin, titulo);
    getline(cin, titulo);
}

void Pagina::escribir(int insertions) {
    cout << insertions << ". " << url << ", " << titulo << ", Rel. " << rel << '\n';
}