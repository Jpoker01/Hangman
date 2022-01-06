//
// Created by jirip on 20.10.2021.
//

#include "Dictionary.h"

Dictionary::Dictionary(){
    m_words = {"ALERGIE", "PENICILIN", "JIDLO", "DRAK", "ARASIDY"};
}

void Dictionary::removeFromDictionary(const std::string word){
    for (unsigned int i = 0; i < m_words.size(); i++){
        if (word == m_words.at(i)){
            m_words.erase(m_words.begin() + i);
        }
    }
}

////convert to upper case;
std::string Dictionary::convertToUpperCase(std::string word){
    for (unsigned int i = 0; i < word.size(); i++){
        word.at(i) = toupper(word.at(i));
    }
    return word;
}



void Dictionary::addToDictionary(const std::string word){
    if (checkWord(word)){
        if (!isAlreadyUsed(word)){
            std::string upperWord = convertToUpperCase(word);
            m_words.push_back(upperWord);
        }
        else {
            std::cerr << "Word has already been used" << std::endl;
        }
    } else {
        std::cerr << "The word is too long, too short or contains invalid characters. " << std::endl;
    }

}

void Dictionary::loadFromFile(const std::string fileName) throw(std::invalid_argument){
    std::fstream input (fileName);
    std::string word;

    if (input.is_open()){
        while (!input.eof()){
            input >> word;
            addToDictionary(word);
        }
    } else {
        throw std::invalid_argument("The given file could not be opened.");
    }

}

bool Dictionary::checkWord(const std::string word) const{
    bool okay = true;
    if (word.size() > 3 and word.size() < 10){
        for (unsigned int i = 0; i < word.size(); i++){
            if (!isalpha(word.at(i))){
                okay = false;
            }
        }
    } else {
        okay = false;
    }

    return okay;
}

////Je jiz slovo pouzito?
bool Dictionary::isAlreadyUsed(const std::string word) const{
    bool result = false;

    for (auto wordFromDictionary : m_words) {
        if (wordFromDictionary == word) {
            result = true;
        }
    }

    return result;
}


std::string Dictionary::chooseRandomWord(){
    int maxValue = m_words.size();
    std::srand(std::time(0));  // needed once per program run
    int randomWordIndex = std::rand() % maxValue;
    std::string chosenWord = m_words.at(randomWordIndex);
    m_words.erase(m_words.begin() + randomWordIndex);
    return chosenWord;
}

void Dictionary::printDictionary() const {
    for (auto word: m_words){
        std::cout << word << std::endl;
    }
}
