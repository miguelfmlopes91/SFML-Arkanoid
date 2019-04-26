//
//  Brick.cpp
//  Arkanoid
//
//  Created by Miguel Lopes on 26/04/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#include "Brick.hpp"
#include "definitions.h"
Brick::Brick(float mX, float mY){
    _shape.setPosition(mX, mY);
    _shape.setSize({BLOCKWIDTH, BLOCKHEIGTH});
    _shape.setFillColor(sf::Color::Yellow);
    _shape.setOrigin(BLOCKWIDTH / 2.f, BLOCKHEIGTH / 2.f);
}
