#ifndef wombatcombat_Helper_h
#define wombatcombat_Helper_h

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Vector2f {

public:  
  float x,y;  
  
  Vector2f();
  Vector2f(float x, float y);
  void setVector(float x, float y);  
  void setX(float value);  
  void setY(float value);
  sf::Vector2f getSFMLPos();
  sf::Vector2f getSFML();
  b2Vec2 getBox2d();  
  
};

#endif
