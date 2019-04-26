//
//  GameManager.cpp
//  Arkanoid
//
//  Created by Miguel Lopes on 25/04/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#include "GameManager.hpp"
#include <cmath>
#include <chrono>

constexpr float ballRadius{10.f}, ballVelocity{0.8f};


GameManager::GameManager(){
    _window.create(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), GAME_TITLE, sf::Style::Close | sf::Style::Titlebar);
    // On construction, we initialize the window and create
    // the brick wall. On a more serious implementation, it
    // would be a good idea to have a `newGame()` method that
    // can be called at any time to restart the game.

    _window.setFramerateLimit(60);
    
    
    ball.setPosition(WINDOWWIDTH/2, WINDOWHEIGHT/2);

    ball.setRadius(ballRadius);
    ball.setFillColor(sf::Color::Red);
    ball.setOrigin(ballRadius, ballRadius);
    ball.setVelocity(ballVelocity);
    ball._velocity = {ball.getVelocity(),ball.getVelocity()};
    paddle = Paddle(WINDOWWIDTH / 2, WINDOWHEIGHT - 50);
    
    for(int iX = 0; iX < _countBlocksX; ++iX)
        for(int iY = 0; iY < _countBlocksY; ++iY)
            bricks.emplace_back(
                                (iX + 1) * (BLOCKWIDTH + 3) + 22,
                                (iY + 2) * (BLOCKHEIGTH + 3)
                                );
}

void GameManager::run(){
    // The `run()` method is used to start the game and
    // contains the game loop.
    
    // Instead of using `break` to stop the game, we will
    // use a boolean variable, `running`.
    _running = true;
    
    while(_running){
        auto timePoint1(std::chrono::high_resolution_clock::now());
        
        _window.clear(sf::Color::Black);
        
        // It's not a bad idea to use methods to make the
        // code more organized. In this case, I've divided
        // the game loop in "input", "update" and "draw"
        // phases. It's one of many possible ways of tidying up
        // the code :)
        inputPhase();
        updatePhase();
        drawPhase();
        
        auto timePoint2(std::chrono::high_resolution_clock::now());
        auto elapsedTime(timePoint2 - timePoint1);
        float ft{std::chrono::duration_cast<std::chrono::duration<float,std::milli>>(elapsedTime).count()};
        
        _lastFt = ft;
        
        auto ftSeconds(ft / 1000.f);
        auto fps(1.f / ftSeconds);
        
        _window.setTitle(
                         "FT: " + std::to_string(ft) + "\tFPS: " + std::to_string(fps));
    }
}

void GameManager::inputPhase()
{
    sf::Event event;
    while(_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed){
            _window.close();
            break;
        }
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) _window.close();
}

void GameManager::updatePhase()
{
    _currentSlice += _lastFt;
    for(; _currentSlice >= _ftSlice; _currentSlice -= _ftSlice)
    {
        ball.update(_ftStep);
        paddle.update(_ftStep);
        
        testCollision(paddle, ball);
        for(auto& brick : bricks) testCollision(brick, ball);
        bricks.erase(std::remove_if(begin(bricks), end(bricks),
                               [](const Brick& mBrick)
                               {
                                   return mBrick.getDestroyed();
                               }),
                     end(bricks));
    }
}

void GameManager::drawPhase(){
    _window.draw(ball.getShape());
    _window.draw(paddle.getShape());
    for(auto& brick : bricks) _window.draw(brick.getShape());
    _window.display();
}

template <class T1, class T2>
bool isIntersecting(T1& mA, T2& mB) noexcept
{
    return mA.right() >= mB.left() && mA.left() <= mB.right() &&
    mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void GameManager::testCollision(Paddle& mPaddle, Ball& mBall) noexcept{
    if(!isIntersecting(mPaddle, mBall)) return;
    
    mBall._velocity.y = - mBall.getVelocity();
    if(mBall.x() < mPaddle.x())
        mBall._velocity.x = - mBall.getVelocity();
    else
        mBall._velocity.x = mBall.getVelocity();
}

void GameManager::testCollision(Brick& mBrick, Ball& mBall) noexcept{
    if(!isIntersecting(mBrick, mBall)) return;
    mBrick.setDestroyed(true);
    
    float overlapLeft{mBall.right() - mBrick.left()};
    float overlapRight{mBrick.right() - mBall.left()};
    float overlapTop{mBall.bottom() - mBrick.top()};
    float overlapBottom{mBrick.bottom() - mBall.top()};
    
    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));
    
    float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
    float minOverlapY{ballFromTop ? overlapTop : overlapBottom};
    
    if(abs(minOverlapX) < abs(minOverlapY))
        mBall._velocity.x = ballFromLeft ? -mBall.getVelocity() : mBall.getVelocity();
    else
        mBall._velocity.y = ballFromTop ? -mBall.getVelocity() : mBall.getVelocity();
}
