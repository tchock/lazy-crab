//
//  WirechainRenderComponent.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "WirechainRenderComponent.h"
#include "Entity.h"

WirechainRenderComponent::WirechainRenderComponent(int pointCount)
:RenderComponent("wirechainRender")
{
  this->pointCount = pointCount;
  
  this->renderVertices.setPrimitiveType(sf::LinesStrip);
  this->renderVertices.resize(this->pointCount);
}

void WirechainRenderComponent::addPoint(int index, float x, float y)
{
  sf::Vector2f ownerPos = owner->getPosition().getSFMLPos();
  Vector2f pos = Vector2f(x + ownerPos.x, y + ownerPos.y);
  this->renderVertices[index] = pos.getSFMLPos();
}

void WirechainRenderComponent::addPoint(int index, sf::Vector2f pos)
{
  sf::Vector2f ownerPos = owner->getPosition().getSFMLPos();
  pos.x += ownerPos.x;
  pos.y += ownerPos.y;
  this->renderVertices[index] = pos;
}

void WirechainRenderComponent::render(GameContainer *gc)
{
  gc->getWindow()->draw(this->renderVertices);
}
