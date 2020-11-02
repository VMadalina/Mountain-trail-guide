#include "includes/Traseu.h"
#include "includes/Marcaj.h"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin_T;
    std::ifstream fin_M;
    fin_T.open ("Traseu.txt");
    fin_M.open ("Marcaj.txt");

    std::string tip_poteca, culoare_marcaj, forma_marcaj;
    int altitudine_traseu, altitudine_maxima;

    if (fin_T.is_open())
        fin_T >> tip_poteca >> altitudine_traseu >> altitudine_maxima;
    else
        std::cout << "Fisierul pentru trasee nu a putut fi deschis";

    if (fin_M.is_open())
        fin_M >> forma_marcaj >> culoare_marcaj;
    else
        std::cout << "Fisierul pentru marcaje nu a putut fi deschis";

    Traseu t(tip_poteca, altitudine_traseu);
    Marcaj m(forma_marcaj, culoare_marcaj);

    m.info_sup(t);
    t.timp_aprox(altitudine_maxima);

    fin_T.close();
    fin_M.close();
    return 0;
}
