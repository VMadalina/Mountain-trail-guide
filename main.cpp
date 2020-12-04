#include "includes/Traseu.h"
#include "includes/Marcaj.h"
#include "includes/Traseu_marcat.h"
#include "includes/Traseu_nemarcat.h"
#include <fstream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <cmath>

void alege_traseu(int nr_trasee, Traseu *traseu, Meteo *meteo, std::vector <std::unique_ptr<Traseu>> &trasee) {
    int random = (rand() % trasee.size());
    //std::cout << *trasee[random];
    int random_vreme = (rand() % nr_trasee);
    std::cout << meteo[random_vreme];
    float timp_final = traseu[random].timp_traseu() + trasee[random]->timp_traseu() + meteo[random_vreme].influenta_vreme();
    if( (timp_final - (int) timp_final) > 0.6)
        timp_final = timp_final + 0.4;

    std::cout << "\n*********************** Calculul aproximativ al timpului pe traseu *********************\n";
    std::cout << (int) timp_final << " ore si " << std::round((timp_final - (int)timp_final) * 100) << " minute.\n";
    
}

int main() {
    srand((unsigned) time (nullptr));
    std::ifstream fin_T,  fin_M, fin_Meteo, fin_A;
    int nr_trasee = 0, nr_marcaje = 0, alegere = 0;

    try {
        fin_T.exceptions(std::ifstream::failbit);
        fin_M.exceptions(std::ifstream::failbit);
        fin_Meteo.exceptions(std::ifstream::failbit);
        fin_A.exceptions(std::ifstream::failbit);
        fin_T.open("files/Traseu.txt");
        fin_M.open("files/Marcaj.txt");
        fin_Meteo.open ("files/Meteo.txt");
        fin_A.open("files/Alegere.txt");
        fin_T >> nr_trasee;
        fin_M >> nr_marcaje;
        ///punem in fisier 1 pentru traseele marcate si 2 daca vrem sa alegem un traseu nemarcat
        fin_A >> alegere;
    }
    catch (const std::ifstream::failure& err) {
        std::cout << "Unul dintre fisiere nu a putut fi deschis.\n";
        std::cout << err.what() << "\n" << err.code() << "\n";
        return 1;
    }

    std::vector<std::unique_ptr<Traseu>> trasee;
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
            trasee.push_back(std::make_unique<Traseu_marcat>(marcaj[random]));
        }
        else {
            trasee.push_back(std::make_unique<Traseu_nemarcat>());
        }
    }

    alege_traseu(nr_trasee, traseu, meteo, trasee);
   /* for (int i = 0; i < nr_trasee; i++) {
        if (traseu[i].get_tip_poteca() == "amenajata") {
            int random = (rand() % nr_marcaje);
            t_marcat.push_back(std::make_unique<Traseu_marcat>(traseu[i], marcaj[random]));
            t_marcat.back()->set_poz(i);
        }
        else {
            t_nemarcat.push_back(std::make_unique<Traseu_nemarcat>(traseu[i]));
            t_nemarcat.back()->set_poz(i);
        }
    }*/

    /*if (alegere == 1) {
        int random = (rand() % t_marcat.size());
        std::cout << *t_marcat[random];
        int random_vreme = (rand() % nr_trasee);
        std::cout << meteo[random_vreme];
        float timp_final =t_marcat[random]->timp_traseu() + meteo[random_vreme].influenta_vreme();
        if( (timp_final - (int) timp_final) > 0.6)
            timp_final = timp_final + 0.4;

        std::cout << "\n*********************** Calculul aproximativ al timpului pe traseu *********************\n";
        std::cout << int (timp_final) << " ore si " << (timp_final - (int)timp_final) * 100 << " minute.\n";
    }
    else {
        int random = (rand() % t_nemarcat.size());
        std::cout << random << "\n";
        int random_vreme = (rand() % nr_trasee);
        std::cout << *t_nemarcat[random];
        std::cout << meteo[random_vreme];
        float timp_final = t_nemarcat[random]->timp_traseu() + meteo[random_vreme].influenta_vreme();
        if( (timp_final - (int) timp_final) > 0.6)
            timp_final = timp_final + 0.4;
        std::cout << "\n*********************** Calculul aproximativ al timpului pe traseu *********************\n";
        std::cout << int (timp_final) << " ore si " << (timp_final - (int)timp_final) * 100 << " minute.\n";
        t_nemarcat[random]->obiectiv_nou(meteo[random_vreme]);
    }*/

    t_marcat.clear();
    t_nemarcat.clear();
    trasee.clear();
    fin_T.close();
    fin_M.close();
    fin_Meteo.close();
    fin_A.close();

    return 0;
}
