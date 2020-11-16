//
// Created by Madalina on 12/11/2020.
//

#include "../includes/Traseu_marcat.h"

void Traseu_marcat:: timp_traseu () {
    float ore_noi = timp_urcare() - 1;
    std::cout << marcaj;
    std::cout << "Te afli pe un traseu marcat deci poteca este amenajata. Timpul nou pe traseul ales este de " << ore_noi << "h.\n";
}