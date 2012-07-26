//
//  xmlTest.h
//  lazy-crab
//
//  Created by Simon Jentsch on 25.07.12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef lazy_crab_xmlTest_h
#define lazy_crab_xmlTest_h

#include <tinyxml2.h>
#include <iostream>

using namespace tinyxml2;

class XmlTest {
  
public:
    
  static std::vector<Vector2f> dump_to_stdout(const string pFilename)
  {
    XMLDocument doc;
    doc.LoadFile(pFilename.data());
    
    XMLElement* titleElement = doc.FirstChildElement("world")->FirstChildElement("terrain");
        
    return parsePoints(titleElement->Attribute("points"));
    
    //std::cout << titleElement->GetText() << endl;
  }
  
  
  static std::vector<Vector2f> parsePoints(const char* points)
  {
    std::string currentString = "";
    std::string currentChar = "";
    std::string X = "";
    std::string Y = "";
    std::string stringToParse = points;
    std::string::iterator it = stringToParse.begin();
    
    std::vector<Vector2f> coords;

    while (it != stringToParse.end())
    {
      currentChar = *it;
      
      if (currentChar == ",")
      {
        X = currentString;
        currentString = "";
      }
      else if (currentChar == " " && X != "")
      {
        Y = currentString;
        currentString = "";
        
        // Converts the two strings to floats and pushes them to the point line;
        Vector2f currentPoint(atof(X.c_str()), atof(Y.c_str()));
        coords.push_back(currentPoint);
        
      }
      else
      {
        currentString += *it;
      }
      it++;
    }
    
    return coords;
    
  }
  
};

#endif
