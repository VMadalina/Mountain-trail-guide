//
// Created by Madalina on 02/11/2020.
//

#pragma once

#include "Traseu.h"
#include <string>

class Marcaj {
    std::string forma; // cruce, dunga/banda, bulina/punct, triunghi
    std::string culoare; // rosu, albastru, galben

public:
    Marcaj(std::string = "-", std::string = "-");
    Marcaj(Marcaj&);
    ~Marcaj();

    void info_sup(Traseu) const; //informatii suplimentare generale legate de traseul ales, in functie de forma si culoare
};

