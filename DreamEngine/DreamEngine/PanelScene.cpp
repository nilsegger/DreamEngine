#include "PanelScene.h"

DreamEngine::PanelScene::PanelScene(PanelSceneDef def)
	:Core::Scene(def)
{
}

void DreamEngine::PanelScene::addPanel(Panel * panel)
{
	panel->load();
	panels.push_back(panel);
}

void DreamEngine::PanelScene::update(float delta)
{
}

void DreamEngine::PanelScene::draw(float delta)
{
	for (int i = 0; i < int(panels.size()); i++) {
	 	panels[i]->draw();
	}
}

void DreamEngine::PanelScene::destroy()
{
}

void DreamEngine::PanelScene::load(float * progress)
{
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
