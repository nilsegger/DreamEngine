#include "EditorPanelBuilder.h"

DreamEngine::EditorPanelBuilder::EditorPanelBuilder(Builder * builder, PanelScene * panelScene, Window * window)
	:builders(builder->getBuilder()), panelScene(panelScene), window(window)
{
}

void DreamEngine::EditorPanelBuilder::createPanelsFromBuilders()
{
	for (int i = 0; i < int(builders.size()); i++) {
		createPanel(builders[i]);
	 }
}

void DreamEngine::EditorPanelBuilder::createPanel(Core::ObjectBuilder * builder)
{
	//std::cout << "Creating panel" << std::endl;
	ObjectData objectData = builder->getExampleObject();
	std::vector<Trio<std::string, std::string, ObjectDataType>> data = objectData.getData();

	UserInterface::PanelDef panelDef;
	
	panelDef.panelTitle = objectData.getString("type");
	panelDef.position = { 0,0 };
	panelDef.window = window;
	
	UserInterface::Panel * panel = new UserInterface::Panel(panelDef);
	
	int row = 0;
	for (int i = 0; i < int(data.size()); i++) {
		createUIElement(panel, data[i], row, objectData);
	}
	panelScene->addPanel(panel);
}

void DreamEngine::EditorPanelBuilder::createUIElement(UserInterface::Panel * panel, Trio<std::string, std::string, ObjectDataType> data, int &row, ObjectData objectData)
{
	//std::cout << "Creating uielement" << std::endl;
	/*UserInterface::TextInputDef textinputdef;
	textinputdef.fontSize = FONTSIZE;
	textinputdef.window = window;
	textinputdef.type = data.c;
	UserInterface::TextInput * input = new UserInterface::TextInput(textinputdef);
	input->setText(data.b);
	input->setLabel(data.a);
	panel->addUIElement(input, row);*/
	switch (data.c)
	{
	case STRING:
		panel->addUIElement(createTextInput(data.a,data.b, data.c), row);
		row++;
		break;
	case INT:
		panel->addUIElement(createTextInput(data.a, data.b, data.c), row);
		row++;
		break;
	case FLOAT:
		panel->addUIElement(createTextInput(data.a, std::to_string(objectData.getFloat(data.a)), data.c), row);
		row++;
		break;
	case B2VEC2_X:
		panel->addUIElement(createTextInput(data.a, std::to_string(objectData.getFloat(data.a)), data.c), row);
		break;
	case B2VEC2_Y:
		panel->addUIElement(createTextInput(data.a, std::to_string(objectData.getFloat(data.a)), data.c), row,1);
		row++;
		break;
	default:
		break;
	}
}

DreamEngine::UserInterface::TextInput * DreamEngine::EditorPanelBuilder::createTextInput(std::string label, std::string value, DreamEngine::ObjectDataType type)
{
	UserInterface::TextInputDef textinputdef;
	textinputdef.fontSize = FONTSIZE;
	textinputdef.window = window;
	textinputdef.type = type;
	UserInterface::TextInput * input = new UserInterface::TextInput(textinputdef);
	input->setText(value);
	input->setLabel(label);
	return input;
}
