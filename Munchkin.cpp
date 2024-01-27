#include "Munchkin.h"
#include "utilities.h"

bool Munchkin::inCardNames(const std::string &cardType) const {
    for (const std::string &name: m_cardName) {
        if (name == cardType)
            return true;
    }
    return false;
}

Card* Munchkin::cardFactory(const std::string &type) {
    CardFactory factory;
    Card * card = factory.CreateCard(type);
    return card;
}

void Munchkin::initialCardQueue(const std::string &fileName) {
    std::ifstream source;
    try {
        source.open(fileName);
    }
    catch (const std::exception &exception) {
        throw (DeckFileNotFound());
    }
    std::string cardType;
    int lineCounter = 1;
    if (source.is_open()) {
        if (source.peek() == EOF) {
            source.close();
            throw (DeckFileInvalidSize());
        }
        while (std::getline(source, cardType)) {
            if (cardType == "Gang") {
                lineCounter++;
                Gang* gang_card = new Gang();
                do {
                    std::getline(source, cardType);
                    if (cardType != "EndGang")
                    {
                        Card * card = cardFactory(cardType);
                        BattleCards * battle_card = dynamic_cast<BattleCards *>(card); /**while always not be null because deck was verified*/
                        gang_card->addToGang(battle_card);
                        lineCounter++;
                        cardType.clear();
                    }
                    } while (cardType != "EndGang");
                m_cardQueue.push_back(std::unique_ptr<Card>(gang_card));
                lineCounter++;
                cardType.clear();
            }
            else if (inCardNames(cardType)) {
                Card * card = cardFactory(cardType);
                m_cardQueue.push_back(std::unique_ptr<Card>(card));
                lineCounter++;
                cardType.clear();
            }
            else { /*unknown card in deck*/
                const std::string line = std::to_string(lineCounter);
                source.close();
                throw (DeckFileFormatError(line));
            }
        }
        source.close();
    } else if (!source) {
        throw (DeckFileNotFound());
    }
    if (m_cardQueue.size() < 5) {
        throw (DeckFileInvalidSize());
    }
}


bool Munchkin::inPlayerCharacters(const std::string &character) const {
    for (const std::string &type: m_playerCharacter) {
        if (type == character) {
            return true;
        }
    }
    return false;
}

Player* Munchkin::playerFactory(const std::string &type, std::string &name) {
    PlayerFactory factory;
    Player *player = factory.CreatePlayer(type, name);
    return player;
}

void Munchkin::checkPlayerName(const std::string &playerName) {
    if (playerName.length() > 15) {
        throw (playerNameLong());
    }
    if (!containsOnlyLetters(playerName)) {
        throw (playerNumbersInName());
    }
}

bool Munchkin::containsOnlyLetters(const std::string &name) {
    for (char const &c: name) {
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) {
            return false;
        }
    }
    return true;
}

void Munchkin::splitNameAndCharacter(std::string &nameAndCharacter, std::string &name, std::string &character) {
    std::istringstream iss(nameAndCharacter);
    iss >> name;
    iss >> character;
}

void Munchkin::initialPLayerQueue() {
    std::string inputSize;
    int size = 0;
    do {
        printEnterTeamSizeMessage();
        std::getline(std::cin, inputSize);
        try {
            size = std::stoi(inputSize);
            if (size > 6 || size < 2) {
                printInvalidTeamSize();
            }
        }
        catch (const std::exception &e) {
            printInvalidTeamSize();
        }
    } while (size > 6 || size < 2);
    std::string name;
    std::string character;
    std::string nameAndCharacter;
    for (int i = 0; i < size; i++) {
        printInsertPlayerMessage();
        bool inputSuccess = false;
        do {
            std::getline(std::cin, nameAndCharacter);
            splitNameAndCharacter(nameAndCharacter, name, character);
            if (inPlayerCharacters(character)) {
                try {
                    checkPlayerName(name);
                    Player* player = playerFactory(character, name);
                    m_playerQueue.push_back(std::unique_ptr<Player>(player));
                    inputSuccess = true;
                }
                catch (const playerInvalidName &e) {
                    printInvalidName();
                }
            } else {
                try {
                    checkPlayerName(name);
                    printInvalidClass();
                }
                catch (const playerInvalidName &e) {
                    printInvalidName();
                }
            }
        } while (!inputSuccess);
    }

}


