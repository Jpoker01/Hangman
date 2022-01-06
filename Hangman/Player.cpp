//
// Created by jirip on 20.10.2021.
//

#include "Player.h"


Player::Player(){
    m_points = 0;
}

void Player::setPoints(const int points){
    m_points = points;
}


int Player::getPoints() const{
    return m_points;
}