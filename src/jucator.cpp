#include "jucator.hpp"

void Jucator::printData() {
    std::cout << "Nume: " << nume << "\n";
}

void Jucator::printPachet() {
    for(auto& carte : mana)
        std::cout << carte;
}
