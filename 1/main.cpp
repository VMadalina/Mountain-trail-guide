#include <iostream>

class Persoana {
public:
    Persoana(std::string nume);
    ~Persoana();

    void saluta();

private:
    std::string nume;

    void secret();
};

Persoana::Persoana(std::string nume) {
    this->nume = nume;
    std::cout << "In constructor!\n";
}

Persoana::~Persoana() {
    std::cout << "In destructor!\n";
}

void Persoana::saluta() {
    std::cout << "Sunt " << nume << "!\n";
}

void Persoana::secret() {
    std::cout << "In functie membru privata!\n";
}

int main() {
    Persoana p("Marius");
    p.saluta();
    // p.secret();  // eroare: nu putem apela functii membru private
    // std::cout << p.nume;  // eroare: nu putem accesa atribute private
    // Persoana pers;  // eroare: nu exista constructorul Persoana::Persoana()
    return 0;
}