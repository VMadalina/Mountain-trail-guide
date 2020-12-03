//
// Created by Madalina on 12/11/2020.
//

#pragma  once
#include "Marcaj.h"

class Traseu_marcat : public Traseu {
protected:
    class Marcaj marcaj;
    int pozitie;
public:
    Traseu_marcat(const Marcaj&, int = 0);
    float timp_traseu();
    friend std::ostream& operator << (std::ostream&, Traseu_marcat&);
    Traseu_marcat &operator = (Marcaj&);

    //getteri
    int get_poz() {
        return pozitie;
    }

    //setteri
    void set_poz(int poz) {
        this->pozitie = poz;
    }
};

