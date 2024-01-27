#include "Rogue.h"
#include "../utilities.h"

void Rogue::addCoins(int coinsToAdd)
{
    if(coinsToAdd < 0)
    {
        coinsToAdd = 0;
    }
    m_coins += coinsToAdd*2;
}
void Rogue::printDetails(std::ostream &os) const
{
    printPlayerDetails(os,m_name,"Rogue",m_level,m_force,m_hp,m_coins);
}