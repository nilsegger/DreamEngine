#pragma once

#include "Objects.h"
#include "CoreObjectBuilder.h"
#include "CoreBuilder.h"
#include <assert.h>

namespace DreamEngine {

	class Builder : public Core::Builder {

	public:
		~Builder();
		// Inherited via Builder
		virtual void build(std::vector<ObjectData> data, float * progress) override;

		void addBuilder(Core::ObjectBuilder * builder);
		std::vector<Core::ObjectBuilder*> getBuilder();
	private:
		std::vector<Core::ObjectBuilder*> builders;
	};

};