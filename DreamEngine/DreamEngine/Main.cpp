#include "GameTest.h"
#include "UI.h"

#include "Launchable.h"

#define de DreamEngine

int main() {
	//assert(sf::Shader::isAvailable());
	
	de::Launchable * launchable = new de::UILauncher();
	//de::Launchable * launchable = new GameTest();

	launchable->init();

	while (launchable->update());

	launchable->end();

	delete launchable;
	
	return 0;
}