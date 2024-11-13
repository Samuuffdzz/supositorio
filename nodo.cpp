#include "nodo.hpp"

void Nodo::insertar(const string& pal, Pagina* pag) {
    if (pal == this->pal) {
        list<Pagina*>::iterator it = l.begin();

        /* if (pal == "perchel") {
            cerr << "-> Te estaba esperando\n";

            for (Pagina* p : l) cerr << "---> " << p->url << '\n';
        } */

        while (it != l.end() && pag->rel < (*it)->rel) ++it;
        while (it != l.end() && (*it)->rel == pag->rel && pag->url > (*it)->url) ++it;
        if (it != l.end() && pag->url == (*it)->url && pag->rel == (*it)->rel) *(*it) = *pag;
        else l.insert(it, pag);
        return;
    }

    if (pal < this->pal) {
        if (lft) lft->insertar(pal, pag);
        else lft = new Nodo(pal, pag);
        int h_lft = lft->alturaLft(), h_rgt = lft->alturaRgt();
        if (h_lft > h_rgt + 1) lft = lft->RSI();
        if (h_rgt > h_lft + 1) lft = lft->RSD();
    }

    else {
        if (rgt) rgt->insertar(pal, pag);
        else rgt = new Nodo(pal, pag);
        int h_lft = rgt->alturaLft(), h_rgt = rgt->alturaRgt();
        if (h_lft > h_rgt + 1) rgt = rgt->RSI();
        if (h_rgt > h_lft + 1) rgt = rgt->RSD();
    }

    // cerr << "llego\n";

    actAltura();
}

list<Pagina*> Nodo::buscar(const string& pal) {
    // cerr << pal << ' ' << this->pal << '\n';

    if (pal == this->pal) return l;

    if (pal < this->pal) {
        if (lft) return lft->buscar(pal);
        return list<Pagina*>();
    }

    if (rgt) return rgt->buscar(pal);
    return list<Pagina*>();
}

Nodo* Nodo::RSI() {
    if (!lft) return this;
    Nodo *B = lft;
    lft = B->rgt;
    actAltura();
    B->rgt = this;
    B->actAltura();
    return B;
}

Nodo* Nodo::RSD() {
    if (!rgt) return this;
    Nodo *B = rgt;
    rgt = B->lft;
    actAltura();
    B->lft = this;
    B->actAltura();
    return B;
}

/* Nodo* Nodo::RDI() {
    try {
        lft = lft->RSD();
        return RSI();
    }

    catch (...) {
        cerr << "No se pudo llevar a cabo la RDI\n";
        return nullptr;
    }
}

Nodo* Nodo::RDD() {
    try {
        rgt = rgt->RSI();
        return RSD();
    }

    catch (...) {
        cerr << "No se pudo llevar a cabo la RDD\n";
        return nullptr;
    }
} */