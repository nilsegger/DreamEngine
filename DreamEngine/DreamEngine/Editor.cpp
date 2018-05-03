#include "Editor.h"

void DreamEngine::Editor::init()
{
	DreamEngine::WindowDef windowDef;
	windowDef.fontSize = { 1280, 720 };
	windowDef.style = sf::Style::Close;
	windowDef.title = "DreamEngine";

	window = new DreamEngine::Window(windowDef);

	window->getWindow()->setFramerateLimit(0);
	window->getWindow()->setVerticalSyncEnabled(false);

	cameraManager = new DreamEngine::CameraManager;
	window->setCameraManager(cameraManager);

	DreamEngine::CameraDef cameraDef;
	cameraDef.window = window->getWindow();
	cameraDef.windowSize = { 1280,720 };
	cameraDef.id = Cameras::WORLD;
	cameraManager->add(new DreamEngine::Camera(cameraDef), true);
	cameraDef.id = Cameras::unfocusedPanel;
	cameraManager->add(new DreamEngine::Camera(cameraDef), true);
	cameraDef.id = Cameras::focusedPanel;
	cameraManager->add(new DreamEngine::Camera(cameraDef), true);
	cameraDef.id = Cameras::UI;
	cameraManager->add(new DreamEngine::Camera(cameraDef), true);

	builder = new DreamEngine::Builder;

	DreamEngine::DataManagerDef dataManagerDef;
	dataManagerDef.savePath = "shadow-test.lvl.txt";
	dataManagerDef.loadPath = "shadow-test.lvl.txt";

	dataManager = new DreamEngine::DataManager(dataManagerDef);

	DreamEngine::SceneManagerDef sceneManagerDef;
	sceneManagerDef.builder = builder;
	sceneManagerDef.dataManager = dataManager;
	sceneManagerDef.window = window;

	sceneManager = new DreamEngine::SceneManager(sceneManagerDef);

	initGame();
	initUI();

	sceneManager->start();

	sceneManager->startScene(0); //Game
	sceneManager->startScene(1); //UI

}

void DreamEngine::Editor::end()
{
}

bool DreamEngine::Editor::update()
{
	sceneManager->baseUpdate();
	return window->isOpen();
}

void DreamEngine::Editor::initGame()
{

	PolygonDrawableBuilderDef polygonDrawableBuilderDef;
	polygonDrawableBuilderDef.cameraManager = cameraManager;
	polygonDrawableBuilderDef.sceneManager = sceneManager;
	polygonDrawableBuilderDef.window = window;
	
	builder->addBuilder(new PolygonDrawableBuilder(polygonDrawableBuilderDef));

	PolygonShapeBuilderDef polygonShapeBuilderDef;
	polygonShapeBuilderDef.cameraManager = cameraManager;
	polygonShapeBuilderDef.sceneManager = sceneManager;
	polygonShapeBuilderDef.window = window;

	builder->addBuilder(new PolygonShapeBuilder(polygonShapeBuilderDef));

	DreamEngine::SpriteBuilderDef spriteBuilderDef;
	spriteBuilderDef.cameraManager = cameraManager;
	spriteBuilderDef.sceneManager = sceneManager;
	spriteBuilderDef.window = window;

	//builder->addBuilder(new DreamEngine::SpriteBuilder(spriteBuilderDef));

	DreamEngine::DefaultSceneDef defaultSceneDef;
	defaultSceneDef.id = 0;
	defaultSceneDef.gravity = { 0.f, 1.f };

	sceneManager->add(new DreamEngine::DefaultScene(defaultSceneDef), true);
}

void DreamEngine::Editor::initUI()
{
	DreamEngine::PanelSceneDef panelSceneDef;
	panelSceneDef.id = 1;
	panelSceneDef.type = "PanelScene";
	panelSceneDef.cameraManager = cameraManager;
	panelScene = new DreamEngine::PanelScene(panelSceneDef);


	EditorPanelBuilder panelBuilder(builder, panelScene, window);
	panelBuilder.createPanelsFromBuilders();

	/*DreamEngine::UserInterface::PanelDef panelDef;
	panelDef.id = 0;
	panelDef.window = window;
	panelDef.size = { 300.f,200.f };

	DreamEngine::UserInterface::Panel * panel = new DreamEngine::UserInterface::Panel(panelDef);

	DreamEngine::UserInterface::PanelDef panelDef2;
	panelDef2.id = 1;
	panelDef2.window = window;
	panelDef2.size = { 300.f,200.f };
	panelDef2.position = { 300.f,200.f };

	DreamEngine::UserInterface::Panel * panel2 = new DreamEngine::UserInterface::Panel(panelDef2);

	DreamEngine::UserInterface::ButtonDef buttonDef;
	buttonDef.text = "Add Tree";
	buttonDef.window = window;
	buttonDef.type = "Panel Button1";
	//buttonDef.onClickFunc = &UILauncher::test;
	buttonDef.fontSize = 15;
	panel->addUIElement(new DreamEngine::UserInterface::Button(buttonDef), 0, 0);
	buttonDef.fontSize = 25;
	panel->addUIElement(new DreamEngine::UserInterface::Button(buttonDef), 0, 1);


	DreamEngine::UserInterface::TextInputDef textInputDef;
	textInputDef.window = window;
	panel->addUIElement(new DreamEngine::UserInterface::TextInput(textInputDef), 2, 1);

	DreamEngine::UserInterface::CheckboxDef checkboxDef;
	checkboxDef.window = window;
	panel->addUIElement(new DreamEngine::UserInterface::Checkbox(checkboxDef), 1, 0);


	panelScene->addPanel(panel);*/

	sceneManager->add(panelScene,true);
}
