#include "septica.hpp"

Septica::Septica(std::shared_ptr<Pachet> pachetSeptica, std::vector<std::shared_ptr<Jucator>> jucatori) : pachetSeptica(pachetSeptica), jucatori(jucatori) {
    std::string key;
    for(auto& jucator : jucatori) {
        playerScore.insert({jucator->getName(), 0});
    }
}

void Septica::distribuirePachet() {
    int nrJucatori = jucatori.size();
    int cartiPerJucator = 6;
    while (pachetSeptica->getCarti().size() < nrJucatori * cartiPerJucator) {
        std::cout << "Not enough cards! Lowering the number of cards per player\n";
        --cartiPerJucator;
    }

    for (auto& jucator : jucatori) {
        auto& cartiJucator = jucator->getPachet();
        for (int i = 0; i < cartiPerJucator; i++) {
            cartiJucator.push_back(pachetSeptica->getCarti().back());
            pachetSeptica->getCarti().pop_back();
        }
    }

}

void Septica::startGame() {
    std::cout << "========= STARTING GAME ============\n\n";
    while(nextRound) {
        roundStart();
    }
}

void Septica::roundStart() {
    
}

void Septica::printJucatori() {
    for(const auto& jucator: jucatori) {
        jucator->printData();
        jucator->printPachet();
        // std::cout << playerScore[jucator->getName()];
    }
}