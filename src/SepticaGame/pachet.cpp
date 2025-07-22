#include "pachet.hpp"

void Pachet::amestecarePachet() {
    Carte aux;

    for(size_t i = 0; i < carti.size() - 1; ++i) {
        int randomNumber = rand() % ( carti.size() - 1 );
        aux = carti[randomNumber];
        carti[randomNumber] = carti[i];
        carti[i] = aux;
    }
}

void Pachet::printPachet() {
    for(auto it = carti.begin(); it < carti.end(); ++it) {
        std::cout << *it;
    }
}

std::vector<Carte> Pachet::generarePachet() {
    std::vector<Carte> carti;
    std::vector<Culoare> culoriPosibile = {Culoare::Toba, Culoare::Frunza, Culoare::Ghinda, Culoare::InimaRosie};
    std::vector<int> valoriPosibile = {2, 3, 4, 7, 8, 9, 10, 11};

    int randomValue, randomColor;
    for(const auto& culoare : culoriPosibile) {
        for(const auto& valoare : valoriPosibile ) {
            carti.push_back({culoare, valoare});
        }
    }
    return carti;
}


