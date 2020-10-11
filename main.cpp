#include <iostream>

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
};

Traseu::Traseu() {
    std::cout << "Constructor fara parametri \n";
    forma = "-"; //pentru verificare am pus "-" in loc de "". Acest lucru va fi modificat.
    culoare = "-";
    altitudine = 0;

    std::cout << "\t\t" << this->forma << " " << culoare << " " << altitudine << "\n"; //afisarea informatiilor pentru verificare
}

Traseu::Traseu(std::string forma) {
    std::cout << "Constructor cu parametrul de forma \n";
    this->forma = forma;
    culoare = "-";
    altitudine = 0;

    std::cout << "\t\t" << this->forma << " " << culoare << " " << altitudine << "\n";
}

Traseu::Traseu(std::string forma, std::string culoare) {
    std::cout << "Constructor cu 2 parametri -> forma + culoare\n";
    this->forma = forma;
    this->culoare = culoare;
    altitudine = 0;

    std::cout << "\t\t" << this->forma << " " << culoare << " " << altitudine << "\n";
}

Traseu::Traseu(std::string forma, std::string culoare, int altitudine) {
    std::cout << "Constructor cu 3 parametri -> forma + culaore + altitudine\n";
    this->forma = forma;
    this->culoare = culoare;
    this->altitudine = altitudine;

    std::cout << "\t\t" << this->forma << " " << culoare << " " << altitudine << "\n";
}

Traseu::Traseu(Traseu& traseu) {
    std::cout << "Constructorul de copiere \n";
    forma = traseu.forma;
    culoare = traseu.culoare;
    altitudine = traseu.altitudine;

    std::cout << "\t\t" << this->forma << " " << culoare << " " << altitudine << "\n";
}

Traseu::~Traseu() {
    std::cout << "Deconstructor \n";
}

int main() {
    Traseu t1;
    Traseu t2("dunga");
    Traseu t3("cruce", "rosie");
    Traseu t4("cruce", "albastra", 1892);
    Traseu t5(t1);
    return 0;
}
