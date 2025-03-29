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

        int getValoare() const {
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

    os << "Culoare: " << carte.getCuloare() << " Valoare: " <<  (carte.getValoare() == 11 ? "As" : std::to_string(carte.getValoare())) << "\n";
    return os;
}

class Pachet : public Carte {

    public:
        Pachet(const std::vector<Carte>& carti) : carti(carti) {}

        Pachet(){}

        std::vector<Carte> getCarti() {
            return carti;
        }

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

        std::vector<Carte> getPachet() const {
            return carti;
        }

        static std::vector<Carte> generarePachet(int type = 0) {
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
        
        ~Pachet() {
            carti.clear();
        }

    private:
        std::vector<Carte> carti;

};

class Jucator : public Pachet {
    public:
        Jucator() {}
        Jucator(const std::string& nume, const int& echipa) : nume(nume), echipa(echipa) {}


        void printData() {
            std::cout << "Nume: " << nume << " Echipa: " << echipa;
        }

        void printPachet() {
            for(auto& carte : mana.getPachet())
                std::cout << carte;
        }

        Pachet getPachet() const {
            return mana;
        }

    private:
        Pachet mana;
        std::string nume;
        int echipa;
};

class Septica : public Pachet {
    public:
        Septica(){}

        static void distribuirePachet(Pachet& pachetSeptica, const std::vector<Jucator> jucatori) {
            int randomNumber;
            for(auto it = jucatori.begin(); it != jucatori.end(); ++it) {
                randomNumber = rand() % (pachetSeptica.getCarti().size());
                it->getPachet().getCarti().assign(randomNumber + pachetSeptica.getCarti().begin(), randomNumber + pachetSeptica.getCarti().begin() + 5);
                pachetSeptica.getCarti().erase(randomNumber + pachetSeptica.getCarti().begin(), randomNumber + pachetSeptica.getCarti().begin() + 5);
            }
        }
};