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
    Brick() = default;
    ~Brick() = default;
    Brick(float mX, float mY);
    void setDestroyed(bool d){ _destroyed = d;}
    bool getDestroyed() const {return _destroyed;}

private:
    bool _destroyed = false;
};
