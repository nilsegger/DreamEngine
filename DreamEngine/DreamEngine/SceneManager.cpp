#include "SceneManager.h"

DreamEngine::SceneManager::SceneManager(SceneManagerDef def)
	:window(def.window), builder(def.builder), dataManager(def.dataManager)
{
	assert(window != nullptr);
	assert(builder != nullptr);
	assert(dataManager != nullptr);
}
void DreamEngine::SceneManager::startScene(Core::Scene * scene)
{

	dataManager->saveTo("test.txt");


	if (scene->isReady == false) loadScene(scene);
	if (activeSceneCount >= MAX_ACTIVE_SCENES - 1) {
		std::cout << "Max active scenes reached" << std::endl;
		return;
	}
	for (int i = 0; i < MAX_ACTIVE_SCENES; i++) {
		if (activeScenes[i] == nullptr) {
			activeScenes[i] = scene;
			scene->start();
			activeSceneCount++;
			break;
		}
	}
}

void DreamEngine::SceneManager::startScene(int id)
{
	startScene((Core::Scene*)get(id));
}

void DreamEngine::SceneManager::loadScene(Core::Scene * scene)
{
	float progress = 0; //pass pointer of float

	std::thread loadingThread(&Core::Scene::load, scene, &progress);

	while (scene->isReady == false) {
		//progressBar->setProgress(progress);
		drawWindow();
		//baseUpdate();
	}

	loadingThread.join();
	//progressBar->displayBar(false);
}

void DreamEngine::SceneManager::loadScene(int id)
{
	loadScene((Core::Scene*)get(id));
}

void DreamEngine::SceneManager::endScene(Core::Scene * scene)
{
	for (int i = 0; i < MAX_ACTIVE_SCENES; i++) {
		if (activeScenes[i] == scene) {
			activeScenes[i] = nullptr;
			scene->end();
			activeSceneCount--;
			break;
		}
	}
}

void DreamEngine::SceneManager::endScene(int id)
{
	endScene((Core::Scene*)get(id));
}

void DreamEngine::SceneManager::baseUpdate()
{
	updateScene();
	drawWindow();
}

void DreamEngine::SceneManager::update(float delta)
{
	int count = 0;
	for (int i = 0; i < MAX_ACTIVE_SCENES && count < activeSceneCount; i++) {
		if (activeScenes[i] != nullptr) {
			activeScenes[i]->update(delta);
			count++;
		}
	}
}

void DreamEngine::SceneManager::draw(float delta)
{
	int count = 0;
	for (int i = 0; i < MAX_ACTIVE_SCENES && count < activeSceneCount; i++) {
		if (activeScenes[i] != nullptr) {
			activeScenes[i]->draw(delta);
			count++;
		}
	}
	//progressBar->draw();
}

void DreamEngine::SceneManager::save()
{
	//progressBar->displayBar(true);
	dataManager->startSaveChain();
	float progress = 0.f;
	int i = 1;
	for (Core::Scene * s = (Core::Scene*)getFirst(); s != nullptr; s = (Core::Scene*)getNext(), i++) {
		s->save(dataManager);
		/*progress = 100.f / float(getObjectCount()) * float(i);
		progressBar->setProgress(progress);*/
		drawWindow();
	}
	dataManager->save();
	//progressBar->displayBar(false);
}

void DreamEngine::SceneManager::destroy()
{
	for (Core::Scene * s = (Core::Scene*)getFirst(); s != nullptr; s = (Core::Scene*)getNext()) {
		s->destroy();
	}
}


void DreamEngine::SceneManager::start()
{

	std::vector<ObjectData> data;
	
	dataManager->getObjectData(&data, new float);

	std::cout << data.size() << std::endl;
	builder->build(data, new float);

	/*WindowDefinition startUpWindowDef;
	startUpWindowDef.size = { 200,200 };
	startUpWindowDef.style = sf::Style::None;

	Window window;
	window.init(startUpWindowDef);

	TextDefinition textDef;
	textDef.color = sf::Color::White;
	textDef.position = { 30, 85 };
	textDef.txt = "Reading...";
	textDef.window = window.getWindow();
	Text text(textDef);
	text.load();

	BarScreenDefinition barDef;
	barDef.position = { 0, 0 };
	barDef.size = { 200.f, 200.f };
	barDef.backgroundColor = sf::Color::Color(77, 82, 89);
	barDef.foregroundColor = sf::Color::Color(217, 217, 217);
	barDef.window = window.getWindow();
	Bar progressBar(barDef);
	progressBar.load();

	float progress = 0.f;

	std::vector<ObjectData> data;
	std::thread readThread(&CustomDataManager::getObjectData, customDataManager, &data, &progress);

	while (progress < 100.f) {
		progressBar.setProgress(progress);
		window.clear();
		window.draw(&progressBar);
		window.draw(&text);
		window.display();
	}
	readThread.join();
	text.setText("Building...");
	progress = 0.f;
	std::thread buildThread(&Builder::build, builder, data, &progress);
	while (progress < 100.f) {
		progressBar.setProgress(progress);
		window.clear();
		window.draw(&progressBar);
		window.draw(&text);
		window.display();
	}
	buildThread.join();

	window.close();
	this->window->getWindow()->setVisible(true);*/
}

void DreamEngine::SceneManager::updateScene()
{
	if (loopTimer.getElapsedTime() >= 1.f / 60.f) {
		update(loopTimer.getElapsedTime());
		loopTimer.restart();
	}
}

void DreamEngine::SceneManager::drawWindow()
{
	window->clear();
	draw(window->frameTimer.getElapsedTime());
	window->display();
}