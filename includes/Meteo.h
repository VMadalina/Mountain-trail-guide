//
// Created by Madalina on 15/11/2020.
//

#pragma once

#include <iostream>

class Meteo {
    float viteza_vant;
    bool ploua;
public:
    Meteo(float = 0, bool = false);
    float influenta_vreme() const;
    friend std::istream& operator >> (std::istream&, Meteo&);
    friend std::ostream& operator << (std::ostream&, Meteo&);

    //getteri
    float get_viteza() {
        return viteza_vant;
    }

    bool get_ploua() {
        return ploua;
    }

    //setteri
    void set_viteza(float viteza) {
        this->viteza_vant = viteza;
    }

    void set_ploua(bool ploi) {
        this->ploua = ploi;
    }
};

