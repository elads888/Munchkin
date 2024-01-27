#ifndef Munchkin_H_
#define Munchkin_H_

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <deque>
#include<cstdlib>
#include <ctime>
#include <windows.h>
#include <unistd.h>


#include "Exception.h"
#include "utilities.h"
#include "IncludeFiles.h"


class Munchkin {
private:
    static const int DECK_SIZE = 20;
    static const int MAX_GANG_SIZE = 3;
    int m_numberOfRounds = 0;
    std::deque<std::unique_ptr<Player>> m_playerQueue;
    std::deque<std::unique_ptr<Card>> m_cardQueue;
    std::set<std::string> m_cardName = {"Barfight", "Fairy", "Pitfall", "Dragon", "Goblin", "Vampire", "Merchant",
                                        "Treasure", "Gang"};
    std::set<std::string> m_gangMembers = {"Dragon", "Goblin", "Vampire"};
    std::set<std::string> m_playerCharacter = {"Rogue", "Wizard", "Fighter"};

    std::vector<std::unique_ptr<Player>> m_winners;
    std::vector<std::unique_ptr<Player>> m_losers;

    void generateRandomDeck(const std::string fileName);

    void addWinner(std::unique_ptr<Player> &ptrPlayer);

    void addLoser(std::unique_ptr<Player> &ptrPlayer);

    void initialCardQueue(const std::string &fileName);

    void initialPLayerQueue();

    bool inCardNames(const std::string &cardType) const;

    bool inPlayerCharacters(const std::string &character) const;

    Card *cardFactory(const std::string &type);

    Player *playerFactory(const std::string &type, std::string &name);

    static void checkPlayerName(const std::string &playerName);

    static bool containsOnlyLetters(const std::string &name);

    void splitNameAndCharacter(std::string &nameAndCharacter, std::string &name, std::string &character);

    void generateGang(std::ofstream &deck, int gang_size, int curr_deck_size);

public:

    Munchkin(const std::string fileName);

    void playRound();

    void printLeaderBoard() const;

    bool isGameOver() const;

    int getNumberOfRounds() const;
};

#endif /* Munchkin_H_ */
