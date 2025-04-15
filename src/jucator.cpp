#include "jucator.hpp"

std::string Jucator::printData() {
    std::cout << "Nume: " << nume;
    return "Nume: " + nume;
}

std::string Jucator::printPachet() {
    std::string ret = "";
    for(auto& carte : mana) {
        std::cout << carte;
        ret += carte;
    }

    return ret;
}
