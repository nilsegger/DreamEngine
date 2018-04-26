#include "UI.h"

void DreamEngine::UILauncher::init()
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
	cameraDef.id = 0; // unfocusedPanel

	cameraManager->add(new DreamEngine::Camera(cameraDef), true);

	cameraDef.id = 1;
	cameraManager->add(new DreamEngine::Camera(cameraDef), true);

	DreamEngine::Builder * builder = new DreamEngine::Builder;

	DreamEngine::DataManagerDef dataManagerDef;
	dataManagerDef.savePath = "panel-test.txt";
	dataManagerDef.loadPath = "panel-test.txt";

	dataManager = new DreamEngine::DataManager(dataManagerDef);

	DreamEngine::SceneManagerDef sceneManagerDef;
	sceneManagerDef.builder = builder;
	sceneManagerDef.dataManager = dataManager;
	sceneManagerDef.window = window;

	sceneManager = new DreamEngine::SceneManager(sceneManagerDef);
	//add panelscene
	
	DreamEngine::PanelSceneDef panelSceneDef;
	panelSceneDef.id = 0;
	panelSceneDef.type = "PanelScene";
	panelSceneDef.cameraManager = cameraManager;
	panelScene = new DreamEngine::PanelScene(panelSceneDef);

	DreamEngine::UserInterface::PanelDef panelDef;
	panelDef.id = 0;
	panelDef.window = window;
	panelDef.size = {300.f,200.f};

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
	buttonDef.onClickFunc = &UILauncher::test;

	panel->addUIElement(new DreamEngine::UserInterface::Button(buttonDef), sf::Vector2f{30,30});

	DreamEngine::UserInterface::CheckboxDef checkboxDef;
	checkboxDef.window = window;
	panel->addUIElement(new DreamEngine::UserInterface::Checkbox(checkboxDef), sf::Vector2f{ 30,80 });
	

	panelScene->addPanel(panel);
	panelScene->addPanel(panel2);

	sceneManager->add(panelScene, true);

	sceneManager->start();

	sceneManager->startScene(panelScene);
}

void DreamEngine::UILauncher::end()
{
}

bool DreamEngine::UILauncher::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		return false;
	}

	sceneManager->baseUpdate();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		end();
		init();
	}
	return window->isOpen();
}

void DreamEngine::UILauncher::test(DreamEngine::UserInterface::UIElement * element)
{
	std::cout << "Test was successfull" << std::endl;
}
