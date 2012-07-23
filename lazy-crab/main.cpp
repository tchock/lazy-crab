#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>
#include <string>
#include <iostream>
#include "ResourcePath.hpp"
#include "GameContainer.h"
#include "EntityManager.h"
#include "Entity.h"
#include "BodyComponent.h"
#include "WireboxRenderComponent.h"

using namespace std;

int main (int argc, const char * argv[])
{
  string gameName = "Lazy Crab";
  float currentFPS = 0;
  
  // Create the main window
  sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(DesktopMode.width/2, DesktopMode.height/2,DesktopMode.bitsPerPixel), gameName);
 
  
  
  // Load a sprite to display
  sf::Texture texture;
  if (!texture.loadFromFile(resourcePath() + "cute_image.jpg"))
  	return EXIT_FAILURE;
  sf::Sprite sprite(texture);

  // Create a graphical text to display
  sf::Font font;
  if (!font.loadFromFile(resourcePath() + "sansation.ttf"))
  	return EXIT_FAILURE;
  sf::Text text("Hello SFML", font, 50);
  text.setColor(sf::Color::Black);

  // Load a music to play
  sf::Music music;
  if (!music.openFromFile(resourcePath() + "nice_music.ogg"))
  	return EXIT_FAILURE;

  
  sf::Clock frameTimer;
  sf::Time deltaTime;
    
  // Generates the World
  b2Vec2 gravity(0, -9.8);
  b2World* world = new b2World(gravity);
    
  GameContainer* gc = new GameContainer(window, world);
    
  EntityManager* em = new EntityManager();
  
  em->addEntity(new Entity(gc, "beispiel_entity"));
  em->getEntity("beispiel_entity")->setPosition(100, 10);
  em->getEntity("beispiel_entity")->addComponent(new BodyComponent(gc, 10, 20));
  em->getEntity("beispiel_entity")->addComponent(new WireboxRenderComponent("wirebox"));
  
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
    gc->getWorld()->Step(1/currentFPS, 8, 3);
    gc->getWindow()->setView(gc->view);
    
    // Update the window
  	gc->getWindow()->display();
    
    gc->setDelta(frameTimer.restart());
  }

	return EXIT_SUCCESS;
}
