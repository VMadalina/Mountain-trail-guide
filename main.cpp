#include <iostream>
#include <cmath>

class Traseu {
    std::string forma;
    std::string culoare;
    int altitudine;

public:
   Traseu();
   explicit Traseu(std::string);
   explicit Traseu(std::string, std::string);
   explicit Traseu(std::string, std::string, int);
   Traseu(Traseu&);
   ~Traseu();

   void info_sup();
   void timp_aprox(int, std::string);
};

Traseu::Traseu() {
    std::cout << "Traseul ales: ";
    forma = "-";
    culoare = "-";
    altitudine = 0;

    std::cout << this->forma << " " << culoare << " cu altitudinea initiala " << altitudine << "m\n"; //afisarea informatiilor pentru verificare
}

Traseu::Traseu(std::string forma) {
    std::cout << "Traseul ales: ";
    this->forma = forma;
    culoare = "-";
    altitudine = 0;

    std::cout << this->forma << " " << culoare << " cu altitudinea initiala " << altitudine << "m\n";
}

Traseu::Traseu(std::string forma, std::string culoare) {
    std::cout << "Traseul ales: ";
    this->forma = forma;
    this->culoare = culoare;
    altitudine = 0;

    std::cout << this->forma << " " << this->culoare << " cu altitudinea initiala " << altitudine << "m\n";
}

Traseu::Traseu(std::string forma, std::string culoare, int altitudine) {
    std::cout << "Traseul ales: ";
    this->forma = forma;
    this->culoare = culoare;
    this->altitudine = altitudine;

    std::cout << this->forma << " " << this->culoare << " cu altitudinea initiala " << this->altitudine << "m\n";
}

Traseu::Traseu(Traseu& traseu) {
    std::cout << "Constructorul de copiere: \n";
    forma = traseu.forma;
    culoare = traseu.culoare;
    altitudine = traseu.altitudine;

    std::cout << this->forma << " " << culoare << " cu altitudinea initiala " << altitudine << "m\n";
}

Traseu::~Traseu() {
    std::cout << "\n Având aceste cunoştinţe şi noţiuni poţi aborda şi calcula mai bine traseele tale pe munte, astfel încât, să reduci riscurile la minim. Drum bun!:) \n";
}

void Traseu::info_sup() {
        std::cout << "\n******************************* Informatii suplimentare legate de traseul ales ******************************\n\n";

        if (culoare == "rosie" || culoare == "rosu") {
            std::cout << "Traseul are un grad mare de dificultate si dureaza aproximativ 5-9h\n";
            std::cout << "Diferenta de nivel este intre 800-1 500 m, efortul fizic este sporit si aveti nevoie de ceva antrenament inainte, pentru ca urcusul este continuu si abrupt.\n";
            std::cout << "Altitudinea in care va incadrati va fi intre " << altitudine + 800 << "m si " << altitudine + 1500 << "m.\n";
        }
        if (culoare == "albastra" || culoare == "albastru") {
            std::cout << "Traseul are un grad mediu de dificultate si dureaza aproximativ 4-8h\n";
            std::cout
                    << "Diferenta de nivel este intre 500-1 000 m si efortul fizic depus este considerabil, insa se poate urca si in lipsa unei conditii fizice deosebite\n";
            std::cout << "Altitudinea in care va incadrati va fi intre " << altitudine + 500 << "m si "
                      << altitudine + 1000 << "m.\n";
        }
        if (culoare == "galben" || culoare == "galbena") {
            std::cout << "Traseul are un grad mic de dificultate si dureaza aproximativ 3-6h\n";
            std::cout << "Diferenta de nivel este intre 300-700 m si efortul fizic este redus.\n";
            std::cout << "Altitudinea in care va incadrati va fi intre " << altitudine + 300 << "m si "
                      << altitudine + 700 << "m.\n";
        }

        if(forma == "dunga" || forma == "banda")
            std::cout <<  "Dunga verticala, marcheaza traseul principal, de cele mai multe ori pe cel de creasta.\n";
        if(forma == "cruce")
            std::cout << "Crucea este folosita pentru traseele care se intersecteaza cu altele, in special cu cel principal marcat cu banda.\n";
        if(forma == "bulina" || forma == "punct")
            std::cout << "Bulina este folosita pentru traseele circulare de tipul dus-intors";
        if(forma == "triunghi")
            std::cout << "Triunghiul este de regula folosit pentru traseele secundare care vin din vai.";

}

void Traseu::timp_aprox(int altitudine_maxima, std::string tip_poteca) {
    std::cout << "\n********************** Calculul aproximativ al timpului pe traseu *********************\n\n";

    int dif_altitudine = altitudine_maxima - altitudine;
    if (tip_poteca == "amenajata"){
        std::cout << "Urcarea pe poteca amenajata va dura aproximativ " << round(dif_altitudine / 350.0 )<< " ore.\n";
        std::cout << "Coborarea pe poteca amenajata va dura aprox " << round(dif_altitudine / 450.0) << " ore.\n";
    }
    if (tip_poteca == "neamenajata"){
        std::cout << "Urcarea pe poteca neamenajata va dura aproximativ " << round(dif_altitudine / 250.0 )<< " ore.\n";
        std::cout << "Coborarea pe poteca neamenajata va dura aprox " << round(dif_altitudine / 400.0) << " ore.\n";
    }

}

int main() {
    Traseu t("cruce", "rosie", 324);
    t.info_sup();
    t.timp_aprox(2125, "neamenajata");
    return 0;
}
