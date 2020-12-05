//
// Created by Madalina on 03/12/2020.
//

#include "../includes/Excursie.h"
#include "../includes/Traseu_nemarcat.h"
#include "../includes/Traseu_marcat.h"
#include <cmath>

void Excursie::timp_total(int nr_trasee, Traseu *traseu, Meteo *meteo, std::vector <std::unique_ptr<Traseu>> &t) {
    int random = (rand() % t.size());
    int random_vreme = (rand() % nr_trasee);
    std::cout << meteo[random_vreme];
    float timp_final = traseu[random].timp_traseu() + t[random]->timp_traseu() + meteo[random_vreme].influenta_vreme();
    if( (timp_final - (int) timp_final) > 0.6)
        timp_final = timp_final + 0.4;

    std::cout << "\n*********************** Calculul aproximativ al timpului pe traseu *********************\n";
    std::cout << (int) timp_final << " ore si " << std::round((timp_final - (int)timp_final) * 100) << " minute.\n";

}

void Excursie::adauga_traseu(const Traseu& t, const Marcaj& marcaj) {
    if(t.get_tip_poteca() == "amenajata") {
        trasee.push_back(std::make_unique<Traseu_marcat>(marcaj));
    }
    else {
        trasee.push_back(std::make_unique<Traseu_nemarcat>());
    }
}