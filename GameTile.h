#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class GameTile
{
public:
	bool isPassable;
	bool isExit;
	Vector2f pos;
	Texture texture;
	Sprite sprite;
	GameTile(string, float, float, bool, bool);
	bool setUpSprite(string);
};

