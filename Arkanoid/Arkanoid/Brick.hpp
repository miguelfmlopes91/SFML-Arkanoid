//
//  Brick.hpp
//  Arkanoid
//
//  Created by Miguel Lopes on 26/04/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#pragma once
#include "Rectangle.hpp"

class Brick : public Rectangle{
public:
    Brick(float mX, float mY);
private:
    bool destroyed = false;
};
