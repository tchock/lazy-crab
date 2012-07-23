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

vector<Entity*> EntityManager::getNearbyEntities(Entity* entity, float distance) const
{
  
  vector<Entity*> output; // Output vector
  // Iterate through the entities
  for(vector<Entity*>::size_type i = 0; i != entities.size(); i++)
  {
    Vector2f distanceVector = entities[i]->getPosition() - entity->getPosition(); // calculate the distance vector between the two objects
    // cout << "ObjectID: " << entities[i]->getId() << " :: Distance: " << distanceVector.getLength() << endl;
    
    if (distanceVector.getLength() < distance && entity != entities[i]) // if within defined distance range and not the object itself
    {  
      output.push_back(entities[i]); // push to output vector
    }
  }
  
  return output;
}

Entity* EntityManager::addEntity(Entity* entity)
{
  entities.push_back(entity);
  return entity;
}

void EntityManager::removeEntity(string id)
{
 
  for (vector<Entity*>::iterator it = entities.begin(); it!=entities.end(); ++it) {
    if ((*it)->getId() == id)
    { 
      delete *it;
      entities.erase(it);
    }
  }
}

void EntityManager::updateRender()
{
  for(vector<Entity*>::size_type i = 0; i != entities.size(); i++)
  {
    entities[i]->update();
    entities[i]->render();
  }
}
 