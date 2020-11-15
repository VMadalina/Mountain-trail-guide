//
// Created by Madalina on 15/11/2020.
//

#pragma once

#include <iostream>
#include "Traseu.h"

class Meteo {
    float viteza_vant;
    std::string cer; ///senin, innorat
    bool ploua;
    Traseu traseu;
public:
    float influenta_vreme ();
};

