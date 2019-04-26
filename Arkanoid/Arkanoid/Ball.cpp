//
//  Ball.cpp
//  Arkanoid
//
//  Created by Miguel Lopes on 25/04/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#include "Ball.hpp"

void Ball::setPosition(float mX, float mY){
    _shape.setPosition(mX, mY);
}
void Ball::setRadius(float ballRadius){
    _shape.setRadius(ballRadius);
}
void Ball::setFillColor(sf::Color color){
    _shape.setFillColor(color);
}
void Ball::setOrigin(float ballRadiusX, float ballRadiusY){
    _shape.setOrigin(ballRadiusX, ballRadiusY);
}

void Ball::setVelocity(float ballVelocity){
    _ballVelocity = ballVelocity;
}

float Ball::getVelocity(){
    return _ballVelocity;
}
void Ball::update(float mFT){
    _shape.move(_velocity * mFT);
    
    if(left() < 0)
        _velocity.x = _ballVelocity;
    else if(right() > WINDOWWIDTH)
        _velocity.x = -_ballVelocity;
    
    if(top() < 0)
        _velocity.y = _ballVelocity;
    else if(bottom() > WINDOWHEIGHT)
        _velocity.y = -_ballVelocity;
}
