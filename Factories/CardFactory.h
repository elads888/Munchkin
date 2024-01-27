#include "../Cards/Card.h"
#include "../Cards/Barfight.h"
#include "../Cards/Dragon.h"
#include "../Cards/Fairy.h"
#include "../Cards/Gang.h"
#include "../Cards/Goblin.h"
#include "../Cards/Dragon.h"
#include "../Cards/Merchant.h"
#include "../Cards/Pitfall.h"
#include "../Cards/Treasure.h"
#include "../Cards/Vampire.h"

class CardFactory{
private:
    Card* FactoryMethod(const std::string& type);
public:
    CardFactory() = default;
    CardFactory(const CardFactory& cardFactory) = delete;
    CardFactory& operator=(const CardFactory& cardFactory) = delete;
    ~CardFactory() = default;
    Card* CreateCard(const std::string& type);
};