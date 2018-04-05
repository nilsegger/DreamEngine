#include "GameTest.h"

#define de DreamEngine

int main() {

	//std::cout << DreamEngine::Engine::angleToForward(DreamEngine::Engine::degToRadian(45.f)).x << "#" << DreamEngine::Engine::angleToForward(DreamEngine::Engine::degToRadian(45.f)).y << std::endl;

	assert(sf::Shader::isAvailable());
	
	GameTest game;
	game.initGame();
	

	sf::RectangleShape rect;
	rect.setPosition(0, 0);
	rect.setSize({ 100,100 });
	
	bool isLess = false;

	while (game.window->isOpen()) {
		game.sceneManager->baseUpdate();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			game.deleteGame(); 
			game.initGame(); 
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			game.deleteGame();
			break;
		}


		if (game.window->fpsCounter.getFrames() < 60 && isLess == false) {
			std::cout << "Less than 60 frames per second" << std::endl;
			isLess = true;
		}
		else if (game.window->fpsCounter.getFrames() >= 60 && isLess == true) {
			std::cout << "More than 60 frames per second" << std::endl;
			isLess = false;
		}
	}
	
	return 0;
}