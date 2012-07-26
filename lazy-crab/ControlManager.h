#ifndef movement_cpp_ControlHandler_h
#define movement_cpp_ControlHandler_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Entity.h"

class ControlManager {
private:
  static bool jumpReady;
  
public:
  static void player (Entity* player, Entity* options);
};

#endif
