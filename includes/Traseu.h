//
// Created by Madalina on 02/11/2020.
//
#pragma once

#include <string>

class Traseu {
    std::string tip_poteca; //amenajata, neamenajata
    int altitudine; //altitudinea de plecare
    int altitudine_maxima;

public:
    Traseu(std::string = "", int = 0, int = 0);
    virtual ~Traseu();
    virtual float timp_traseu(); //aproximare a timpului de urcare/coborare in functie de poteca aleasa si altitudinea maxima la care se doreste sa se ajunga
    friend std::ostream& operator << (std::ostream&, Traseu&);
    friend std::istream& operator >> (std::istream&, Traseu&);

    //setter
    void set_tip_poteca(std::string tip_p) {
        this->tip_poteca = tip_p;
    }

    void set_alt_init(int alt_init) {
        this->altitudine = alt_init;
    }

    void set_alt_max(int alt_max) {
        this->altitudine_maxima = alt_max;
    }

    //getter
    int get_alt() const;
    std::string get_tip_poteca() const;
};

