#pragma once
#include <string>
#include <random>
//#include "StringArray.h"

class Entity
{
public:
	std::string name;
	int health;

	Entity();

	const char* toString();

	float posx, posy;

	void draw();
};

//template<>
//inline void StringArray<Entity>::listContents()
//{
//	for (int i = 0; i < bruhSize; i++)
//	{
//		std::cout << "[" << i << "] = " << arrayz[i].toString() << "\n";
//	}
//}