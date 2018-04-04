#include "Lightning.h"

DreamEngine::Lightning::Lightning(LightningDef def)
{
	texture = new sf::Texture;
	texture->create(def.windowSize.x, def.windowSize.y);
}

DreamEngine::DirectionalLightning::DirectionalLightning(DirectionalLightningDef def)
	:world(def.world), forward(def.forward), position(def.position), line(sf::LinesStrip, 2), viewport(Engine::pixelToWorld(def.windowSize)), range(def.range),window(def.window), Lightning(def)
{
	line[0].color = sf::Color::White;
	line[1].color = sf::Color::White;
}

sf::Texture * DreamEngine::DirectionalLightning::get()
{
	
	b2AABB queryRange;
	queryRange.lowerBound = position;
	queryRange.upperBound = position + viewport;
	world->QueryAABB(this, queryRange);


	world->RayCast(this, position, position + (range * forward));

	/*sf::Image image;
	image.create(100, 100);*/

	/*
	
	
		Min versuech:
		
		en area query

		denn en ray vumne punkt vo forward weg her luege obs überdeckt wird, so wird jedes object beachtet
	
	
	*/

	

	window->draw(line);


	return nullptr;
}

float32 DreamEngine::DirectionalLightning::ReportFixture(b2Fixture * fixture, const b2Vec2 & point, const b2Vec2 & normal, float32 fraction)
{

	

	//std::cout << "hit: " << Engine::worldToPixel(position).x << "#" << Engine::worldToPixel(position).y << "#" << Engine::worldToPixel(point).x << "#" << Engine::worldToPixel(point).y << std::endl;

	line[0].position = Engine::worldToPixel(position);
	line[1].position = Engine::worldToPixel(point);


	
	

	/*line[0].color.a = fraction;
	line[1].color.a = fraction;*/

	window->draw(line);

	//Engine::waitForKeyPress();

	return fraction;

	// -1 filters out
	// 1 continue like this fixture doesnt exist
	// 0 End

}

bool DreamEngine::DirectionalLightning::ReportFixture(b2Fixture * fixture)
{

	if (fixture->GetType() == b2Shape::Type::e_polygon) {
		b2PolygonShape * poylgon = (b2PolygonShape*)fixture->GetShape();


		/*HitByRaycastCallback
			check for hits;
			*/

	}



	return false;
}

DreamEngine::HitByRaycastCallback::HitByRaycastCallback(b2Shape * shape)
	:shape(shape)
{
}

float32 DreamEngine::HitByRaycastCallback::ReportFixture(b2Fixture * fixture, const b2Vec2 & point, const b2Vec2 & normal, float32 fraction)
{

	if (shape == fixture->GetShape()) hit = true;

	return 1.f;
}

bool DreamEngine::HitByRaycastCallback::isHit()
{
	return hit;
}
