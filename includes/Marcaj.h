//
// Created by Madalina on 02/11/2020.
//

#pragma once

#include "Traseu.h"
#include <string>
#include <memory>

class Marcaj {
    std::string forma; // cruce, dunga/banda, bulina/punct, triunghi
    std::string culoare; // rosu, albastru, galben

public:
    Marcaj(std::string = "", std::string = "");
    Marcaj(const Marcaj&);
    ~Marcaj();

    void info_sup(const Traseu&) const; //informatii suplimentare generale legate de traseul ales, in functie de forma si culoare
    friend std::ostream& operator << (std::ostream&, Marcaj&);
    friend std::istream& operator >> (std::istream&, Marcaj&);

    //settere
    void set_forma(std::string form) {
        this->forma = form;
    }

    void set_culoare(std::string cul) {
        this->culoare = cul;
    }

    //gettere
    std::string get_forma() {
        return forma;
    }

    std::string get_culoare() {
        return culoare;
    }
};

