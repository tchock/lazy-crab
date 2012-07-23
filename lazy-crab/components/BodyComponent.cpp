//
//  BodyComponent.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "BodyComponent.h"
#include "Entity.h"

BodyComponent::BodyComponent(GameContainer* gc, float x, float y, string bodyType, bool fixedRotation, float density, float friction)
{
  this->gc = gc;
  size.setVector(x, y);
  id = "body";
  
  bodyDef = new b2BodyDef(); // Generates a new body definition which contains values of the Body
  if (bodyType == "dynamic")
    bodyDef->type = b2_dynamicBody; // Sets type of Body to Dynamic (can move / be moved)
  else if (bodyType == "static")
    bodyDef->type = b2_staticBody; // Sets type of Body to Static (can't move / be moved)
  
  this->body = this->gc->getWorld()->CreateBody(bodyDef);
  this->body->SetFixedRotation(fixedRotation); // Body always stands straight (no rotation through Box2D)

  
  bodyBox = new b2PolygonShape();
  bodyBox->SetAsBox(x/2, y/2); // Sets the hitbox with halfsizes
  fixtureDef = new b2FixtureDef;
  fixtureDef->shape = bodyBox;
  fixtureDef->density = density; // Density of water, and because a human is almost water, also of a human
  fixtureDef->friction = friction;
  this->body->CreateFixture(fixtureDef);
  
}

void BodyComponent::setOwnerEntity(Entity* owner) 
{
  this->owner = owner;
  body->SetTransform(owner->getPosition().getBox2d(), owner->getRotation());
}


Vector2f BodyComponent::getSize() const
{
  return size; 
}

b2Body* BodyComponent::getBody() const
{
  return body;
}

void BodyComponent::setSize(float x, float y)
{
  size.setVector(x, y);
}

void BodyComponent::setX(float value)
{
  size.setX(value);
}

void BodyComponent::setY(float value)
{
  size.setY(value);
}

void BodyComponent::update(GameContainer *gc)
{
  owner->setPosition(body->GetPosition().x, body->GetPosition().y);
  owner->setRotation(body->GetAngle());
}