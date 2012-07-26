//
//  WireboxRenderComponent.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "ComponentWireboxRender.h"
#include "Entity.h"
#include "ComponentBody.h"

WireboxRenderComponent::WireboxRenderComponent(string id)
:RenderComponent(id)
{
  shape.setOutlineColor(sf::Color::Green);
  shape.setOutlineThickness(0.1f);
  shape.setFillColor(sf::Color::Transparent);
}

void WireboxRenderComponent::render(GameContainer *gc)
{
  gc->getWindow()->draw(shape);
}

void WireboxRenderComponent::update(GameContainer *gc)
{
  if (owner->hasComponent("body"))
  {
    sf::Vector2f ownerPos = owner->getPosition().getSFMLPos();
    sf::Vector2f bodySize = ((BodyComponent*) owner->getComponent("body"))->getSize().getSFML();
    shape.setOrigin(bodySize.x/2, bodySize.y/2);
    shape.setPosition(ownerPos.x, ownerPos.y);
    shape.setSize(((BodyComponent*) owner->getComponent("body"))->getSize().getSFML());
    shape.setRotation(-(owner->getRotation() * (180/M_PI)));

  }
}