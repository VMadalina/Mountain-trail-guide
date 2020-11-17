//
// Created by Madalina on 15/11/2020.
//

#include "../includes/Meteo.h"

float Meteo::influenta_vreme() const {
    if (ploua == true)
        if (viteza_vant >= 29)
            return 1.5;
        else
            return 1;
    else {
        if (viteza_vant >= 29)
            return 0.5;
        else
            return -0.5;
    }
}