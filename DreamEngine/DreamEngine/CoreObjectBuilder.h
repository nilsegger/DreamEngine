#pragma once

#include "Objects.h"
#include "ObjectData.h"
#include "Pair.h"

#include "UIElement.h"

namespace DreamEngine::Core {

	class ObjectBuilder {
	public:
		virtual bool doesBuild(std::string type) = 0;
		virtual void build(DreamEngine::ObjectData data, std::string type) = 0;
		virtual std::vector < Trio<std::string, DreamEngine::UserInterface::UIElementType, std::string>> getNecessaryObjectMembers() = 0;
		virtual DreamEngine::ObjectData createObjectDataFromNecessaryObjectMembers(std::vector < Trio<std::string, DreamEngine::UserInterface::UIElementType, std::string>>) = 0; // Create Panel with String as label, UIElementType as Textinput and need default value in it
		
	};

};