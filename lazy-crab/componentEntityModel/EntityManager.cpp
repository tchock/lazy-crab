//
//  EntityManager.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "EntityManager.h"

EntityManager::EntityManager()
{
  
}

Entity* EntityManager::getEntity(string id) const
{
  
  // Iterate through the vector, if ID is found, return the entity
  for(vector<Entity*>::size_type i = 0; i != entities.size(); i++)
    if (entities[i]->getId() == id)
      return entities[i];
  
  // Otherwise return pointer to NULL
  return NULL;
}

void EntityManager::addEntity(Entity* entity)
{
  entities.push_back(entity);
}

void EntityManager::updateRender()
{
  for(vector<Entity*>::size_type i = 0; i != entities.size(); i++)
  {
    entities[i]->update();
    entities[i]->render();
  }
}
