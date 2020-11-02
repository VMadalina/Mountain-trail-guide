//
// Created by Madalina on 02/11/2020.
//
#pragma once

#include <string>

class Traseu {
    std::string tip_poteca; //amenajata, neamenajata
    int altitudine; //altitudinea de plecare

public:
    Traseu(std::string = "", int = 0);
    void timp_aprox(int) const; //aproximare a timpului de urcare/coborare in functie de poteca aleasa si altitudinea maxima la care se doreste sa se ajunga

    //getter
    int get_alt() const;
};

