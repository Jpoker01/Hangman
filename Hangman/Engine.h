//
// Created by jirip on 20.10.2021.
//

#ifndef HANGMAN_ENGINE_H
#define HANGMAN_ENGINE_H

#include <array>
#include <locale>

#include "Player.h"
#include "Dictionary.h"

class Engine {
    Dictionary* m_dictionary;
    Player* m_player;
    std::string m_word;
    std::array<char, 26> m_letters;
    int m_progression;
public:
    Engine();
    void play();
private:
    char getUserInput() const throw(std::invalid_argument);
    void drawLayout() const;
    void printLine() const;
    void initLetters();
    bool isItLetter( const char letter) const;
    bool hasLetterBeenUsed(const char letter) const;
    bool isLetterInTheWord(const char letter) const;
    void removeFromLetters(const char letter);
    bool hasWordBeenGuessed();
    void resetLetters();
    bool isEnd();
};


#endif //HANGMAN_ENGINE_H
