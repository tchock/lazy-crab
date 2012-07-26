//
//  WireboxRenderComponent.h
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_WireboxRenderComponent_h
#define lazy_crab_WireboxRenderComponent_h

#include <SFML/Graphics.hpp>
#include <string>
#include "GameContainer.h"
#include "RenderComponent.h"

class WireboxRenderComponent: public RenderComponent {
 
private:
  sf::RectangleShape shape;
  
public:
  WireboxRenderComponent(string id);
  void render(GameContainer* gc);
  void update(GameContainer* gc);
};

#endif
