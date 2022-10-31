#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using namespace std;
using namespace sf;

#define BULLET_WIDTH 5.f;
#define BULLET_HEIGHT 2.f;

class Bullet
{
public:
	Bullet(int x, int y, int xdest, int ydest);
	RectangleShape shape;
	Vector2i destPoint;
	Vector2f shiftVec = Vector2f(0,0);
	float x = 0.f, y = 0.f;
	float xtemp = 0.f, ytemp = 0.f;
	float xVelocity = 0.f, yVelocity = 0.f;
	float angle = 0.f;
	float width = BULLET_WIDTH;
	float height = BULLET_HEIGHT;
	float speed = 5.f;
	void draw(RenderWindow& window);
	void update();
	void checkCollision();
	void calcVector();

};

