#pragma once

#include "DreamEngine.h"

#include "PolygonDrawableBuilder.h"
#include "PolygonShapeBuilder.h"



#include "Launchable.h"

class GameTest : public DreamEngine::Launchable
{
public:
	GameTest();
	~GameTest();

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

	// Inherited via Launchable
	virtual void init() override;
	virtual void end() override;
	virtual bool update() override;
private:
	void freeMemory();

	
};

