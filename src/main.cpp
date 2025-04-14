#include "septica.hpp"

int main() {
    srand(time(0));

    auto pachet = std::make_shared<Pachet>(Pachet::generarePachet());
    pachet->amestecarePachet();
    
    std::vector<std::shared_ptr<Jucator>> jucatori = {
        std::make_shared<Jucator>("Darius"),
        std::make_shared<Jucator>("Edi"),
        std::make_shared<Jucator>("Ileana"),
        std::make_shared<Jucator>("Robi"),
        std::make_shared<Jucator>("Dori"),
        std::make_shared<Jucator>("Horia")
    };

    Septica septica(pachet, jucatori);
    septica.distribuirePachet();
    // septica.printJucatori();

    return 0;
}