//
//  Entity.h
//  lazy-crab
//
//  Created by Simon Jentsch on 22.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_Entity_h
#define lazy_crab_Entity_h

#include <string>
#include <vector>
#include "Vector2f.h"
#include "Component.h"
#include "RenderComponent.h"

using namespace std;

class Entity
{
  
protected:  
  GameContainer* gc;
  string id;
  
  Vector2f position;
  float scale;
  float rotation;
  
  vector<RenderComponent*> renderComponents;
  vector<Component*> components;
  
public:
  Entity(GameContainer* gc, string id);
  void addComponent(Component* component);
  
  // Getter
  Component* getComponent(string id) const;
  bool hasComponent(string id) const;
  Vector2f getPosition() const;
  float getScale() const;
  float getRotation() const;
  string getId() const;
  GameContainer* getGC() const;
  
  // Setter
  void setPosition(float x, float y);
  void setRotation(float rotate);
  void setScale(float scale); 
  
  
  //Update and render method
  void update();
  void render();
};

#endif
