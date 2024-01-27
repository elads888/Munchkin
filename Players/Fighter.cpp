
#include "Fighter.h"
#include "../utilities.h"
int Fighter::getAttackStrength() const
{
    int attackStrength = m_level + (m_force* 2);
    return attackStrength;
}
void Fighter::printDetails(std::ostream &os) const
{
    printPlayerDetails(os,m_name,"Fighter",m_level,m_force,m_hp,m_coins);
}