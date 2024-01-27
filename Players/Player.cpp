#include "Player.h"
#include "../utilities.h"

void Player::printDetails(std::ostream &os) const
{
    os << m_name;
}

void Player::levelUp()
{
    if(m_level == MAX_LEVEL)
    {
        return;
    }
    m_level ++;
}
int Player::getLevel() const
{
    return m_level;
}
void Player::buff(int forceToAdd)
{
    if(m_force + forceToAdd < 0)
    {
        m_force = 0;
        return;
    }
    m_force += forceToAdd;
}
void Player::heal(int HPToAdd)
{
    if(HPToAdd < 0)
    {
        HPToAdd = 0;
    }
    if(m_hp == MAX_HP)
    {
        return;
    }
    if(m_hp + HPToAdd > MAX_HP)
    {
        m_hp = MAX_HP;
    }
    else
    {
        m_hp += HPToAdd;
    }
}
void Player::damage(int HPToReduce)
{
    if (HPToReduce < 0)
    {
        return;
    }
    if(m_hp - HPToReduce < 0)
    {
        m_hp = 0;
    }
    else
    {
        m_hp -= HPToReduce;
    }
}
bool Player::isKnockedOut() const
{
    if(m_hp == 0)
    {
        return true;
    }
        return false;
}
void Player::addCoins(int coinsToAdd)
{
    if(coinsToAdd < 0)
    {
        coinsToAdd = 0;
    }
    m_coins += coinsToAdd;
}
bool Player::pay(int coinsToPay)
{
    if(coinsToPay <= 0)
    {
        return true;
    }
    if(m_coins < coinsToPay)
    {
        return false;
    }
    else
    {
        m_coins -= coinsToPay;
        return true;
    }
}
int Player::getAttackStrength() const
{
    int attackStrength = m_level + m_force;
    return attackStrength;
}
std::ostream& operator<<(std::ostream& os,const Player& player)
{
    player.printDetails(os);
    return os;
}

int Player::getCoins() const
{
    return m_coins;
}

std::string Player::getName() const
{
    return m_name;
}
