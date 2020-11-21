//
// Created by Madalina on 12/11/2020.
//

#include "../includes/Traseu_marcat.h"

Traseu_marcat::Traseu_marcat(Marcaj m) {
    this->marcaj = m;
}

float Traseu_marcat:: timp_traseu_marcat() {
    float ore_noi = timp_traseu()- 1;
    //std::cout << this->timp_traseu() << "\n";
    return ore_noi;
    //std::cout << marcaj;
    //std::cout << "Te afli pe un traseu marcat deci poteca este amenajata. Timpul nou pe traseul ales este de " << ore_noi << "h.\n";
}

std::ostream& operator << (std::ostream& out, Traseu_marcat& tm) {
    out <<"Traseul ales este " << tm.marcaj.get_forma() << " " << tm.marcaj.get_culoare() << "\n";
    return out;
}

/*std::istream& operator >> (std::istream& in, Traseu_marcat& tm) {
    in >> tm.marcaj;
    return in;
}*/

Traseu_marcat &Traseu_marcat::operator = (Marcaj &m) {
    this->marcaj.set_culoare(m.get_culoare());
    this->marcaj.set_forma(m.get_forma());
    return (*this);
}