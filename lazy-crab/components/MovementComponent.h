//
//  MovementComponent.h
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_MovementComponent_h
#define lazy_crab_MovementComponent_h

#include "Component.h"
#include "enums.h"

class MovementComponent: public Component {
  
public:
  MovementComponent();
  void move(Direction direction);
  void jump();
};


#endif
