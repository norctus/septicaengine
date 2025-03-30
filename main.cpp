#include "septica.hpp"

int main() {
    srand(time(0));

    std::vector<Carte> carti = Pachet::generarePachet(10);
    Pachet pachet(Pachet::generarePachet());
    pachet.amestecarePachet();
    
    Jucator darius("Darius", 1);
    Jucator edi("Edi", 1);
    std::vector<Jucator> players;
    players.push_back(std::move(darius));
    players.push_back(std::move(edi));

    Septica::distribuirePachet(pachet, players);
    players[1].printPachet();
    players[1].printData();

    players[0].printPachet();
    players[0].printData();

    pachet.printPachet();

    return 0;
}