//
//  Component.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 22.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Component.h"

string Component::getId() const
{
  return id;
}

string Component::getType() const
{
  return type;
}

void Component::setOwnerEntity(Entity* owner) 
{
  this->owner = owner;
}

