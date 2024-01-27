# Munchkin Card Game Simulation

This is a small simulation of the card game Munchkin. In this project, I applied object-oriented programming (OOP) concepts such as polymorphism, design patterns, and inheritance. Specifically, I used the factory design pattern and the composite design pattern.

## Description

The goal of the game is to win battles and reach level 10. The game is designed for 2-6 players.

### Setup

1. Choose the number of players in the game.
2. Each player selects their name and character.

### Gameplay

- During a player's turn, they choose the top card of the deck and play it.
- If a player reaches level 10, they win. If a player's health points reach zero, they lose.
- The game ends when all players reach zero health points or level 10.

### Player Characteristics

Each player has the following characteristics:
- Name
- Level (1-10)
- Force
- Health points
- Coins

Every player starts with level 1, 10 coins, maximum health points (100), and force amount of 5.

#### Characters:

1. **Rogue**:
    - Receives twice the number of coins from a card.

2. **Wizard**:
    - Receives twice the amount of health points when healed from a card.

3. **Fighter**:
    - Attack strength is calculated as twice the player's force plus level.

### Cards

There are at least five types of cards in the game. Each played card is returned to the deck.

#### Type of Cards:

1. **Battle Cards**:
    - These cards can lead to a win or loss.
    - Win: If the player's attack strength (force + level) exceeds the force of the card, the player wins and gains the loot described on the card, upgrading by one level.
    - Loss: If the player's attack strength is insufficient, they lose and take damage as described on the card (minimum health points is zero).

##### Type of Battle Cards:

- **Goblin**: force 6, loot 2, damage 10.
- **Vampire**: force 10, loot 2, damage 10. If a player loses to a vampire, their force downgrades by 1.
- **Dragon**: force 25, loot 1000, damage – all of the health points of the player fighting the dragon.

- **The Gang card**: This card groups up to 3 battle cards. When a player encounters this card, they battle against all the battle cards in the gang.

2. **Other Cards**:
    - **Merchant**: Allows a player to buy a force potion or health potion if they have enough coins, or do nothing.
    - **Treasure**: Contains 10 coins which the player receives.
    - **Pitfall**: Decreases the health points of a player by 10, unless the player is a rogue.
    - **Barfight**: Decreases the health points of a player by 10, unless the player is a fighter.
    - **Fairy**: Raises the health points of a wizard by 10. Since a wizard receives double healing, they gain 20 health points. For other characters, this card has no effect.

### Leaderboard

At the end of the game, the leaderboard is printed:
- The player who reached level 10 first is listed first.
- The player who lost all their health points first is listed last.