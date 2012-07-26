//
//  Component.h
//  lazy-crab
//
//  Created by Simon Jentsch on 22.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_Component_h
#define lazy_crab_Component_h

#include <string>
#include "GameContainer.h"
using namespace std;

class Entity;

class Component {
  
protected:
  string id;
  string type;
  Entity* owner;
  
public:
  string getId() const;
  string getType() const;
  virtual void setOwnerEntity(Entity* owner);
  virtual void update(GameContainer* gc) = 0;
  
};

#endif
