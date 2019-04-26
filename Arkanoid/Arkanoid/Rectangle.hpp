//
//  Rectangle.hpp
//  Arkanoid
//
//  Created by Miguel Lopes on 26/04/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>

class Rectangle{
protected:
    sf::RectangleShape _shape;
public:
    Rectangle() = default;
    ~Rectangle() = default;
        float x() const noexcept { return _shape.getPosition().x; }
        float y() const noexcept { return _shape.getPosition().y; }
        float left() const noexcept { return x() - _shape.getSize().x / 2.f; }
        float right() const noexcept { return x() + _shape.getSize().x / 2.f; }
        float top() const noexcept { return y() - _shape.getSize().y / 2.f; }
        float bottom() const noexcept { return y() + _shape.getSize().y / 2.f; }
    
    sf::RectangleShape getShape(){ return _shape; }


};
