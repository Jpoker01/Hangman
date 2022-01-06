//
// Created by jirip on 20.10.2021.
//

#ifndef HANGMAN_PLAYER_H
#define HANGMAN_PLAYER_H


class Player {
    int m_points;
public:
    Player();
    void setPoints(const int points);
    int getPoints() const;
};


#endif //HANGMAN_PLAYER_H
