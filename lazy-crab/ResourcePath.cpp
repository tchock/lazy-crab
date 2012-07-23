//
//  ResourcePath.cpp
//  lazy-crab
//
//  Created by Simon Jentsch on 23.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#ifdef __APPLE__
#include "ResourcePathOSX.hpp"
#endif
#include "ResourcePath.h"

string resourcePath()
{
  // Individual Resource Handling in OS X (copies in .app file, so there is a specific function needed (in objective-c))
#ifdef __APPLE__
  return resourcePathOSX();
#else
  return "data/"; // if not OS X, simply use the data folder in the same dir
#endif
}