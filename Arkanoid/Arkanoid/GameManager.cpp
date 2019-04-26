//
//  GameManager.cpp
//  Arkanoid
//
//  Created by Miguel Lopes on 25/04/2019.
//  Copyright © 2019 Miguel Lopes. All rights reserved.
//

#include "GameManager.hpp"




GameManager::GameManager(){
    
    _window.create(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), GAME_TITLE, sf::Style::Close | sf::Style::Titlebar);
    // On construction, we initialize the window and create
    // the brick wall. On a more serious implementation, it
    // would be a good idea to have a `newGame()` method that
    // can be called at any time to restart the game.

    _window.setFramerateLimit(240);
    
    
    ball.setPosition(WINDOWWIDTH/2, WINDOWHEIGHT/2);
    paddle = Paddle(WINDOWWIDTH / 2, WINDOWHEIGHT - 50);
    std::vector<Brick> bricks;
    
    for(int iX = 0; iX < _countBlocksX; ++iX)
        for(int iY = 0; iY < _countBlocksY; ++iY)
            bricks.emplace_back(
                                (iX + 1) * (BLOCKWIDTH + 3) + 22,
                                (iY + 2) * (BLOCKHEIGTH + 3)
                                );
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
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) _running = false;
}

void GameManager::updatePhase()
{
    currentSlice += lastFt;
    for(; currentSlice >= ftSlice; currentSlice -= ftSlice)
    {
        ball.update(ftStep);
        paddle.update(ftStep);
        
        testCollision(paddle, ball);
        for(auto& brick : bricks) testCollision(brick, ball);
        bricks.erase(remove_if(begin(bricks), end(bricks),
                               [](const Brick& mBrick)
                               {
                                   return mBrick.destroyed;
                               }),
                     end(bricks));
    }
}

void GameManager::drawPhase()
{
    _window.draw(ball.shape);
    _window.draw(paddle.shape);
    for(auto& brick : bricks) window.draw(brick.shape);
    _window.display();
}
