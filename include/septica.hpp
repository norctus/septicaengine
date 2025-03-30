#include "ddgtypes.hpp"

// ============================ Carte ============================
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

// ============ Pachet class ================
class Pachet {

    public:
        Pachet(const std::vector<Carte>& carti) : carti(carti) {}

        Pachet(){}

        std::vector<Carte>& getCarti() {
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
                std::cout << *it;
            }
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

// =============== Jucator class ===============
class Jucator {
    public:
        Jucator() {}
        Jucator(const std::string& nume, const int& echipa) : nume(nume), echipa(echipa) {}


        void printData() {
            std::cout << "Nume: " << nume << " | Echipa: " << echipa << "\n";
        }

        void printPachet() {
            for(auto& carte : mana)
                std::cout << carte;
        }

        std::vector<Carte>& getPachet() {
            return mana;
        }

    private:
        std::vector<Carte> mana;
        std::string nume;
        int echipa;
};

// ============== Septica game logic =================
class Septica {
    public:
        Septica(){}

        static void distribuirePachet(Pachet& pachetSeptica, std::vector<Jucator>& jucatori) {
            int nrJucatori = jucatori.size();
            if (pachetSeptica.getCarti().size() < nrJucatori * 5) {
                std::cerr << "Not enough cards to distribute!\n";
                return;
            }
    
            for (auto& jucator : jucatori) {
                auto& cartiJucator = jucator.getPachet();
                for (int i = 0; i < 5; i++) {
                    cartiJucator.push_back(pachetSeptica.getCarti().back());
                    pachetSeptica.getCarti().pop_back();
                }
            }
        }

    private:
        int rounds;
        std::vector<int> teamPoints;
        
};