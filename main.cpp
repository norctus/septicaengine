#include <iostream>
#include "septica.hpp"

int main() {
    srand(time(0));

    std::vector<Carte> carti = Pachet::generarePachet(10);
    Pachet pachet(Pachet::generarePachet());
    pachet.amestecarePachet();
    
    Jucator darius("Darius", 1);
    Jucator edi("Edi", 1);

    Septica::distribuirePachet(pachet, {darius, edi});

    return 0;
}