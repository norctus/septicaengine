#include "carte.hpp"

// ==================== Culoare to string =======================
std::string Carte::culoareAsString() const {
    switch(culoare) {
        case Culoare::Toba:
            return "Toba";
        case Culoare::Frunza:
            return "Frunza";
        case Culoare::Ghinda:
            return "Ghinda";
        case Culoare::InimaRosie:
            return "InimaRosie";
        default:
            throw std::runtime_error("Incorrect color");
    }
}

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
std::ostream& operator<<(std::ostream& os, const Carte& carte) {

    os << "Culoare: " << carte.getCuloare() << " Valoare: " <<  (carte.getValoare() == 11 ? "As" : std::to_string(carte.getValoare()));
    return os;
}

// ================ Carte concat operator ===========
std::string& operator+=(std::string& str, const Carte& carte) {
    str += carte.culoareAsString() + std::to_string(carte.getValoare());
    return str;
}