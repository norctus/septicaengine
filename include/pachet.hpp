#pragma once

#include "carte.hpp"
#include <vector>

// ============ Pachet class ================
class Pachet {

    public:
        Pachet(const std::vector<Carte>& carti) : carti(carti) {}

        Pachet(){}

        std::vector<Carte>& getCarti() { return carti; }

        void amestecarePachet();

        void printPachet();

        static std::vector<Carte> generarePachet();
        
        ~Pachet() { carti.clear(); }

    private:
        std::vector<Carte> carti;

};