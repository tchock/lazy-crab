//
//  ControlHandler.cpp
//  movement_cpp
//
//  Created by Simon Jentsch on 06.03.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "ControlManager.h"
#include "enums.h"
#include <iostream>
#include "OptionComponent.h"

bool ControlManager::jumpReady = true;

void ControlManager::player(Entity* player, Entity* options)
{

  
  //if (sf::Keyboard::isKeyPressed()
  
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