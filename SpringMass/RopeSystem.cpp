#include "RopeSystem.h"

RopeSystem::RopeSystem()
{
	ropes.push_back(new Spring(600, 400, 15, 200, 'b'));
}

RopeSystem::~RopeSystem()
{
}

void RopeSystem::update()
{
	for (int i = 0; i < ropes.size(); i++)
		ropes[i]->update();
}

void RopeSystem::draw()
{
	for (int i = 0; i < ropes.size(); i++)
		ropes[i]->draw();
}