//
// Created by Madalina on 12/11/2020.
//

#pragma  once

#include <iostream>
#include "Marcaj.h"

class Traseu_marcat : public Traseu {
    class Marcaj marcaj;
public:
    //Traseu_marcat(Marcaj);
    void timp_traseu_marcat();
    friend std::ostream& operator << (std::ostream&, Traseu_marcat&);
    friend std::istream& operator >> (std::istream&, Traseu_marcat&);
    Traseu_marcat &operator = (Marcaj&);
};

