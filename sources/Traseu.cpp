//
// Created by Madalina on 02/11/2020.
//
#include "../includes/Traseu.h"

#include <cmath>
#include <iostream>

Traseu::Traseu(std::string tip_poteca, int altitudine, int altitudine_maxima) {
    this->tip_poteca = tip_poteca;
    this->altitudine = altitudine;
    this->altitudine_maxima = altitudine_maxima;
}

int Traseu::get_alt() const {
    return altitudine;
}

std::string Traseu::get_tip_poteca() const {
    return tip_poteca;
}

float Traseu::timp_traseu() {
    std::cout << "\n*********************** Calculul aproximativ al timpului pe traseu *********************\n\n";

    int dif_altitudine = this->altitudine_maxima - this->altitudine;
    float ore_urcare;
    if (this->tip_poteca == "amenajata")
        ore_urcare = round(dif_altitudine / 350.0 );
    else
        ore_urcare = round(dif_altitudine / 250.0 );

    return std::abs(ore_urcare);
}

std::ostream& operator << (std::ostream& out, Traseu& t) {
    float timp = t.timp_traseu();
    out << "Urcarea pe poteca " << t.tip_poteca << " va dura aproximativ " << timp << " ore.\n";
    return out;
}

std::istream& operator >> (std::istream& in, Traseu& t) {
    std::string tip_poteca;
    int alt, alt_max;
    in >> tip_poteca >> alt >> alt_max;
    t.set_tip_poteca(tip_poteca);
    t.set_alt_init(alt);
    t.set_alt_max(alt_max);
    return in;
}