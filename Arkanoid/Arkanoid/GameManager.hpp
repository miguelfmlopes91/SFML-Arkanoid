//
//  GameManager.hpp
//  Arkanoid
//
//  Created by Miguel Lopes on 25/04/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#include "Ball.hpp"
#include "Brick.hpp"
#include "Paddle.hpp"

class GameManager{
public:
    GameManager();
    ~GameManager() = default;

    void run();
    
    void inputPhase();
    void updatePhase();
    void drawPhase();
private:
    
    void testCollision(Paddle& mPaddle, Ball& mBall) noexcept;
    
    void testCollision(Brick& mBrick, Ball& mBall) noexcept;
    
    // These members are related to the control of the game.
    sf::RenderWindow _window;
    float _lastFt = 0.f;
    float _currentSlice = 0.f;
    bool _running = false;
    float _ftStep = 1.f;
    float _ftSlice = 1.f;
    int _countBlocksX = 11;
    int _countBlocksY = 4;


    Ball ball;
    Paddle paddle;
    std::vector<Brick> bricks;    
    
};
