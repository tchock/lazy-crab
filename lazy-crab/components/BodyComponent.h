//
//  BodyComponent.h
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_BodyComponent_h
#define lazy_crab_BodyComponent_h

#include <Box2D/Box2D.h>
#include <string>
#include "Component.h"
#include "Vector2f.h"

class BodyComponent: public Component {
  
private:
  GameContainer* gc;
  Vector2f size;
  b2Body* body;
  b2BodyDef* bodyDef;
  b2FixtureDef* fixtureDef;
  b2PolygonShape* bodyBox;

public:
  BodyComponent(GameContainer* gc, float x, float y, string bodyType="dynamic", bool fixedRotation=true, float density=1.0f, float friction=1.0f);
  Vector2f getSize() const;
  b2Body* getBody() const;
  void setOwnerEntity(Entity* owner);
  void setSize(float x, float y);
  void setX(float value);
  void setY(float value);
  void update(GameContainer* gc);
};

#endif
