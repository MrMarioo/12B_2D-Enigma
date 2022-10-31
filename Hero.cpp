#include "Hero.h"
#include "Engine.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <chrono>

using namespace std;
using namespace sf;

#define HERO_WIDTH 50.f;
#define HERO_HEIGHT 100.f;
#define HERO_SPEED 5;
#define HERO_FALL_SPEED 5;

int endjump = 1;
int changecrouch = 1;
int nextshoot = 1;

void Hero::init()
{
	x = 100;
	y = 100;
	width = HERO_WIDTH;
	height = HERO_HEIGHT;
	falling = 0;
	jumping = 0;
	crouching = 0;
	shooting = 0;
	movespeed = HERO_SPEED;
	fallspeed = HERO_FALL_SPEED;
	shape.setPosition(Vector2f(x, y));
	shape.setSize(Vector2f(width, height));
	shape.setFillColor(Color::Green);
	puts("Hero initiation complete");
}

void Hero::draw(RenderWindow& window)
{
	window.draw(shape);
	for (int i = 0; i < bulletVec.size(); i++)
		bulletVec.at(i).draw(window);
}

void Hero::input()
{
	Event event;
		if (event.KeyReleased) { moving = 0; }
		if (Mouse::isButtonPressed(Mouse::Left)) { shooting= 1; }
		if (Keyboard::isKeyPressed(Keyboard::W)) { direction[0] = 1; moving = 1; }
		if (Keyboard::isKeyPressed(Keyboard::A)) { direction[1] = 1; moving = 1; }
		if (Keyboard::isKeyPressed(Keyboard::S)) { direction[2] = 1; moving = 1; }
		if (Keyboard::isKeyPressed(Keyboard::D)) { direction[3] = 1; moving = 1; }
		
}

void Hero::update(RenderWindow &window)
{
	move();
	fall();
	shoot(window);
	shape.setPosition(x, y);
	for (int i = 0; i < bulletVec.size(); i++)
		bulletVec.at(i).update();
}

void Hero::move()
{
	if (moving)
	{
		if (direction[0] == 1)
			if (endjump && !falling)
			{
				jumping = 1;
				endjump = 0;
			}
		if (direction[1] == 1)
			x -= movespeed;
		if (direction[2] == 1)
			crouch();
		if (direction[3] == 1)
			x += movespeed;
	}
	for (int i = 0; i < 4; i++)
		direction[i] = 0;
}

void jumpthread(int id)
{
	this_thread::sleep_for(chrono::milliseconds(500));
	endjump = 1;
}

void Hero::fall()
{
	(endjump && getbottom() < 500 ? falling = 1 : falling = 0);
	if (falling)
		y += fallspeed;
	if (!endjump)
		y -= fallspeed;
	if (jumping && !falling)
	{
		thread th1(jumpthread, 1);
		th1.detach();
		jumping = 0;
	}
			
}

void crouchhread(int id)
{
	this_thread::sleep_for(chrono::milliseconds(200));
	changecrouch = 1;
}

void Hero::crouch()
{
	if (changecrouch)
	{
		(crouching ? crouching = 0 : crouching = 1);
		if (crouching)
		{
			height = height / 2;
			shape.setSize(Vector2f(width, height));
			y += height;
			changecrouch = 0;
		}
		else
		{
			height = height * 2;
			shape.setSize(Vector2f(width, height));
			y -= height / 2;
			changecrouch = 0;
		}
		thread th2(crouchhread, 2);
		th2.detach();
	}

}

float Hero::getbottom()
{
	float ret = y + height;
	return ret;
}

void shoothread(int id)
{
	this_thread::sleep_for(chrono::milliseconds(100));
	nextshoot = 1;
}

void Hero::shoot(RenderWindow& window)
{
	if (shooting)
	{
		shooting = 0;
		if (nextshoot)
		{
			nextshoot = 0;
			Vector2i mouseCoord = Mouse::getPosition(window);
			Bullet newBullet(this->x, this->y, mouseCoord.x, mouseCoord.y);
			//cout << "x: " << mouseCoord.x << " y: " << mouseCoord.y << endl;
			if (bulletVec.size() > 5)
				bulletVec.erase(bulletVec.begin());
			bulletVec.push_back(newBullet);
			thread th3(shoothread, 3);
			th3.detach();
		}
	}
}

