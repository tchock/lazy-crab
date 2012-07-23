
//
//  Entit.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 22.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Entity.h"

Entity::Entity(GameContainer* gc, string id)
{
  this->id = id;
  this->gc = gc;
  
  renderComponents = vector<RenderComponent*>();
  components = vector<Component*>();
  
  scale = 1;
  rotation = 0;
}

void Entity::addComponent(Component* component)
{
  component->setOwnerEntity(this);
  
  if (component->getType() == "render")
    renderComponents.push_back((RenderComponent*) component);
  else
    components.push_back(component);
}

Component* Entity::getComponent(string id) const
{
  
  // Iterate through the vector, if ID is found, return the component
  for(vector<Component*>::size_type i = 0; i != components.size(); i++)
    if (components[i]->getId() == id)
      return components[i];
  
  // Otherwise return pointer to NULL
  return NULL;
}

bool Entity::hasComponent(string id) const
{
  // Iterate through the vector, if ID is found, return true
  for(vector<Component*>::size_type i = 0; i != components.size(); i++)
  {
    if (components[i]->getId() == id)
      return true;
  }
  
  // Otherwise the component is not existent -> return false;
  return false;
}

Vector2f Entity::getPosition() const
{
  return position;
}

float Entity::getScale() const
{
  return scale;
}

float Entity::getRotation() const
{
  return rotation;
}

string Entity::getId() const
{
  return id;
}

GameContainer* Entity::getGC() const
{
  return gc;
}

void Entity::setPosition(float x, float y)
{
  position = Vector2f(x,y);
}

void Entity::setRotation(float rotate)
{
  rotation = rotate;
}

void Entity::setScale(float scale)
{
  this->scale = scale;
}


void Entity::update()
{
  for(vector<Component*>::size_type i = 0; i != components.size(); i++)
    components[i]->update(gc);
  for(vector<RenderComponent*>::size_type i = 0; i != renderComponents.size(); i++)
    renderComponents[i]->update(gc);
}

void Entity::render()
{
  for(vector<RenderComponent*>::size_type i = 0; i != renderComponents.size(); i++)
    renderComponents[i]->render(gc);
}