cmake_minimum_required(VERSION 3.20)
project(munchkin)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall -pedantic-errors -Werror -DNDEBUG")
add_executable(munchkin main.cpp utilities.cpp Factories/PlayerFactory.cpp Factories/CardFactory.cpp
        Players/Player.cpp Players/Wizard.cpp Players/Rogue.cpp Players/Fighter.cpp
        Cards/Barfight.cpp Cards/BattleCards.cpp Cards/Card.cpp Cards/Dragon.cpp Cards/Dragon.cpp
        Cards/Fairy.cpp Cards/Goblin.cpp Cards/Merchant.cpp Cards/Pitfall.cpp Cards/Treasure.cpp
        Cards/Vampire.cpp Cards/Gang.cpp
        Munchkin.cpp)
