//
// Created by Madalina on 03/12/2020.
//

#pragma once
#include "../includes/Traseu.h"
#include "../includes/Meteo.h"
#include "../includes/Marcaj.h"
#include <vector>
#include <memory>

class Excursie {
    std::vector<std::unique_ptr<Traseu>> trasee;
public:
    void adauga_traseu(const Traseu&, const Marcaj&);
    void timp_total(Meteo*);
};

