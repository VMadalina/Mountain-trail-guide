//
// Created by Madalina on 03/12/2020.
//

#include "../includes/Excursie.h"
#include "../includes/Traseu_nemarcat.h"
#include "../includes/Traseu_marcat.h"
#include "../includes/Strategy.h"
#include <cmath>

void Excursie::timp_total(Meteo *meteo) {
    int random = (rand() % this->trasee.size());
    int random_vreme = (rand() % this->trasee.size());
    std::cout << meteo[random_vreme];
    int random_traseu = (rand() % 3) + 1;

    Context *context = new Context (new Traseu_normal);
    if(random_traseu == 1)
        context->set_strategy(new Traseu_urs);
    else if (random_traseu == 2)
        context->set_strategy(new Traseu_masina);
    else
        context->set_strategy(new Traseu_rana);

    float timp_final = trasee[random]->timp_traseu() + meteo[random_vreme].influenta_vreme() + context->Situatie();
    if( (timp_final - (int) timp_final) > 0.6)
        timp_final = timp_final + 0.4;

    std::cout << "\n*********************** Calculul aproximativ al timpului pe traseu *********************\n";
    std::cout << (int) timp_final << " ore si " << std::round((timp_final - (int)timp_final) * 100) << " minute.\n";

    delete context;
}

void Excursie::adauga_traseu(const Traseu& t, const Marcaj& marcaj) {
    if(t.get_tip_poteca() == "amenajata") {
        trasee.push_back(std::make_unique<Traseu_marcat>(t,marcaj));
    }
    else {
        trasee.push_back(std::make_unique<Traseu_nemarcat>(t));
    }
}