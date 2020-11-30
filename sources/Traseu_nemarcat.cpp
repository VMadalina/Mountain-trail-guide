//
// Created by Madalina on 15/11/2020.
//

#include "../includes/Traseu_nemarcat.h"

Traseu_nemarcat::Traseu_nemarcat(Traseu t, int alt_noua, int poz) {
    this->set_alt_init(t.get_alt());
    this->set_alt_max(t.get_alt_max());
    this->altitudine_noua = alt_noua;
    this->pozitie = poz;
}

float Traseu_nemarcat::timp_traseu_nemarcat(Traseu t) {
    float ore_noi = t.timp_traseu() + 0.40;
    return ore_noi;
}

void Traseu_nemarcat::obiectiv_nou(Meteo vreme) {
    float influenta = vreme.influenta_vreme();
    if (influenta == 1.5 or influenta == 1) {
        std::cout << "\nRECOMANDARE: \n";
        std::cout<< "Din pacate vremea nu tine cu tine, iar din moment ce "
                    " te afli si pe un traseu marcat si te poti rataci usor, altitudinea"
                    " la care vei ajunge va fi cu 750 m mai mica. ";
        this->altitudine_noua = this->get_alt_max() - 750;
        std::cout << "Astfel, noua altitudine la care vei ajunge este " << this->altitudine_noua << "m.\n";
    }
}

std::ostream& operator << (std::ostream& out, Traseu_nemarcat& t) {
    out << "Te afli pe un traseu nemarcat. Exista sanse mari sa te ratacesti asa ca va trebui sa te deplasezi "
           "cu foarte mare atentie ca sa ajungi la " << t.get_alt_max() << "m. Asadar timpul tau pe traseu se va mari.\n";
    return out;
}