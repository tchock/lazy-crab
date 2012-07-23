//
//  OptionComponent.h
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_OptionComponent_h
#define lazy_crab_OptionComponent_h

#include "Component.h"

class OptionComponent: public Component {
  
private:
  string type, value;
  
public:
  OptionComponent (string type, string key, string value);
  
  // Getter
  string getType() const;
  string getKey() const;
  string getValue() const;
  
  // Setter
  void setType(string type);
  void setKey(string key);
  void setValue(string value);

  void update(GameContainer* gc) {};
};

#endif
