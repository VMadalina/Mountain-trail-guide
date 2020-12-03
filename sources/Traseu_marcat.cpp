//
// Created by Madalina on 12/11/2020.
//

#include "../includes/Traseu_marcat.h"

Traseu_marcat::Traseu_marcat(const Marcaj& m, int poz) {
    this->marcaj = m;
    this->pozitie = poz;
}

float Traseu_marcat:: timp_traseu () {
    return -0.2;
}

std::ostream& operator << (std::ostream& out, Traseu_marcat& tm) {
    out <<"Traseul ales este amenajat, cu marcajul " << tm.marcaj.get_forma() << " " << tm.marcaj.get_culoare() << ".\n";
    return out;
}

Traseu_marcat &Traseu_marcat::operator = (Marcaj &m) {
    this->marcaj.set_culoare(m.get_culoare());
    this->marcaj.set_forma(m.get_forma());
    return (*this);
}