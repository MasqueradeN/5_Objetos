#include "Entity.h"
#include "ofMain.h"

Entity::Entity()
{
	name = "xd";
	health = 0;
	velocity = new ofVec2f(0, 0);
}

const char* Entity::toString()
{
	return name.c_str();
}

void Entity::draw()
{
	ofSetColor(ofColor::chartreuse);
	ofDrawCircle(posx, posy, 25);
}
