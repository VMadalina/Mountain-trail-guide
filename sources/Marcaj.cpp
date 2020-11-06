//
// Created by Madalina on 02/11/2020.
//

#include "../includes/Marcaj.h"
#include <iostream>

Marcaj::Marcaj(std::string forma, std::string culoare) {
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
    //std::cout << "\nAvand aceste cunostinte si notiuni poti aborda si calcula mai bine traseele tale pe munte, astfel incat, sa reduci riscurile la minim. Drum bun!:) \n";
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

std::ostream& operator << (std::ostream& out, Marcaj& m) {
    out << "Traseul ales este " << m.forma << " " << m.culoare << ".\n";
    return out;
}