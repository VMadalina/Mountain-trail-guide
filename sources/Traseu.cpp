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

float Traseu::timp_urcare() {
    std::cout << "\n*********************** Calculul aproximativ al timpului pe traseu *********************\n\n";

    int dif_altitudine = this->altitudine_maxima - this->altitudine;
    double ore_urcare;
    if (this->tip_poteca == "amenajata")
        ore_urcare = round(dif_altitudine / 350.0 );
    else
        ore_urcare = round(dif_altitudine / 250.0 );

    return abs(ore_urcare);
}

std::ostream& operator << (std::ostream& out, Traseu& t) {
    float timp = t.timp_urcare();
    out << "Urcarea pe poteca " << t.tip_poteca << " va dura aproximativ " << timp << " ore.\n";
    return out;
}