Munchkin::Munchkin(const std::string fileName) {
    generateRandomDeck(fileName);
    printStartGameMessage();
    initialCardQueue(fileName);
    initialPLayerQueue();
}

int Munchkin::getNumberOfRounds() const {
    return m_numberOfRounds;
}

void Munchkin::playRound() {
    int curNumberOfPlayers = m_playerQueue.size();
    printRoundStartMessage((getNumberOfRounds() + 1));
    sleep(1);
    for (int i = 0; i < curNumberOfPlayers; ++i) {
        printTurnStartMessage(m_playerQueue.front()->getName());
        std::cout << "The card that was drawn:"<< std::endl;
        std::cout<< *m_cardQueue.front() << std::endl;
        sleep(2);
        m_cardQueue.front()->applyEncounter(*(m_playerQueue.front()));
        if (m_playerQueue.front()->getLevel() == m_playerQueue.front()->MAX_LEVEL) {
            std::unique_ptr<Player> ptr = std::move(m_playerQueue.front());
            printPlayerWon(ptr);
            m_playerQueue.pop_front();
            addWinner(ptr);

        } else if (m_playerQueue.front()->isKnockedOut()) {
            std::unique_ptr<Player> ptr = std::move(m_playerQueue.front());
            printPlayerLost(ptr);
            m_playerQueue.pop_front();
            addLoser(ptr);
        } else {
            std::unique_ptr<Player> ptr = std::move(m_playerQueue.front());
            m_playerQueue.pop_front();
            m_playerQueue.push_back(std::move(ptr));
        }
        m_cardQueue.push_back(std::move(m_cardQueue.front()));
        m_cardQueue.pop_front();
    }
    m_numberOfRounds++;
}

bool Munchkin::isGameOver() const {
    if (m_playerQueue.size() == 0) {
        return true;
    } else {
        return false;
    }
}

void Munchkin::printLeaderBoard() const {
    int ranking = 1;
    printGameEndMessage();
    printLeaderBoardStartMessage();
    for (const std::unique_ptr<Player> &player: m_winners) {
        printPlayerLeaderBoard(ranking, *player);
        ranking++;
    }
    for (const std::unique_ptr<Player> &player: m_playerQueue) {
        printPlayerLeaderBoard(ranking, *player);
        ranking++;
    }
    for (int i = m_losers.size() - 1; i >= 0; i--) {
        printPlayerLeaderBoard(ranking, *m_losers.at(i));
        ranking++;
    }
}

void Munchkin::addWinner(std::unique_ptr<Player> &ptrPlayer) {
    m_winners.push_back(std::move(ptrPlayer));
}

void Munchkin::addLoser(std::unique_ptr<Player> &ptrPlayer) {
    m_losers.push_back(std::move(ptrPlayer));
}

void Munchkin::generateGang(std::ofstream &deck, int gang_size, int curr_deck_size) {
    deck << "Gang" << std::endl;
    for (int i = 0; i < gang_size; ++i) {
        auto it = m_gangMembers.begin();
        int random = rand() % m_gangMembers.size();
        std::advance(it, random);
        std::string card_name = *it;
        deck << card_name << std::endl;
    }
    deck << "EndGang";
    if (curr_deck_size + gang_size +2 < DECK_SIZE -1)
        deck << std::endl;
}

void Munchkin::generateRandomDeck(const std::string fileName) {
    std::ofstream deck(fileName);
    if (!deck.is_open())
        throw CreateDeckException();
    int curr_deck_size = 0;
    srand((unsigned) time(nullptr));
    while (curr_deck_size < DECK_SIZE){
        auto it = m_cardName.begin();
        int random = rand() % m_cardName.size();
        std::advance(it, random);
        std::string card_name = *it;
        if (card_name == "Gang")
        {
            int gang_size = (rand() % MAX_GANG_SIZE) +1;
            if (curr_deck_size + gang_size + 2 < DECK_SIZE) {
                generateGang(deck, gang_size, curr_deck_size);
                curr_deck_size += gang_size + 2;
            }
            else
                continue;
        }
        else {
            curr_deck_size ++;
            deck << card_name;
            if (curr_deck_size < DECK_SIZE)
                deck << std::endl;
        }
    }
    deck.close();
}

