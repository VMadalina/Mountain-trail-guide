//
// Created by Madalina on 15/11/2020.
//

#include "../includes/Meteo.h"

Meteo::Meteo(float vant, bool ploaie) {
    this->viteza_vant = vant;
    this->ploua = ploaie;
}

float Meteo::influenta_vreme() const {
    if (this->ploua == 1)
        if (this->viteza_vant >= 29)
            return 1.2;
        else
            return 1;
    else {
        if (this->viteza_vant >= 29)
            return 0.4;
        else
            return -0.3;
    }
}

std::istream& operator >> (std::istream& in, Meteo& m) {
    bool ploi;
    float viteza;
    in >> viteza >> ploi;
    m.set_viteza(viteza);
    m.set_ploua(ploi);
    return in;
}

std::ostream& operator << (std::ostream& out, Meteo& m) {
    out << "Vantul sufla cu o viteza de " << m.get_viteza() << " m/s. \n";
    if (m.get_ploua())
        std::cout << "Si din pacate a inceput sa si ploua. \n";
    else
        std::cout << "Si nu ploua. Yaay! \n";
    return out;
}