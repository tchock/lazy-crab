//
//  TerrainComponent.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "TerrainComponent.h"
#include "Entity.h"
#include "WirechainRenderComponent.h"

TerrainComponent::TerrainComponent(GameContainer* gc, string id, int pointCount)
{
  this->id = id;
  this->pointCount = pointCount;
  
  // Body Definition (Box2D)
  this->bodyDef = new b2BodyDef(); // Generates a new body definition which contains values of the Body

  // Creates Body in the World (Box2D)
  this->body = gc->getWorld()->CreateBody(this->bodyDef);
  
  // Fixture (Box2D)
  this->chainVertices = new b2Vec2 [this->pointCount]; 
  /*this->renderVertices.setPrimitiveType(sf::LinesStrip);
  this->renderVertices.resize(this->pointCount);
  */
}

void TerrainComponent::addPoint(int index, float x, float y)
{
  Vector2f pos = Vector2f(x, y);
  this->chainVertices[index] = pos.getBox2d();
  if(owner->hasComponent("wirechainRender"))
    ((WirechainRenderComponent*) owner->getComponent("wirechainRender"))->addPoint(index, pos.getSFMLPos());
}

void TerrainComponent::generate()
{
  this->chain = new b2ChainShape(); 
  this->chain->CreateChain(this->chainVertices, this->pointCount);
  this->body->CreateFixture(this->chain, 0);  
}

void TerrainComponent::setOwnerEntity(Entity* owner) 
{
  this->owner = owner;
  body->SetTransform(owner->getPosition().getBox2d(), owner->getRotation());
}
