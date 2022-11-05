#include "GameTile.h"

GameTile::GameTile(string textureName, float x, float y, bool passable, bool exit)
{
	if (!setUpSprite(textureName))
		return;
	pos = Vector2f(x, y);
	sprite.setPosition(pos);
	isPassable = passable;
	isExit = exit;
}

bool GameTile::setUpSprite(string textureName)
{
	if (!texture.loadFromFile("images/wall.png"))
		return false;
	//texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 50, 50));
	return true;
}