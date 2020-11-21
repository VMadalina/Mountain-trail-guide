#include "includes/Traseu.h"
#include "includes/Marcaj.h"
#include "includes/Traseu_marcat.h"
#include "includes/Traseu_nemarcat.h"
#include "includes/Meteo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>


int main() {
    std::ifstream fin_T;
    std::ifstream fin_M;
    std::ifstream fin_Meteo;
    fin_T.open ("files/Traseu.txt");
    fin_M.open ("files/Marcaj.txt");
    fin_Meteo.open ("files/Meteo.txt");

    int nr_trasee = 0, nr_marcaje = 0;
    std::string linie;
    srand((unsigned) time (nullptr));

    if (fin_T.is_open())
        fin_T >> nr_trasee;
    else
        std::cout << "Fisierul pentru trasee nu a putut fi deschis";

    if (fin_M.is_open())
        fin_M >> nr_marcaje;
    else
        std::cout << "Fisierul pentru marcaje nu a putut fi deschis";

    Traseu traseu[nr_trasee];
    Marcaj marcaj[nr_marcaje];
    Meteo meteo[nr_trasee];
    std::vector<std::unique_ptr<Traseu_marcat>> t_marcat;
    std::vector<std::unique_ptr<Traseu_nemarcat>> t_nemarcat;

    for (int i = 0; i < nr_trasee; i++) {
        fin_T >> traseu[i];
        fin_Meteo >> meteo[i];
    }

    for (int i = 0; i < nr_marcaje; i++)
        fin_M >> marcaj[i];

    for (int i = 0; i < nr_trasee; i++) {
        if (traseu[i].get_tip_poteca() == "amenajata") {
            int random = (rand() % nr_marcaje);
            t_marcat.push_back(std::make_unique<Traseu_marcat>(marcaj[random]));
        }
        else
            t_nemarcat.push_back(std::make_unique<Traseu_nemarcat>());
    }

    //std::cout << meteo[0].influenta_vreme();
    float timp = 0;
    //timp = t_marcat0]->timp_traseu_marcat() + meteo[0].influenta_vreme();
    //timp = traseu[0].timp_traseu();
    timp = t_marcat[0]->timp_traseu_marcat();
    std::cout << timp;

    t_marcat.clear();
    t_nemarcat.clear();
    fin_T.close();
    fin_M.close();

    return 0;
}
