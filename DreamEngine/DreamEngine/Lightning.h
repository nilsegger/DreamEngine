#pragma once

#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include "Engine.h"

namespace DreamEngine {

	struct LightningDef {
		sf::Vector2u windowSize;
	};

	class Lightning {
	public:
		Lightning(LightningDef def);
		virtual sf::Texture * get() = 0;
		//get Array pixel array?
		sf::Texture * texture;
	};

	struct DirectionalLightningDef : public LightningDef {
		b2World * world = nullptr;
		b2Vec2 forward = {0,0};
		b2Vec2 position = {0,0};
		float range = 10.f;
		sf::RenderWindow * window = nullptr;
	};


	class DirectionalLightning : public Lightning, public b2RayCastCallback, public b2QueryCallback{

	public:
		DirectionalLightning(DirectionalLightningDef def);

		// Inherited via Lightning
		virtual sf::Texture * get() override;
		// Inherited via b2RayCastCallback
		virtual float32 ReportFixture(b2Fixture * fixture, const b2Vec2 & point, const b2Vec2 & normal, float32 fraction) override;
		// Inherited via b2QueryCallback
		virtual bool ReportFixture(b2Fixture * fixture) override;
	private:
		unsigned int rays = 10;

		b2World * world;
		b2Vec2 forward;
		b2Vec2 position;
		b2Vec2 viewport;
		float range = 10.f;
		sf::RenderWindow * window;
		sf::VertexArray line;
	};

	class HitByRaycastCallback : public b2RayCastCallback {
	public:
		HitByRaycastCallback(b2Shape * shape);
		// Inherited via b2RayCastCallback
		virtual float32 ReportFixture(b2Fixture * fixture, const b2Vec2 & point, const b2Vec2 & normal, float32 fraction) override;

		bool isHit();
	private:
		bool hit = false;
		b2Shape * shape;

	};


};
