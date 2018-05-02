#include "EditorPanelBuilder.h"

DreamEngine::EditorPanelBuilder::EditorPanelBuilder(Builder * builder, PanelScene * panelScene, Window * window)
	:builders(builder->getBuilder()), panelScene(panelScene), window(window)
{
}

void DreamEngine::EditorPanelBuilder::createPanelsFromBuilders()
{
	for (int i = 0; i < builders.size(); i++) {
		createPanel(builders[i]);
	 }
}

void DreamEngine::EditorPanelBuilder::createPanel(Core::ObjectBuilder * builder)
{
	ObjectData objectData = builder->getExampleObject();
	std::vector<Trio<std::string, std::string, ObjectDataType>> data = objectData.getData();

	UserInterface::PanelDef panelDef;
	
	panelDef.panelTitle = objectData.getString("type");
	panelDef.position = { 0,0 };
	panelDef.window = window;
	
	UserInterface::Panel * panel = new UserInterface::Panel(panelDef);
	
	for (int i = 0; i < data.size(); i++) {
		createUIElement(panel, data[i]);
	}

}

void DreamEngine::EditorPanelBuilder::createUIElement(UserInterface::Panel * panel, Trio<std::string, std::string, ObjectDataType> data)
{
	UserInterface::TextInputDef textinputdef;
	textinputdef.fontSize = FONTSIZE;
	textinputdef.window = window;
	textinputdef.type = data.c;
	UserInterface::TextInput * input = new UserInterface::TextInput(textinputdef);
	input->setText(data.b);
	panel->addUIElement(input);

}
