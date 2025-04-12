#pragma once

#include "ddgtypes.hpp"
#include <iostream>
#include <string>

// ============================ Carte ============================
class Carte {
    public:
        Carte() {}

        Carte(const Culoare& culoare, const int& valoare) : culoare(culoare), valoare(valoare) {}

        Culoare getCuloare() const { return culoare; }

        int getValoare() const { return valoare; }

    private:
        Culoare culoare;
        int valoare;
};

// ======================== Culoare print operator =================
std::ostream& operator<<(std::ostream& os, const Culoare& cul) {
    switch(cul) {
        case Culoare::Toba:
            os << "Toba";
            break;
        case Culoare::Frunza:
            os << "Frunza";
            break;
        case Culoare::Ghinda:
            os << "Ghinda";
            break;
        case Culoare::InimaRosie:
            os << "InimaRosie";
            break;
    }

    return os;
}

// ======================== Carte print operator =================
std::ostream& operator<<(std::ostream& os, Carte& carte) {

    os << "Culoare: " << carte.getCuloare() << " Valoare: " <<  (carte.getValoare() == 11 ? "As" : std::to_string(carte.getValoare())) << "\n";
    return os;
}
