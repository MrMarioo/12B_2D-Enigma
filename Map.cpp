#include "Map.h"

#define SIZE 50;

string wall = "images/wall.png";

void Map::getLevel()
{
	tileSize.x = SIZE;
	tileSize.y = SIZE;
	for (int i = 0; i < 10; i++) 
		for(int j = 0; j < 10; j++) {
			if (map[j][i] == 1)
			{
				tiles.push_back(GameTile(wall, i * 50, j * 50, false, false));
			}
		}
}

void Map::draw(RenderWindow& window)
{
	for (int i = 0; i < tiles.size(); i++)
		window.draw(tiles.at(i).sprite);
}

void Map::getSideTiles(int x, int y)
{
	sideTiles[0][0] = floor(x / 50) + 1;//W
	sideTiles[0][1] = floor(x / 50);
	sideTiles[1][0] = floor(y / 50) - 1;//A
	sideTiles[1][1] = floor(y / 50);
	sideTiles[2][0] = floor(x / 50) - 1;//S
	sideTiles[2][1] = floor(x / 50);
	sideTiles[3][0] = floor(y / 50) + 1;//D
	sideTiles[3][1] = floor(y / 50);
}

int Map::checkCollision(Hero hero)
{
	getSideTiles(hero.x, hero.y);
	if (hero.direction[0] == 1 && map[sideTiles[0][0]][sideTiles[0][1]] == 1)
		return 1;
	if (hero.direction[1] == 1 && map[sideTiles[1][0]][sideTiles[1][1]] == 1)
		return 2;
	if (hero.falling && map[sideTiles[2][0]][sideTiles[2][1]] == 1)
		return 3;
	if (hero.direction[3] == 1 && map[sideTiles[3][0]][sideTiles[3][1]] == 1)
		return 4;
	return 0;
}