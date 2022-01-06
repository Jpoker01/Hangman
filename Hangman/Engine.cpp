//
// Created by jirip on 20.10.2021.
//

#include "Engine.h"

Engine::Engine(){
    Dictionary* dictionary = new Dictionary();
    m_dictionary = dictionary;

    Player* player = new Player();
    m_player = player;

    m_word = "";
    initLetters();
    m_progression = 0;
}

void Engine::play(){
    char decision;
    std::cout << "Would you like to load words into dictionary from a text file? (y/n)" << std::endl;
    std::cin >> decision;
    if (decision == 'y' or decision == 'Y'){
        std::string fileName;
        std::cout << "Type in the complete file name (including .txt): " << std::endl;
        std::cin >> fileName;
        m_dictionary->loadFromFile(fileName);
    }

    std::cout << "Welcome to the hangman!" << std::endl;
    std::cout << "Start by choosing the first letter. " << std::endl;
    int firstRun = 0;
    m_word = m_dictionary->chooseRandomWord();
    printLine();
    char letter;
    letter = getUserInput();

    while(!isEnd()){
        if (firstRun != 0){
            letter = getUserInput();
        } else {
            firstRun++;
        }
        if (hasLetterBeenUsed(letter)){
            std::cout << "Letter has already been used. " << std::endl;
            while (hasLetterBeenUsed(letter)){
                letter = getUserInput();
            }
        }
        if (isLetterInTheWord(letter)){
            removeFromLetters(letter);
            std::cout << "You have correctly guess a letter from the word! " << std::endl;

        } else {
            std::cout << "The given letter is not in the word!" << std::endl;
            m_progression++;

        }
        drawLayout();

    }



}

void Engine::initLetters(){
    for (unsigned int i = 0; i < m_letters.size(); i++){
        m_letters.at(i) = char('A' + i);
    }
}

char Engine::getUserInput()  const throw(std::invalid_argument){
    char A;
    std::cout << "Type in a character for the word: " << std::endl;
    std::cin >> A;
    if (isItLetter(A)){
        A = toupper(A);
    } else {
        while (!isItLetter(A)){
            std::cerr << "The given input is not a letter";
            std::cin >> A;
        }
        A = toupper(A);
    }
    return A;
}

void Engine::printLine() const {
    unsigned int wordLength = m_word.size();
    for (int i = 0; i < wordLength; i++){

        char result = m_letters.at(int(m_word.at(i) - 'A'));
        if (result == '0'){
            std::cout << m_word.at(i);
        } else {
            std::cout << "_";
        }
    }
    std::cout << std::endl;
}

void Engine::drawLayout() const{
    printLine();
    if (m_progression == 0){
        printLine();
        std::cout <<  " x________x" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  "/|\\" << std::endl;

    } else if (m_progression == 1){
        std::cout <<  " x________x" << std::endl;
        std::cout <<  " |        |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  "/|\\" << std::endl;
    } else if (m_progression == 2){
        std::cout <<  " x________x" << std::endl;
        std::cout <<  " |        |" << std::endl;
        std::cout <<  " |        O" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  "/|\\" << std::endl;
    } else if (m_progression == 3){
        std::cout <<  " x________x" << std::endl;
        std::cout <<  " |        |" << std::endl;
        std::cout <<  " |        O" << std::endl;
        std::cout <<  " |        |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  "/|\\" << std::endl;
    } else if (m_progression == 4){
        std::cout <<  " x________x" << std::endl;
        std::cout <<  " |        |" << std::endl;
        std::cout <<  " |        O" << std::endl;
        std::cout <<  " |       /|" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  "/|\\" << std::endl;
    } else if (m_progression == 5){
        std::cout <<  " x________x" << std::endl;
        std::cout <<  " |        |" << std::endl;
        std::cout <<  " |        O" << std::endl;
        std::cout <<  " |       /|\\" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  "/|\\" << std::endl;
    } else if (m_progression == 6){
        std::cout <<  " x________x" << std::endl;
        std::cout <<  " |        |" << std::endl;
        std::cout <<  " |        O" << std::endl;
        std::cout <<  " |       /|\\" << std::endl;
        std::cout <<  " |       /"   << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  "/|\\" << std::endl;
    } else if (m_progression == 7){
        std::cout <<  " x________x" << std::endl;
        std::cout <<  " |        |" << std::endl;
        std::cout <<  " |        O" << std::endl;
        std::cout <<  " |       /|\\" << std::endl;
        std::cout <<  " |       / \\"   << std::endl;
        std::cout <<  " |" << std::endl;
        std::cout <<  "/|\\" << std::endl;
    } else {
        throw std::out_of_range("Progression out of range.");
    }
}

bool Engine::isItLetter( const char letter) const{
    if (isalpha(letter)){
        return true;
    } else {
        return false;
    }
}

bool Engine::hasLetterBeenUsed(const char letter) const{
    bool used = true;
    for (int unsigned i = 0; i < m_letters.size(); i++){
        if (letter == m_letters.at(i)){
            used = false;
        }
    }

    return used;

}

bool Engine::isLetterInTheWord(const char letter) const{
    bool isIt = false;

    for (unsigned int i = 0; i < m_word.size(); i++){
        if (m_word.at(i) == letter){
            isIt = true;
        }
    }
    return isIt;
}

void Engine::removeFromLetters(const char letter){
    m_letters.at(int(letter - 'A')) = '0';
}

bool Engine::hasWordBeenGuessed(){
    bool okay = true;

        for (unsigned int i = 0; i < m_word.size(); i++){
            char result = m_letters.at(int(m_word.at(i) - 'A'));

            if (result != '0'){
                okay = false;
            }
        }

    return okay;

}

bool Engine::isEnd(){
    if (m_progression == 7){
        std::cout << "You have lost!" << std::endl;
        return true;
    } else if (hasWordBeenGuessed()){
        std::cout << "You have guessed the word and won!" << std::endl;
        return true;
    }
    else {
        return false;
    }
}
