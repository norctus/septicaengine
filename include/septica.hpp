#include "includes.hpp"

enum class Culoare {
    Toba,
    Frunza,
    Ghinda,
    InimaRosie
};

class Carte {
    public:
        Carte() {}

        Carte(const Culoare& culoare, const int& valoare) : culoare(culoare), valoare(valoare) {}

        Culoare getCuloare() {
            return culoare;
        }

        int getValoare() {
            return valoare;
        }

        ~Carte() {}

    private:
        Culoare culoare;
        int valoare;
};

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

std::ostream& operator<<(std::ostream& os, Carte& carte) {
    os << "Culoare: " << carte.getCuloare() << " Valoare: " << carte.getValoare();
    return os;
}

class Jucator;

class Pachet : public Carte {

    public:
        Pachet(const std::vector<Carte>& carti) : carti(carti) {}

        Pachet(){}

        void amestecarePachet() {
            Carte aux;

            for(size_t i = 0; i < carti.size() - 1; ++i) {
                int randomNumber = rand() % ( carti.size() - 1 );
                aux = carti[randomNumber];
                carti[randomNumber] = carti[i];
                carti[i] = aux;
            }
        }

        void printPachet() {
            for(auto it = carti.begin(); it < carti.end(); ++it) {
                std::cout << *it << " \n";
            }
        }

        std::vector<Carte> getPachet() {
            return carti;
        }

        static std::vector<Carte> generarePachet(int count) {
            std::vector<Carte> carti;
            int randomValue, randomColor;
            for(int i = 0; i < count; ++i) {
                randomValue = rand() % 12;
                randomColor = rand() % 4;
                Carte carte(static_cast<Culoare>(randomColor), randomValue);
                carti.push_back(carte);
            }
            return carti;
        }

        static void distribuirePachet(Pachet& pachet, const std::vector<Jucator> jucatori) {
            int randomNumber;
            for(auto &it : jucatori) {
                randomNumber = rand() % (pachet.carti.size());
                it->pachet.carti.assign(randomNumber + pachet.carti.begin(), randomNumber + pachet.carti.begin() + 5);
                pachet.carti.erase(randomNumber + pachet.carti.begin(), randomNumber + pachet.carti.begin() + 5);
            }
        }
        
        ~Pachet() {
            carti.clear();
        }

    private:
        std::vector<Carte> carti;

};

class Jucator : public Pachet {
    public:
        Jucator() {}
        Jucator(const Pachet& pachet, const std::string& nume, const int& echipa) : pachet(pachet), nume(nume), echipa(echipa) {}


        void printData() {
            std::cout << "Nume: " << nume << " Echipa: " << echipa;
        }

    private:
        Pachet pachet;
        std::string nume;
        int echipa;
};
