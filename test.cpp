//
// Created by Madalina on 11/10/2020.
//

#include <iostream>

class umbrela {
protected:
    std::string culoare;
public:
    umbrela(std::string cul) : culoare(cul) {
        std::cout << "constructor baza " << culoare << "\n";
    }

    umbrela(umbrela& u) : culoare(u.culoare + " copie") {
        std::cout << "constructor copiere baza " << u.culoare << "\n";
    }

    umbrela& operator=(const umbrela &rhs) {
        std::cout << "op= baza " << culoare << " " << rhs.culoare << "\n";
        culoare = rhs.culoare;
        return *this;
    }

    ~umbrela() {
        std::cout << "destructor baza " << culoare << "\n";
    }

};

int main() {

    umbrela u("portocalie");
    return 0;
}