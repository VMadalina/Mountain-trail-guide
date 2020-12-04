//
// Created by Madalina on 02/11/2020.
//
#include "../includes/Traseu.h"
#include <cmath>

Traseu::Traseu(std::string tip_poteca, int altitudine, int altitudine_maxima) {
    this->tip_poteca = tip_poteca;
    this->altitudine = altitudine;
    this->altitudine_maxima = altitudine_maxima;
}

Traseu::~Traseu()= default;

int Traseu::get_alt() const {
    return altitudine;
}

int Traseu::get_alt_max() const {
    return altitudine_maxima;
}

std::string Traseu::get_tip_poteca() const {
    return tip_poteca;
}

//timpul tottal petrecut pe traseu (urcare + coborare)
float Traseu::timp_traseu() {
   // std::cout << "\n*********************** Calculul aproximativ al timpului pe traseu *********************\n";

    int dif_altitudine = this->altitudine_maxima - this->altitudine;
    float ore_traseu;
    ore_traseu= round(dif_altitudine / 300.0 ) + round(dif_altitudine / 400.0 );
    return std::abs(ore_traseu);
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