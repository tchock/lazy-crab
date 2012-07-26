//
//  CameraComponent.h
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_CameraComponent_h
#define lazy_crab_CameraComponent_h

#include "Component.h"
#include "GameContainer.h"
#include "Vector2f.h"

class CameraComponent: public Component {
  
private:
  Vector2f size;
  GameContainer* gc;
  Entity* center;
  
  float currentZoom;
  float walkingZoom;
  float runningZoom;
  float zoomSpeed;
  
public:
  CameraComponent (GameContainer* gc, Entity* center, float width, float height);
  void setOwnerEntity(Entity* owner);
  void update(GameContainer* gc);
  
};


#endif
