// Created by Madalina on 15/11/2020.
//
#pragma once
#include "Traseu.h"
#include "Meteo.h"

class Traseu_nemarcat: public Traseu, public Meteo {
    int altitudine_noua;
    int pozitie;

public:
    Traseu_nemarcat(Traseu, int = 0, int = 0);
    static float timp_traseu_nemarcat(Traseu);
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