//
//  Ball.hpp
//  Arkanoid
//
//  Created by Miguel Lopes on 25/04/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "definitions.h"

class Ball{
  
public:
    Ball();
    ~Ball();
    
    void setPosition(float mX, float mY);
    void setRadius(float ballRadius);
    void setFillColor(sf::Color color);
    void setOrigin(float ballRadiusX, float ballRadiusY);
    void setVelocity(float ballVelocity);
    
    void update(float mFT);
    
    float x() const noexcept { return _shape.getPosition().x; }
    float y() const noexcept { return _shape.getPosition().y; }
    float left() const noexcept { return x() - _shape.getRadius(); }
    float right() const noexcept { return x() + _shape.getRadius(); }
    float top() const noexcept { return y() - _shape.getRadius(); }
    float bottom() const noexcept { return y() + _shape.getRadius(); }
private:
    
    float _ballVelocity = 0.0f;

    sf::CircleShape _shape;
    sf::Vector2f _velocity{_ballVelocity,_ballVelocity};
    
};
