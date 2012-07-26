//
//  RenderComponent.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ComponentRender.h"

RenderComponent::RenderComponent(string id)
{
  this->id = id;
  this->type = "render";
}