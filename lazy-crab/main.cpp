#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>
#include <string>
#include <iostream>

#include "GameContainer.h"
#include "EntityManager.h"
#include "ControlManager.h"
#include "Entity.h"
#include "ComponentBody.h"
#include "ComponentWireboxRender.h"
#include "ComponentTerrain.h"
#include "ComponentWirechainRender.h"
#include "ComponentCamera.h"
#include "ComponentOption.h"

#include "ResourcePathOSX.hpp"
#include "ResourcePath.h"



using namespace std;

int main (int argc, const char * argv[])
{  
  string gameName = "Lazy Crab";
  float currentFPS = 0;
  
  // Create the main window
  sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(DesktopMode.width/2, DesktopMode.height/2,DesktopMode.bitsPerPixel), gameName);

  sf::Clock frameTimer;
    
  // Generates the World
  b2Vec2 gravity(0, -9.8);
  b2World* world = new b2World(gravity);
  
  GameContainer* gc = new GameContainer(window, world);
    
  
  EntityManager* em = new EntityManager();
  
  Entity* player = em->addEntity(new Entity(gc, "player"));
  player->setPosition(8, 30);
  player->addComponent(new BodyComponent(gc, 0.6f, 1.8f, true));
  player->addComponent(new WireboxRenderComponent("wirebox"));
  
  float windowRatio = (float)gc->getWindow()->getSize().y / (float)gc->getWindow()->getSize().x;
  Entity* camera = em->addEntity(new Entity(gc, "camera"));
  camera->setPosition(100, 10);
  camera->addComponent(new CameraComponent(gc, player, 30, 30*windowRatio));
  
  Entity* terrain = em->addEntity(new Entity(gc, "terrain"));
  
  terrain->setPosition(0, 0);
  terrain->addComponent(new WirechainRenderComponent(5));
  terrain->addComponent(new TerrainComponent(gc, "gameTerrain", 5));
  /*for(int i = 0; i != coords.size(); i++)
  {
    ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(i, coords[i].x, coords[i].y);
  }*/
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(0, 0, 5);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(1, 30, -2);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(2, 50, 10);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(3, 80, 5);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(4, 100, 15);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->generate();

  
  Entity* options = em->addEntity(new Entity(gc, "options"));
  options->addComponent(new OptionComponent("controls", "moveLeft", "A"));
  options->addComponent(new OptionComponent("controls", "moveLeft_alt", "arrow_left"));
  options->addComponent(new OptionComponent("controls", "moveRight", "D"));
  options->addComponent(new OptionComponent("controls", "moveRight_alt", "arrow_right"));
  
  
  
  
  
  
  //ControlManager::player(player);
  
  // Start the game loop
  while (window->isOpen())
  {
  	// Process events
  	sf::Event event;
  	while (window->pollEvent(event))
  	{
  		// Close window : exit
  		if (event.type == sf::Event::Closed)
  			window->close();
          
  		// Escape pressed : exit
  		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
  			window->close();
  	}
    
    currentFPS =  1000 / (gc->getDelta().asMicroseconds() / 1000.0f);

  	// Clear screen
  	gc->getWindow()->clear();
  	    
    em->updateRender();
    
    em->getNearbyEntities(em->getEntity("player"), 2);
    
    
    
    gc->getWorld()->Step(1/currentFPS,  8, 3);
    gc->getWindow()->setView(gc->view);
    
    // Update the window
  	gc->getWindow()->display();
    
    gc->setDelta(frameTimer.restart());
  }

	return EXIT_SUCCESS;
}
