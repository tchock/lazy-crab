//  GameContainer.cpp
//  wombatcombat
//
//  Created by Simon Jentsch on 16.03.12.
//  Copyright 2012 __MungoGames__. All rights reserved.
//

#include <iostream>
#include "GameContainer.h"

GameContainer::GameContainer(sf::RenderWindow* window, b2World* world)
{
  this->window = window;
  this->window->setVerticalSyncEnabled(true);
  this->world = world;

}


// Getter
sf::RenderWindow* GameContainer::getWindow()
{
  return this->window;
}

b2World* GameContainer::getWorld()
{
  return this->world;
}

float GameContainer::getViewCenterX()
{
  return this->view.getCenter().x;
}

sf::Vector2f GameContainer::getViewEdges()
{
  sf::Vector2f edges = this->view.getCenter();
  edges.x -= this->view.getSize().x / 2;
  edges.y -= this->view.getSize().y / 2;
  
  return edges;
}

sf::Vector2f GameContainer::getPlayerOnScreen()
{
  return this->playerOnScreen;
}

Direction GameContainer::getMouseSide ()
{
  sf::RenderWindow* window = this->window;
  if (sf::Mouse::getPosition(*window).x < this->getPlayerOnScreen().x)
    return LEFT;
  else if (sf::Mouse::getPosition(*window).x > this->getPlayerOnScreen().x)
    return RIGHT;
  else
    return NONE;
}

sf::Time GameContainer::getDelta ()
{
  return this->delta;
}

// Setter
void GameContainer::setWindow(sf::RenderWindow* window)
{
  this->window = window;
}

void GameContainer::setView(sf::View view) {
  this->view = view;
  this->window->setView(this->view);
}

void GameContainer::setViewCenterX(float x) 
{
  this->view.setCenter(x, this->view.getCenter().y);
  this->window->setView(this->view);
}

void GameContainer::setPlayerOnScreen(sf::Vector2f pos)
{
  this->playerOnScreen = sf::Vector2f((pos.x / 100) * this->getWindow()->getSize().x, (pos.y / 100) * this->getWindow()->getSize().y);
}

void GameContainer::setDelta(sf::Time delta)
{
  this->delta = delta;
}
