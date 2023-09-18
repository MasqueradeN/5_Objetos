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
	ofSetColor(setColor(color));
	ofDrawCircle(posx, posy, 15);
}

ofColor Entity::setColor(ofColor _color)
{
	color = _color;
	return _color;
}

void Entity::setSprite(std::string _sprite)
{
	entitySprite.load(_sprite);
}
