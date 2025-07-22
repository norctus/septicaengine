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

        std::string culoareAsString() const;

        int getValoare() const { return valoare; }

    private:
        Culoare culoare;
        int valoare;
};

std::ostream& operator<<(std::ostream& os, const Culoare& cul);

std::ostream& operator<<(std::ostream& os, const Carte& carte);

std::string& operator+=(std::string& str, const Carte& carte);