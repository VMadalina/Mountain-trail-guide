//
// Created by Madalina on 02/11/2020.
//
#include "../includes/Traseu.h"

#include <cmath>
#include <iostream>

Traseu::Traseu(std::string tip_poteca, int altitudine) {
    this->tip_poteca = tip_poteca;
    this->altitudine = altitudine;
}

int Traseu::get_alt() const {
    return altitudine;
}

void Traseu::timp_aprox(int altitudine_maxima) const {
    std::cout << "\n*********************** Calculul aproximativ al timpului pe traseu *********************\n\n";

    int dif_altitudine = altitudine_maxima - this->altitudine;
    if (this->tip_poteca == "amenajata"){
        std::cout << "Urcarea pe poteca amenajata va dura aproximativ " << round(dif_altitudine / 350.0 )<< " ore.\n";
        std::cout << "Coborarea pe poteca amenajata va dura aprox " << round(dif_altitudine / 450.0) << " ore.\n";
    }
    if (this->tip_poteca == "neamenajata"){
        std::cout << "Urcarea pe poteca neamenajata va dura aproximativ " << round(dif_altitudine / 250.0 )<< " ore.\n";
        std::cout << "Coborarea pe poteca neamenajata va dura aprox " << round(dif_altitudine / 400.0) << " ore.\n";
    }

}
