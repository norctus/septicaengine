#pragma once

#include "pachet.hpp"

// =============== Jucator class ===============
class Jucator {
    public:
        Jucator() {}
        Jucator(const std::string& nume) : nume(nume) {}


        std::string printData();

        std::string printPachet();

        std::vector<Carte>& getPachet() { return mana; }

        std::string& getName() { return nume; }

    private:
        std::vector<Carte> mana;
        std::string nume;
};