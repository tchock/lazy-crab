/////////////////////////////////////////////
/// @brief Helper class
/// A set of helpful functions like vector2f
///
/// @author Simon J
/// @date 03/27/2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////

#include <iostream>
#include "Vector2f.h"



/////////////////////////////////////////////
/// @brief Vector2f object for Box2D and SFML
///
/// A simple container method that inhabits a struct.
/// Sets the vector2f values for Box2D and SFML (with negativ y-axis)
///
/// @param x,y     Coordinates of the Vector
/////////////////////////////////////////////

Vector2f::Vector2f()
{
  x = y = 0;
}

Vector2f::Vector2f(float x, float y)
{
  this->x = x;
  this->y = y;
}

// Setter

void Vector2f::setVector(float x, float y)
{
  this->x = x;
  this->y = y;
}

void Vector2f::setX(float value)
{
  this->x = value;
}

void Vector2f::setY(float value)
{
  this->y = value;
}

// Getter

sf::Vector2f Vector2f::getSFML() const
{
  return sf::Vector2f(x,y);
}

sf::Vector2f Vector2f::getSFMLPos() const
{
  return sf::Vector2f(x,-y);
}

b2Vec2 Vector2f::getBox2d() const
{
  return b2Vec2(x,y);
}

float Vector2f::getLength() const
{
  return sqrt(operator*(*this));
}

Vector2f Vector2f::operator+(const Vector2f& other) const
{
  return Vector2f(x + other.x, y + other.y);
}

Vector2f Vector2f::operator-(const Vector2f& other) const
{
  return Vector2f(x - other.x, y - other.y);
}

float Vector2f::operator*(const Vector2f& other) const
{
  return x * other.x + y * other.y;
}