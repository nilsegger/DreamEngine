#pragma once

#include "DreamEngine.h"

#include "PolygonDrawableBuilder.h"
#include "PolygonShapeBuilder.h"


class GameTest
{
public:
	GameTest();
	~GameTest();

	void initGame();
	void deleteGame();

	DreamEngine::Window * window = nullptr;
	DreamEngine::CameraManager * cameraManager = nullptr;
	DreamEngine::Camera * camera = nullptr;
	DreamEngine::Builder * builder = nullptr;
	DreamEngine::DataManager * dataManager = nullptr;
	DreamEngine::SceneManager * sceneManager = nullptr;
	PolygonDrawableBuilder * polygonDrawableBuilder = nullptr;
	PolygonShapeBuilder * polygonShapeBuilder = nullptr;
	DreamEngine::SpriteBuilder * spriteBuilder = nullptr;
	DreamEngine::DefaultScene * defaultScene = nullptr;
private:
	void freeMemory();
};

