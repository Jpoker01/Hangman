//
// Created by jirip on 20.10.2021.
//

#ifndef HANGMAN_DICTIONARY_H
#define HANGMAN_DICTIONARY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <locale>

class Dictionary {
    std::vector<std::string> m_words;
public:
    Dictionary();
    void loadFromFile(const std::string fileName) throw(std::invalid_argument);
    bool checkWord(const std::string word) const;
    bool isAlreadyUsed(const std::string word) const;
    void removeFromDictionary(const std::string word);
    void addToDictionary(const std::string word);
    std::string convertToUpperCase(std::string word);
    std::string chooseRandomWord();
    void printDictionary() const;
};


#endif //HANGMAN_DICTIONARY_H
