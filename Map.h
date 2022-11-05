#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameTile.h"
#include "Hero.h"

using namespace std;
using namespace sf;

class Map
{
public:
	/*int map[10][10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };*/
	int width = 0;
	int height = 0;
	int tabsize = 10;
	int sideTiles[4][2];
	Vector2i tileSize;
	int map[10][10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
						0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	vector<GameTile> tiles;
	void getLevel();
	void draw(RenderWindow& window);
	int checkCollision(Hero hero);
	void getSideTiles(int x, int y);
};

