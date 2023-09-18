#pragma once
#include <string>
#include <random>
#include "ofMain.h"
//#include "StringArray.h"

class Entity
{
public:
	std::string name;
	int health;

	ofColor color;

	Entity();

	const char* toString();

	float posx, posy;
	ofVec2f* velocity;
	ofImage entitySprite;

	void draw();

	ofColor setColor(ofColor _color);
	void setSprite(std::string _sprite);
};

//template<>
//inline void StringArray<Entity>::listContents()
//{
//	for (int i = 0; i < bruhSize; i++)
//	{
//		std::cout << "[" << i << "] = " << arrayz[i].toString() << "\n";
//	}
//}