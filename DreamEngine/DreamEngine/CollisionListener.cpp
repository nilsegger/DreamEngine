#include "CollisionListener.h"

void DreamEngine::CollisionListener::BeginContact(b2Contact * contact)
{
	Collision parsedCollisions[4];
	int count = 0;
	parseContact(contact, parsedCollisions, &count, true);
	for (int i = 0; i < count; i++) {
		collisions.push_back(parsedCollisions[i]);
	}
}

void DreamEngine::CollisionListener::EndContact(b2Contact * contact)
{
	Collision parsedCollisions[4];
	int count = 0;
	parseContact(contact, parsedCollisions, &count, false);
	for (int i = 0; i < count; i++) {
		collisions.push_back(parsedCollisions[i]);
	}
}

void DreamEngine::CollisionListener::runCollisions()
{
	int size = int(collisions.size());
	for (int i = size - 1; i >= 0; i--) {
		switch (collisions[i].type)
		{
		case CollisionType::BEGINAA:
			doBeginAACollision(collisions[i]);
			break;
		case CollisionType::ENDAA:
			doEndAACollision(collisions[i]);
			break;
		case CollisionType::BEGINAS:
			doBeginASCollision(collisions[i]);
			break;
		case CollisionType::ENDAS:
			doEndASCollision(collisions[i]);
			break;
		case CollisionType::BEGINSS:
			doBeginSSCollision(collisions[i]);
			break;
		case CollisionType::ENDSS:
			doEndSSCollision(collisions[i]);
			break;
		default:
			break;
		}
		collisions.erase(collisions.begin() + i);
	}
}

void DreamEngine::CollisionListener::parseContact(b2Contact * contact, Collision * collision, int * count, bool begin)
{
	b2Body * bodyA = contact->GetFixtureA()->GetBody();
	b2Body * bodyB = contact->GetFixtureB()->GetBody();

	if (bodyA->GetUserData() == nullptr || bodyB->GetUserData() == nullptr) return;

	DreamEngine::Shape * shapeA = (DreamEngine::Shape*)bodyA->GetUserData();
	DreamEngine::Shape * shapeB = (DreamEngine::Shape*)bodyB->GetUserData();

	if (begin) setCollision(collision, shapeA, shapeB, contact, collision->type = CollisionType::BEGINSS);
	else setCollision(collision, shapeA, shapeB, contact, collision->type = CollisionType::ENDSS);
	collision++;
	(*count)++;

	if (shapeB->parent != nullptr) {
		if (begin) setCollision(collision, (DreamEngine::Actor*)shapeB->parent, shapeA, contact, collision->type = CollisionType::BEGINAS);
		else setCollision(collision, (DreamEngine::Actor*)shapeB->parent, shapeA, contact, collision->type = CollisionType::ENDAS);
		collision++;
		(*count)++;
	}
	if (shapeA->parent != nullptr) {
		if (begin) setCollision(collision, (DreamEngine::Actor*)shapeA->parent, shapeB, contact, collision->type = CollisionType::BEGINAS);
		else setCollision(collision, (DreamEngine::Actor*)shapeA->parent, shapeB, contact, collision->type = CollisionType::ENDAS);
		collision++;
		(*count)++;
	}
	if (shapeA->parent != nullptr && shapeB->parent != nullptr) {
		DreamEngine::Actor * actorA = (DreamEngine::Actor*)shapeA->parent;
		DreamEngine::Actor * actorB = (DreamEngine::Actor*)shapeB->parent;
		if (begin) setCollision(collision, actorA, actorB, contact, collision->type = CollisionType::BEGINAA);
		else setCollision(collision, actorA, actorB, contact, collision->type = CollisionType::ENDAA);
		(*count)++;
	}
}

void DreamEngine::CollisionListener::setCollision(Collision * collision, DreamEngine::Core::WorldObject * a, DreamEngine::Core::WorldObject * s, b2Contact * contact, CollisionType type)
{
	collision->a = a;
	collision->s = s;
	collision->contact = contact;
	collision->type = type;
}

void DreamEngine::CollisionListener::doBeginAACollision(Collision  collision)
{
	collision.a->beginCollision();
	collision.s->beginCollision();
	collision.a->beginActorCollision(collision.s, collision.contact);
	collision.s->beginActorCollision(collision.a, collision.contact);
}

void DreamEngine::CollisionListener::doEndAACollision(Collision  collision)
{
	collision.a->endCollision();
	collision.s->endCollision();
	collision.a->endActorCollision(collision.s, collision.contact);
	collision.s->endActorCollision(collision.a, collision.contact);
}

void DreamEngine::CollisionListener::doBeginASCollision(Collision  collision)
{
	collision.a->beginCollision();
	collision.s->beginCollision();
	collision.a->beginShapeCollision(collision.s, collision.contact);
	collision.s->beginActorCollision(collision.a, collision.contact);
}

void DreamEngine::CollisionListener::doEndASCollision(Collision  collision)
{
	collision.a->endCollision();
	collision.s->endCollision();
	collision.a->endShapeCollision(collision.s, collision.contact);
	collision.s->endActorCollision(collision.a, collision.contact);
}

void DreamEngine::CollisionListener::doBeginSSCollision(Collision  collision)
{
	collision.a->beginCollision();
	collision.s->beginCollision();
	collision.a->beginShapeCollision(collision.s, collision.contact);
	collision.s->beginShapeCollision(collision.a, collision.contact);
}

void DreamEngine::CollisionListener::doEndSSCollision(Collision  collision)
{
	collision.a->endCollision();
	collision.s->endCollision();
	collision.a->endShapeCollision(collision.s, collision.contact);
	collision.s->endShapeCollision(collision.a, collision.contact);
}
