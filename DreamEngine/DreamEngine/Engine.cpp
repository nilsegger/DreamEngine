#include "Engine.h"

float DreamEngine::Engine::worldToPixel(float val)
{
	return val * SCALE;
}

sf::Vector2f DreamEngine::Engine::worldToPixel(b2Vec2 val)
{
	return{ worldToPixel(val.x), worldToPixel(val.y) };
}

sf::Vector2i DreamEngine::Engine::worldToPixeli(b2Vec2 val)
{
	return sf::Vector2i{ int(worldToPixel(val).x), int(worldToPixel(val).y) };
}

b2Vec2 DreamEngine::Engine::pixelToWorld(sf::Vector2i val)
{
	return b2Vec2(val.x / SCALE, val.y / SCALE);
}

b2Vec2 DreamEngine::Engine::pixelToWorld(sf::Vector2f val)
{
	return b2Vec2(val.x / SCALE, val.y / SCALE);
}


void DreamEngine::Engine::waitForKeyPress(std::string message)
{
	std::cout << message << std::endl << "Press enter to continue..." << std::endl;
	getchar();
}

bool DreamEngine::Engine::intToBool(int val)
{
	return val != 0;
}

b2Vec2 DreamEngine::Engine::angleToForward(float angle)
{
	return{ cos(angle), sin(angle) };
}

float DreamEngine::Engine::radianToDeg(float angle)
{
	return angle * 57.2958f;
}

float DreamEngine::Engine::degToRadian(float degree)
{
	return degree / 57.2958f;
}
