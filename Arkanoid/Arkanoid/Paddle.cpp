//
//  Paddle.cpp
//  Arkanoid
//
//  Created by Miguel Lopes on 26/04/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#include "Paddle.hpp"
#include "definitions.h"
Paddle::Paddle(float mX, float mY){
    _shape.setPosition(mX, mY);
    _shape.setSize({_paddleWidth, _paddleHeight});
    _shape.setFillColor(sf::Color::Red);
    _shape.setOrigin(_paddleWidth / 2.f, _paddleHeight / 2.f);
}

void Paddle::update(float mFT){
    _shape.move(_velocity * mFT);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
        _velocity.x = -_paddleVelocity;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) &&
            right() < WINDOWWIDTH)
        _velocity.x = _paddleVelocity;
    else
        _velocity.x = 0;
}
