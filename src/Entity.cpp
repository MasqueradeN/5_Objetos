#include "Entity.h"
#include "ofMain.h"

Entity::Entity()
{
	name = "xd";
	health = 0;
}

const char* Entity::toString()
{
	return name.c_str();
}

void Entity::draw()
{
	ofSetColor(ofColor::chartreuse);
	ofCircle(posx, posy, 25);
}
