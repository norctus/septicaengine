#pragma once

#include "jucator.hpp"
#include <unordered_map>

// ============== Septica game logic =================
class Septica {
    public:
        Septica(std::shared_ptr<Pachet> pachetSeptica, std::vector<std::shared_ptr<Jucator>> jucatori);

        void distribuirePachet();

        void startGame();

        void roundStart();

        void printJucatori();

    private:
        std::shared_ptr<Pachet> pachetSeptica;
        std::vector<std::shared_ptr<Jucator>> jucatori;
        bool nextRound = true;
        std::unordered_map<std::string, int> playerScore;

};

