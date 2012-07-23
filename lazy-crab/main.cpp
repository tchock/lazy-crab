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
#include "BodyComponent.h"
#include "WireboxRenderComponent.h"
#include "TerrainComponent.h"
#include "WirechainRenderComponent.h"
#include "CameraComponent.h"
#include "OptionComponent.h"

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
  window->setVerticalSyncEnabled(true);
  
  
  // Load a sprite to display
  sf::Texture texture;
  if (!texture.loadFromFile(resourcePath() + "images/cute_image.jpg"))
  	return EXIT_FAILURE;
  sf::Sprite sprite(texture);

  // Create a graphical text to display
  sf::Font font;
  if (!font.loadFromFile(resourcePath() + "fonts/sansation.ttf"))
  	return EXIT_FAILURE;
  sf::Text text("Hello SFML", font, 50);
  text.setColor(sf::Color::Black);

  // Load a music to play
  sf::Music music;
  if (!music.openFromFile(resourcePath() + "music/fairy_road.ogg"))
  	return EXIT_FAILURE;

  
  sf::Clock frameTimer;
  sf::Time deltaTime;
    
  // Generates the World
  b2Vec2 gravity(0, -9.8);
  b2World* world = new b2World(gravity);
  
  GameContainer* gc = new GameContainer(window, world);
    
  
  EntityManager* em = new EntityManager();
  
  Entity* player = em->addEntity(new Entity(gc, "player"));
  player->setPosition(8, 0);
  player->addComponent(new BodyComponent(gc, 0.6f, 1.8f, true));
  player->addComponent(new WireboxRenderComponent("wirebox"));
  
  float windowRatio = (float)gc->getWindow()->getSize().y / (float)gc->getWindow()->getSize().x;
  Entity* camera = em->addEntity(new Entity(gc, "camera"));
  camera->setPosition(100, 10);
  camera->addComponent(new CameraComponent(gc, player, 30, 30*windowRatio));
  
  Entity* terrain = em->addEntity(new Entity(gc, "terrain"));
  terrain->setPosition(0, -10);
  terrain->addComponent(new WirechainRenderComponent(6));
  terrain->addComponent(new TerrainComponent(gc, "gameTerrain", 6));
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(0, 5, 0);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(1, 20, 5);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(2, 30, -2);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(3, 50, 10);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(4, 80, 5);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->addPoint(5, 100, 15);
  ((TerrainComponent*) terrain->getComponent("gameTerrain"))->generate();
  
  Entity* options = em->addEntity(new Entity(gc, "options"));
  options->addComponent(new OptionComponent("controls", "moveLeft", "A"));
  options->addComponent(new OptionComponent("controls", "moveLeft_alt", "arrow_left"));
  options->addComponent(new OptionComponent("controls", "moveRight", "D"));
  options->addComponent(new OptionComponent("controls", "moveRight_alt", "arrow_right"));
  
  
  
  
  //ControlManager::player(player);
  
  
  // Play the music
  music.play();
      

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
