#include <iostream>
#include <cmath>

class Traseu {
    std::string tip_poteca; //amenajata, neamenajata
    int altitudine; //altitudinea de plecare

public:
    Traseu(std::string, int);
    void timp_aprox(int) const; //aproximare a timpului de urcare/coborare in functie de poteca aleasa si altitudinea maxima la care se doreste sa se ajunga
    int get_alt() const;
};

Traseu::Traseu(std::string tip_poteca = "", int altitudine = 0) {
    this->tip_poteca = tip_poteca;
    this->altitudine = altitudine;
}

int Traseu::get_alt() const {
    return altitudine;
}

void Traseu::timp_aprox(int altitudine_maxima) const {
    std::cout << "\n*********************** Calculul aproximativ al timpului pe traseu *********************\n\n";

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

class Marcaj {
    std::string forma; // cruce, dunga/banda, bulina/punct, triunghi
    std::string culoare; // rosu, albastru, galben

public:
   Marcaj(std::string, std::string);
   Marcaj(Marcaj&);
   ~Marcaj();

   void info_sup(Traseu) const; //informatii suplimentare generale legate de traseul ales, in functie de forma si culoare
};

Marcaj::Marcaj(std::string forma = "-", std::string culoare = "-") {
    std::cout << "Marcajul ales petru acest traseu: ";
    this->forma = forma;
    this->culoare = culoare;

    std::cout << this->forma << " " << this->culoare << "\n";
}

Marcaj::Marcaj(Marcaj& traseu) {
    std::cout << "Constructorul de copiere: \n";
    this->forma = traseu.forma;
    this->culoare = traseu.culoare;

    std::cout << this->forma << " " << this->culoare << " cu altitudinea initiala " << "\n";
}

Marcaj::~Marcaj() {
    std::cout << "\nAvand aceste cunostinte si notiuni poti aborda si calcula mai bine traseele tale pe munte, astfel incat, sa reduci riscurile la minim. Drum bun!:) \n";
}

void Marcaj::info_sup(Traseu tr) const{
        std::cout << "\n********************************* Informatii suplimentare legate de traseul ales *********************************\n\n";
        int alt = tr.get_alt();
        if (culoare == "rosie" || culoare == "rosu") {
            std::cout << "Traseul are un grad mare de dificultate si dureaza aproximativ 5-9h\n";
            std::cout << "Diferenta de nivel este intre 800-1 500 m, efortul fizic este sporit si aveti nevoie de ceva antrenament inainte, pentru ca urcusul este continuu si abrupt.\n";
            std::cout << "Altitudinea in care va incadrati va fi intre " << alt + 800 << "m si " << alt + 1500 << "m.\n";
        }
        if (culoare == "albastra" || culoare == "albastru") {
            std::cout << "Traseul are un grad mediu de dificultate si dureaza aproximativ 4-8h\n";
            std::cout << "Diferenta de nivel este intre 500-1 000 m si efortul fizic depus este considerabil, insa se poate urca si in lipsa unei conditii fizice deosebite\n";
            std::cout << "Altitudinea in care va incadrati va fi intre " << alt + 500 << "m si " << alt + 1000 << "m.\n";
        }
        if (culoare == "galben" || culoare == "galbena") {
            std::cout << "Traseul are un grad mic de dificultate si dureaza aproximativ 3-6h\n";
            std::cout << "Diferenta de nivel este intre 300-700 m si efortul fizic este redus.\n";
            std::cout << "Altitudinea in care va incadrati va fi intre " << alt + 300 << "m si " << alt + 700 << "m.\n";
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

/*class Drumet {
    std::string conditie_fizica; //normala, buna, antrenata
    std::string echipament; //uzual, mediu, special

    Momentan nu stiu daca sa adaug aceasta clasa sau sa o regandescputin pentru a reusi sa fac mostenirile pt tema 2. Ideea era ca in functie de echipamentul si de conditia fizica pe care o are sa il informeze daca se
    poate deplasa pe traseul cu marcajul ales.
};*/

int main() {

    Traseu t("neamenajata", 234);
    Marcaj m("cruce", "rosie");

    m.info_sup(t);
    t.timp_aprox(2034);
    return 0;
}
