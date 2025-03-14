#include <iostream>
#include "septica.hpp"

int main() {
    srand(time(0));
    Carte carte1(Culoare::Toba, 3);
    Carte carte2(Culoare::InimaRosie, 4);
    std::vector<Carte> carti = Pachet::generarePachet(10);
    Pachet pachet(Pachet::generarePachet());
    pachet.amestecarePachet();
    Pachet pachet2({carte1, carte2});

    
    
    Jucator darius(pachet, "Darius", 1);
    darius.printData();
    darius.printPachet();

    return 0;
}