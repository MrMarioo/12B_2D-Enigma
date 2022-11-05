#include "Bullet.h"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

Bullet::Bullet(int x, int y, int xdest, int ydest)
{
	this->x = x;
	this->y = y;
	shape.setPosition(Vector2f(x, y));
	shape.setSize(Vector2f(width,height));
	shape.setFillColor(Color::Cyan);
	destPoint.x = xdest;
	destPoint.y = ydest;
	calcVector();
}
void Bullet::draw(RenderWindow &window)
{
	window.draw(shape);
}
void Bullet::calcVector()
{
	angle = atan2(destPoint.x - x, destPoint.y - y);
	if (abs(angle) > 2.2 || abs(angle) < 0.8)
	{
		float buff = width;
		width = height;
		height = buff;
		shape.setSize(Vector2f(width, height));
	}
	xVelocity = ((speed)*sin(1 * angle));
	yVelocity = ((speed)*cos(-1 * angle));
	shiftVec.x = xVelocity;
	shiftVec.y = yVelocity;
}
void Bullet::update()
{
	x += shiftVec.x;
	y += shiftVec.y;
	shape.setPosition(x, y);
}
void Bullet::checkCollision()
{

}