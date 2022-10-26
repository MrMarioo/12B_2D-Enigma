#include "Hero.h"
#include "Engine.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

#define HERO_WIDTH 50;
#define HERO_HEIGHT 50;
#define HERO_SPEED 5;
#define HERO_FALL_SPEED 5;

void Hero::init()
{
	x = 100;
	y = 100;
	width = HERO_WIDTH;
	height = HERO_HEIGHT;
	falling = 0;
	movespeed = HERO_SPEED;
	fallspeed = HERO_FALL_SPEED;
	shape.setPosition(Vector2f(x, y));
	shape.setSize(Vector2f(width, height));
	shape.setFillColor(Color::Green);
	puts("Hero initiation complete");
}

RectangleShape Hero::draw()
{
	//window.draw(shape);
	return shape;
}

void Hero::input()
{
	Event event;
		if (event.KeyReleased) { moving = 0; }
		if (Keyboard::isKeyPressed(Keyboard::W)) { direction = 'w'; moving = 1; }
		if (Keyboard::isKeyPressed(Keyboard::A)) { direction = 'a'; moving = 1; }
		if (Keyboard::isKeyPressed(Keyboard::S)) { direction = 's'; moving = 1; }
		if (Keyboard::isKeyPressed(Keyboard::D)) { direction = 'd'; moving = 1; }
		
}

void Hero::update()
{
	move();
	fall();
	shape.setPosition(x, y);
}

void Hero::move()
{
	if (moving)
	{
		switch (direction)
		{
			case 'w':
			{
				falling = 0;
				break;
			}
			case 'a':
			{
				x -= movespeed;
				break;
			}
			case 's':
			{
				//crouch = 1;
				break;
			}
			case 'd':
			{
				x += movespeed;
				break;
			}
		default:
			break;
		}
	}
}

void Hero::fall()
{
	(y < 500 ? falling = 1 : falling = 0);
	if (falling)
		y += fallspeed;
}
