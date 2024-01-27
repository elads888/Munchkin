#include "Wizard.h"
#include "../utilities.h"

void Wizard::heal(int HPToAdd)
{
    if(HPToAdd < 0)
    {
        HPToAdd = 0;
    }
    if(m_hp == MAX_HP)
    {
        return;
    }
    if(m_hp + 2*HPToAdd > MAX_HP)
    {
        m_hp = MAX_HP;
    }
    else
    {
        m_hp += 2*HPToAdd;
    }
}

void Wizard::printDetails(std::ostream &os) const
{
    printPlayerDetails(os,m_name,"Wizard",m_level,m_force,m_hp,m_coins);
}
