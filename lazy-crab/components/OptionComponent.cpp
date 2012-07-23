//
//  OptionComponent.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "OptionComponent.h"

OptionComponent::OptionComponent(string type, string key, string value)
{
  id = key;
  this->type = type;
  this->value = value;
}

string OptionComponent::getType() const
{
  return type;
}


string OptionComponent::getKey() const
{
  return id;
}

string OptionComponent::getValue() const
{
  return value;
}

void OptionComponent::setType(string type)
{
  this->type = type;
}

void OptionComponent::setKey(string key)
{
  id = key;
}

void OptionComponent::setValue(string value)
{
  this->value = value;
}