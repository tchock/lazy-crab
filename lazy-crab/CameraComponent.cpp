//
//  CameraComponent.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "CameraComponent.h"
#include "Entity.h"

CameraComponent::CameraComponent (GameContainer* gc, Entity* center, float width, float height)
{
  this->gc = gc;
  this->center = center;
  this->size = Vector2f(width, height);
  
  // Static values
  this->currentZoom = 1.0f;
  this->walkingZoom = 1.0f;
  this->runningZoom = 1.4f;
  this->zoomSpeed = 0.001;
}

void CameraComponent::setOwnerEntity(Entity* owner) 
{
  this->owner = owner;
  gc->setView(sf::View(owner->getPosition().getSFMLPos() ,this->size.getSFML()));
}

void CameraComponent::update(GameContainer *gc)
{
  gc->setView(sf::View(center->getPosition().getSFMLPos() ,this->size.getSFML()));
}