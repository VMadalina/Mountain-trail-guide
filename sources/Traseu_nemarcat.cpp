//
// Created by Madalina on 15/11/2020.
//

#include "../includes/Traseu_nemarcat.h"

void Traseu_nemarcat:: timp_traseu_nemarcat () {
    float ore_noi = timp_urcare() + 1;
    std::cout << "Te afli pe un traseu marcat deci poteca este amenajata. Timpul nou pe traseul ales este de " << ore_noi << "h.\n";
}