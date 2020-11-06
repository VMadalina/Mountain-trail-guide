#include "includes/Traseu.h"
#include "includes/Marcaj.h"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin_T;
    std::ifstream fin_M;
    fin_T.open ("files/Traseu.txt");
    fin_M.open ("files/Marcaj.txt");

    std::string tip_poteca, forma_marcaj, culoare_marcaj;
    int nr_trasee, nr_marcaje, altitudine_traseu, altitudine_maxima;

    fin_T >> nr_trasee;
    fin_M >> nr_marcaje;
    Traseu traseu[nr_trasee];
    Marcaj marcaj[nr_marcaje];

    if (fin_T.is_open())
        for (int i = 0; i < nr_trasee; i++) {
            fin_T >> tip_poteca >> altitudine_traseu >> altitudine_maxima;
            traseu[i].set_tip_poteca(tip_poteca);
            traseu[i].set_alt_init(altitudine_traseu);
            traseu[i].set_alt_max(altitudine_maxima);
        }
    else
     std::cout << "Fisierul pentru trasee nu a putut fi deschis";

    if (fin_M.is_open())
        for (int i = 0; i < nr_marcaje; i++) {
            fin_M >> forma_marcaj >> culoare_marcaj;
            marcaj[i].set_forma(forma_marcaj);
            marcaj[i].set_culoare(culoare_marcaj);
        }
    else
        std::cout << "Fisierul pentru marcaje nu a putut fi deschis";

    std::cout << marcaj[0] << traseu[1];

    fin_T.close();
    fin_M.close();
    return 0;
}
