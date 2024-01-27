#ifndef MUNCHKIN_EXCEPTION_H
#define MUNCHKIN_EXCEPTION_H

#include <stdexcept>
#include <string>

class PlayerExceptions : public std::runtime_error {
public:
    explicit PlayerExceptions(const std::string &what) : std::runtime_error(what) {};
};

class DeckExceptions : public std::runtime_error {
public:
    explicit DeckExceptions(const std::string &what) : std::runtime_error(what) {};
};

class CreateDeckException : public DeckExceptions {
public:
    explicit CreateDeckException() : DeckExceptions("Unable to create deck file") {};
};

class DeckFileNotFound : public DeckExceptions {
public:
    DeckFileNotFound() : DeckExceptions("Deck File Error: File not found") {};
};

class DeckFileFormatError : public DeckExceptions {
public:
    DeckFileFormatError(const std::string &line) : DeckExceptions(
            "Deck File Error: File format error in line " + line) {};
};

class DeckFileInvalidSize : public DeckExceptions {
public:
    DeckFileInvalidSize() : DeckExceptions("Deck File Error: Deck size is invalid") {};
};

class playerInvalidName : public PlayerExceptions {
public:
    explicit playerInvalidName(const std::string &what) : PlayerExceptions(what) {};
};

class playerNameLong : public playerInvalidName {
public:
    playerNameLong() : playerInvalidName("Player name too long") {};
};

class playerNumbersInName : public playerInvalidName {
public:
    playerNumbersInName() : playerInvalidName("Player name has invalid characters in it") {};
};

#endif //MUNCHKIN_EXCEPTION_H
