//
//  RenderComponent.h
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_RenderComponent_h
#define lazy_crab_RenderComponent_h

#include "Component.h"
#include "GameContainer.h"
#include <string>
using namespace std;

class RenderComponent: public Component {
  
public:
  RenderComponent(string id);
  virtual void render(GameContainer* gc) =0;
};

#endif
