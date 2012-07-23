//
//  WireboxRenderComponent.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "WireboxRenderComponent.h"
#include "Entity.h"
#include "BodyComponent.h"

WireboxRenderComponent::WireboxRenderComponent(string id)
:RenderComponent(id)
{
  shape.setOutlineColor(sf::Color::Green);
  shape.setOutlineThickness(1);
  shape.setFillColor(sf::Color::Transparent);
}

void WireboxRenderComponent::render(GameContainer *gc)
{
  gc->getWindow()->draw(shape);
}

void WireboxRenderComponent::update(GameContainer *gc)
{
  shape.setPosition(owner->getPosition().getSFMLPos());
  if (owner->hasComponent("body"))
  {
    shape.setSize(((BodyComponent*) owner->getComponent("body"))->getSize().getSFML());

  }
}