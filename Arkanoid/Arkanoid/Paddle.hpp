//
//  Paddle.hpp
//  Arkanoid
//
//  Created by Miguel Lopes on 26/04/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#pragma once
#include "Rectangle.hpp"

class Paddle : public Rectangle{
public:
    Paddle() = default;
    Paddle(float mX, float mY);
    ~Paddle();
    
    void update(float mFT);
private:
    sf::Vector2f _velocity;
    float _paddleWidth = 60.f;
    float _paddleHeight = 20.f;
    float _paddleVelocity = 0.6f;

};
