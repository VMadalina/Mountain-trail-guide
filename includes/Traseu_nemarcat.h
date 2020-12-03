// Created by Madalina on 15/11/2020.
//
#pragma once
#include "Traseu.h"
#include "Meteo.h"

class Traseu_nemarcat: public Traseu, public Meteo {
    int altitudine_noua;
    int pozitie;

public:
    Traseu_nemarcat(const Traseu&, int = 0, int = 0);
    Traseu_nemarcat(int = 0, int = 0);
    float timp_traseu();
    void obiectiv_nou(Meteo);
    friend std::ostream& operator << (std::ostream&, Traseu_nemarcat&);

    //getteri
    int get_poz() {
        return pozitie;
    }

    //setteri
    void set_poz(int poz) {
        this->pozitie = poz;
    }
};