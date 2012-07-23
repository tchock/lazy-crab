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
  sf::Vector2f getSFMLPos() const;
  sf::Vector2f getSFML() const;
  b2Vec2 getBox2d() const;  
  float getLength() const;   
  
  // Operatoroverloading
  Vector2f operator+(const Vector2f& other) const;
  Vector2f operator-(const Vector2f& other) const;
  float operator*(const Vector2f& other) const;
  
};

#endif
