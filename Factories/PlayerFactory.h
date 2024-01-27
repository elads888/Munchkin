#include "../Players/Player.h"
#include "../Players/Wizard.h"
#include "../Players/Fighter.h"
#include "../Players/Rogue.h"


class PlayerFactory{
private:
    Player* FactoryMethod(const std::string& type, const std::string& name);
public:
    PlayerFactory() = default;
    PlayerFactory(const PlayerFactory& playerFactory) = delete;
    PlayerFactory& operator=(const PlayerFactory& playerFactory) = delete;
    ~PlayerFactory() = default;
    Player* CreatePlayer(const std::string& type, const std::string& name);
};