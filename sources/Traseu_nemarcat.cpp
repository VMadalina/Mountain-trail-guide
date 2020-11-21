//
// Created by Madalina on 15/11/2020.
//

#include "../includes/Traseu_nemarcat.h"

float Traseu_nemarcat::timp_traseu_nemarcat() {
    float ore_noi = timp_traseu() + 1;
    return ore_noi;
    //std::cout << "Te afli pe un traseu nemarcat deci poteca este neamenajata. Timpul nou pe traseul ales este de " << ore_noi << "h.\n";
}