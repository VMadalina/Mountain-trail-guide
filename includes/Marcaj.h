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
    Marcaj(std::string = "", std::string = "");
    Marcaj(Marcaj&);
    ~Marcaj();

    void info_sup(Traseu) const; //informatii suplimentare generale legate de traseul ales, in functie de forma si culoare
    friend std::ostream& operator << (std::ostream&, Marcaj&);

    //settere
    void set_forma(std::string foma) {
        this->forma = foma;
    }

    void set_culoare(std::string culoare) {
        this->culoare = culoare;
    }

    //gettere
    std::string get_forma() {
        return forma;
    }
};

