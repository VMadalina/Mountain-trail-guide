#include "includes/Traseu.h"
#include "includes/Marcaj.h"
#include "includes/Traseu_nemarcat.h"
#include "includes/Excursie.h"
#include <fstream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>

int main() {
    srand((unsigned) time (nullptr));
    std::ifstream fin_T,  fin_M, fin_Meteo, fin_A;
    int nr_trasee = 0, nr_marcaje = 0;

    try {
        fin_T.exceptions(std::ifstream::failbit);
        fin_M.exceptions(std::ifstream::failbit);
        fin_Meteo.exceptions(std::ifstream::failbit);
        fin_A.exceptions(std::ifstream::failbit);
        fin_T.open("/files/Traseu.txt");
        fin_M.open("/files/Marcaj.txt");
        fin_Meteo.open ("/files/Meteo.txt");
        fin_T >> nr_trasee;
        fin_M >> nr_marcaje;
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
    Excursie excursie;

    for (int i = 0; i < nr_trasee; i++) {
        fin_T >> traseu[i];
        fin_Meteo >> meteo[i];
    }
   for (int i = 0; i < nr_marcaje; i++)
        fin_M >> marcaj[i];

    for (int i = 0; i < nr_trasee; i++)
    {
        int random = (rand() % nr_marcaje);
        excursie.adauga_traseu(traseu[i], marcaj[random]);
    }

    excursie.timp_total(meteo);

    trasee.clear();
    fin_T.close();
    fin_M.close();
    fin_Meteo.close();

    return 0;
}
