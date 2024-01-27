
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include <string>
#include "../Exception.h"

class Player
        {
protected:
    std::string m_name;
    int m_coins = 10;
    int m_level = 1;
    int m_force = 5;
    int m_hp = 100;

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    virtual void printDetails(std::ostream& os) const;

        public:
            static const int MAX_LEVEL = 10;
            static const int MAX_HP = 100;
            /**
             *Constructor of a player
             * @param Name - The name that is given to the player that's created
             * @param HP - the amount of life that is given to the player
             * @param Force - the amount of force that is given to the player
             */

            explicit Player(const std::string& Name): m_name(Name){};
            /**
             *
             * player - copy constructor, copies all parameters of one player to another
             */
            Player(const Player& otherPlayer) = delete;
            /**
             * Assignment operator.
             * @return the player that has been assigned to another player.
             */
            Player & operator=(const Player &) = delete;
            /**
             * destructor
             */
            virtual ~Player() = default;
            /**
             *a function that raises the level of a particular player by one
             */
            void levelUp();
            /**
             * a function that shows the level of a specific player
             * @return
             */
            int getLevel() const;
            /**
             *
             * @param forceToAdd - the amount of force to add to the player
             *
             */
            void buff(int forceToAdd);
            /**
             *
             * @param HPToAdd - the amount of HP to add to the player
             * @return
             */
            virtual void heal(int HPToAdd);
            /**
             *
             * @param HPToReduce - The amount of HP to reduce from the player
             *
             */
            void damage(int HPToReduce);
            /**
             *
             * @return - true if the player has 0 HP
             */
            bool isKnockedOut() const;
            /**
             *
             * @param coinsToAdd - the amount of coins to add to the player
             */
            virtual void addCoins(int coinsToAdd);
            /**
             *
             * @return - The attacks strength of the player
             */
             /**
              *
              * @param coinsToPay - The amount of coins to reduce from m_coins
              */
             bool pay(int coinsToPay);
            virtual int getAttackStrength() const;
            std::string getName() const;
            int getCoins() const;

        };
#endif //EX2_PLAYER_H
