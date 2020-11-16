#include "includes/Traseu.h"
#include "includes/Marcaj.h"
#include "includes/Traseu_marcat.h"
#include "includes/Traseu_nemarcat.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

int main() {
    std::ifstream fin_T;
    std::ifstream fin_M;
    fin_T.open ("files/Traseu.txt");
    fin_M.open ("files/Marcaj.txt");

    int nr_trasee, nr_marcaje;

    fin_T >> nr_trasee;
    fin_M >> nr_marcaje;
    Traseu traseu[nr_trasee];
    Marcaj marcaj[nr_marcaje];
    std::vector<std::unique_ptr<Traseu_marcat>> t_marcat;
    std::vector<std::unique_ptr<Traseu_nemarcat>> t_nemarcat;

    if (fin_T.is_open())
        for (int i = 0; i < nr_trasee; i++) {
            fin_T >> traseu[i];
        }
    else
     std::cout << "Fisierul pentru trasee nu a putut fi deschis";

    if (fin_M.is_open())
        for (int i = 0; i < nr_marcaje; i++) {
            fin_M >> marcaj[i];
        }
    else
        std::cout << "Fisierul pentru marcaje nu a putut fi deschis";
    for (int i = 0; i < nr_trasee; i++) {
        if (traseu[i].get_tip_poteca() == "amenajata")
            t_marcat.push_back(std::make_unique<Traseu_marcat>());
        else
            t_nemarcat.push_back(std::make_unique<Traseu_nemarcat>());
    }

    std::cout << t_marcat.size() << "\n";
    std::cout << t_nemarcat.size();

    t_marcat.clear();
    t_nemarcat.clear();

    fin_T.close();
    fin_M.close();

    return 0;
}
