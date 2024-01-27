#ifndef MUNCHKIN_LEADBOARD_H
#define MUNCHKIN_LEADBOARD_H

#include <vector>
#include <memory>
#include <deque>

#include "../Players/Player.h"
#include "../utilities.h"

class LeadBoard {
private:
    std::vector<std::unique_ptr<Player>> m_winners;
    std::vector<std::unique_ptr<Player>> m_losers;
public:

    LeadBoard();
    LeadBoard&  operator= (const LeadBoard& leadBoard) = delete;
    LeadBoard(const LeadBoard& leadBoard) = delete;
    void printLeadBoard(const std::deque<std::unique_ptr<Player>>& playerQueue) const;
    void addWinner(std::unique_ptr<Player>& ptrPlayer);
    void addLoser(std::unique_ptr<Player>& ptrPlayer);
};


#endif //MUNCHKIN_LEADBOARD_H
