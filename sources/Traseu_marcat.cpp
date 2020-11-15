//
// Created by Madalina on 12/11/2020.
//

#include "../includes/Traseu_marcat.h"

void Traseu_marcat:: timp_traseu () {
    float ore_noi = timp_urcare();
    if (marcaj.get_forma() != "") {
        ore_noi --;
        std::cout << "Te afli pe un traseu marcat deci poteca este amenajata. ";
    }
    else {
        ore_noi ++;
        std::cout << "Traseul pe care te afli nu este marcat, asadar te poti rataci cu usurinta. ";
    }
    std::cout << "Timpul nou pe traseul ales este de " << ore_noi << "h.\n";
}