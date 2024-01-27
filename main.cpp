#include "Munchkin.h"

int main() {
    Munchkin game("deck.txt");
    const int MAX_NUMBER_OF_ROUNDS = 100;
    while (!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS) {
        try {
            game.playRound();
        }
        catch (const std::exception &exception) {
            std::cout << exception.what() << std::endl;
            return 0;
        }
    }
    game.printLeaderBoard();
    return 0;
}


