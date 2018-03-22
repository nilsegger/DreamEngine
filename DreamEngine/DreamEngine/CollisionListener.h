#pragma once

#include "Actor.h"
#include "Shape.h"

#include <Box2D\Box2D.h>

namespace DreamEngine {

	enum CollisionType {
		BEGINAA, ENDAA, BEGINAS, ENDAS, BEGINSS, ENDSS
	};

	struct Collision {
		DreamEngine::Core::WorldObject * a;
		DreamEngine::Core::WorldObject * s;
		b2Contact * contact;
		CollisionType type;
	};

	class CollisionListener : public b2ContactListener
	{
	public:
		void BeginContact(b2Contact* contact);
		void EndContact(b2Contact* contact);

		void runCollisions();
	private:
		std::vector<Collision> collisions;
		void parseContact(b2Contact * contact, Collision * collision, int * count, bool begin);
		void setCollision(Collision * collision, DreamEngine::Core::WorldObject * a, DreamEngine::Core::WorldObject * s, b2Contact * contact, CollisionType type);
		void doBeginAACollision(Collision collision);
		void doEndAACollision(Collision collision);
		void doBeginASCollision(Collision collision);
		void doEndASCollision(Collision collision);
		void doBeginSSCollision(Collision collision);
		void doEndSSCollision(Collision collision);
	};

};
