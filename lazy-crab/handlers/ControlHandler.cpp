//
//  ControlHandler.cpp
//  movement_cpp
//
//  Created by Simon Jentsch on 06.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "ControlHandler.h"
#include "enums.h"

bool ControlHandler::jumpReady = true;

void ControlHandler::player(Entity* player, sf::Keyboard::Key moveRight, sf::Keyboard::Key moveLeft, sf::Keyboard::Key runToggler, sf::Keyboard::Key jumpToggler)
{
/*  
  if (sf::Keyboard::isKeyPressed(runToggler))
    player->setRunning(true);
  else
    player->setRunning(false);
  *
  if (sf::Keyboard::isKeyPressed(moveLeft))
    player->move(LEFT);
  if (sf::Keyboard::isKeyPressed(moveRight))
    player->move(RIGHT);

  if (!sf::Keyboard::isKeyPressed(moveLeft) && !sf::Keyboard::isKeyPressed(moveRight))
    player->stopMoving();
  
  if (sf::Keyboard::isKeyPressed(jumpToggler))
    if (ControlHandler::jumpReady) {
      player->jump();
      ControlHandler::jumpReady = false;
    }
  
  if (!sf::Keyboard::isKeyPressed(jumpToggler)) {
    ControlHandler::jumpReady = true;
  }
  */
}