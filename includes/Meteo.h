//
// Created by Madalina on 15/11/2020.
//

#pragma once

#include <iostream>
#include "Traseu.h"

class Meteo {
    float viteza_vant;
    bool ploua;
    Traseu traseu;
public:
    float influenta_vreme() const;
};

