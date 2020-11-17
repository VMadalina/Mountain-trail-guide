#include "includes/Traseu.h"
#include "includes/Marcaj.h"
#include "includes/Traseu_marcat.h"
#include "includes/Traseu_nemarcat.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>


int main() {
    std::ifstream fin_T;
    std::ifstream fin_M;
    fin_T.open ("files/Traseu.txt");
    fin_M.open ("files/Marcaj.txt");

    int nr_trasee, nr_marcaje;
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
    std::vector<std::unique_ptr<Traseu_marcat>> t_marcat;
    std::vector<std::unique_ptr<Traseu_nemarcat>> t_nemarcat;

    for (int i = 0; i < nr_trasee; i++)
        fin_T >> traseu[i];

    for (int i = 0; i < nr_marcaje; i++)
        fin_M >> marcaj[i];

    for (int i = 0; i < nr_trasee; i++) {
        int random = (rand() % nr_marcaje) + 1;
        if (traseu[i].get_tip_poteca() == "amenajata")
            t_marcat.push_back(std::make_unique<Traseu_marcat>());
        else
            t_nemarcat.push_back(std::make_unique<Traseu_nemarcat>());
    }
    
    for(int i = 0; i < t_marcat.size(); i++) {
        int random = (rand() % nr_marcaje) + 1;
        t_marcat[i] = marcaj[random];
    }

    t_marcat.clear();
    t_nemarcat.clear();
    fin_T.close();
    fin_M.close();

    return 0;
}
