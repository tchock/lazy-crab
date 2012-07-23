//
//  WirechainRenderComponent.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "WirechainRenderComponent.h"

WirechainRenderComponent::WirechainRenderComponent(int pointCount)
:RenderComponent("wirechainRender")
{
  this->pointCount = pointCount;
  
  this->renderVertices.setPrimitiveType(sf::LinesStrip);
  this->renderVertices.resize(this->pointCount);
}

void WirechainRenderComponent::addPoint(int index, float x, float y)
{
  Vector2f pos = Vector2f(x, y);
  this->renderVertices[index] = pos.getSFMLPos();
}

void WirechainRenderComponent::addPoint(int index, sf::Vector2f pos)
{
  this->renderVertices[index] = pos;
}

void WirechainRenderComponent::render(GameContainer *gc)
{
  gc->getWindow()->draw(this->renderVertices);
}
