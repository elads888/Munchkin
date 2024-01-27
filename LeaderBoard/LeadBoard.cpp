#include "LeadBoard.h"

LeadBoard::LeadBoard() {
    std::cout << "seggy" << std::endl;
}

void LeadBoard::addWinner(std::unique_ptr<Player>& ptrPlayer)
{
    this->m_winners.push_back(std::move(ptrPlayer));
}

void LeadBoard::addLoser(std::unique_ptr<Player>& ptrPlayer)
{
    this->m_losers.push_back(std::move(ptrPlayer));
}

void LeadBoard::printLeadBoard(const std::deque<std::unique_ptr<Player>>& playerQueue) const
{
    int ranking = 1;
    printLeaderBoardStartMessage();
    for (const std::unique_ptr<Player>& player: m_winners)
    {
        printPlayerLeaderBoard(ranking,*player);
        ranking++;
    }
    for (const std::unique_ptr<Player>& player: playerQueue)
    {
        printPlayerLeaderBoard(ranking, *player);
        ranking++;
    }
    for (int i = m_losers.size() - 1; i>=0; i--)
    {
        printPlayerLeaderBoard(ranking, *m_losers.at(i));
        ranking++;
    }
}
