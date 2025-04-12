#include "septica.hpp"

Septica::Septica(std::shared_ptr<Pachet> pachetSeptica, std::vector<std::shared_ptr<Jucator>> jucatori) : pachetSeptica(pachetSeptica), jucatori(jucatori) {
    std::string key;
    for(auto& jucator : jucatori) {
        playerScore.insert({jucator->getName(), 0});
    }
}

void Septica::distribuirePachet() {
    int nrJucatori = jucatori.size();
    if (pachetSeptica->getCarti().size() < nrJucatori * 5) {
        std::cerr << "Not enough cards to distribute!\n";
        return;
    }

    for (auto& jucator : jucatori) {
        auto& cartiJucator = jucator->getPachet();
        for (int i = 0; i < 5; i++) {
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
        std::cout << playerScore[jucator->getName()];
    }
}