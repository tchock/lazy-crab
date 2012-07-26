//
//  WirechainRenderComponent.h
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_WirechainRenderComponent_h
#define lazy_crab_WirechainRenderComponent_h

#include "RenderComponent.h"
#include "Vector2f.h"

class WirechainRenderComponent: public RenderComponent {
  
private:
  int pointCount;
  sf::VertexArray renderVertices;
  
public:
  WirechainRenderComponent(int pointCount);
  void addPoint(int index, float x, float y);
  void addPoint(int index, sf::Vector2f pos);
  void render(GameContainer* gc);
  void update(GameContainer* gc) {};
};

#endif
