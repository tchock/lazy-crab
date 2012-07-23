//
//  TerrainComponent.h
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_TerrainComponent_h
#define lazy_crab_TerrainComponent_h

#include "GameContainer.h"
#include <Box2D/Box2D.h>
#include "Component.h"

class TerrainComponent: public Component {
  
private:
  int pointCount;
  
  b2Vec2* chainVertices; 
  
  b2BodyDef* bodyDef;
  b2Body* body;
  
  b2ChainShape* chain;
  
public:
  TerrainComponent(GameContainer* gc, string id, int pointCount);
  void addPoint(int index, float x, float y);
  void generate();
  void setOwnerEntity(Entity* owner);
  void update(GameContainer* gc) {};
};

#endif
