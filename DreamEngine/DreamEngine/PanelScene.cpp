#include "PanelScene.h"

DreamEngine::PanelScene::PanelScene(PanelSceneDef def)
	:Core::Scene(def), cameraManager(def.cameraManager)
{
}

void DreamEngine::PanelScene::addPanel(UserInterface::Panel * panel)
{
	//panel->load();
	panels.push_back(panel);
}

void DreamEngine::PanelScene::update(float delta)
{
}

void DreamEngine::PanelScene::draw(float delta)
{
	assert(cameraManager != nullptr);
	for (int i = 0; i < int(panels.size()); i++) {
		if (panels[i]->isFocused()) cameraManager->get(Cameras::focusedPanel)->draw(panels[i]);
		else cameraManager->get(Cameras::unfocusedPanel)->draw(panels[i]);
	}
}

void DreamEngine::PanelScene::destroy()
{
}

void DreamEngine::PanelScene::load(float * progress)
{

	for (int i = 0; i < int(panels.size()); i++) {
		panels[i]->id = i;
		panels[i]->load();
	}

	isReady = true;
}

void DreamEngine::PanelScene::start()
{
}

void DreamEngine::PanelScene::end()
{
	for (int i = 0; i < int(panels.size()); i++) {
		delete panels[i];
	}
}

void DreamEngine::PanelScene::save(Core::DataManager * dataManager)
{
}
