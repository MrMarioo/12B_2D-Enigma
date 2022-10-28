#include "Hero.h"
#include "Engine.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <chrono>

using namespace std;
using namespace sf;

#define HERO_WIDTH 50;
#define HERO_HEIGHT 100;
#define HERO_SPEED 5;
#define HERO_FALL_SPEED 5;

int endjump = 1;

void Hero::init()
{
	x = 100;
	y = 100;
	width = HERO_WIDTH;
	height = HERO_HEIGHT;
	falling = 0;
	jumping = 0;
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
		if (Keyboard::isKeyPressed(Keyboard::W)) { direction[0] = 1; moving = 1; }
		if (Keyboard::isKeyPressed(Keyboard::A)) { direction[1] = 1; moving = 1; }
		if (Keyboard::isKeyPressed(Keyboard::S)) { direction[2] = 1; moving = 1; }
		if (Keyboard::isKeyPressed(Keyboard::D)) { direction[3] = 1; moving = 1; }
		
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

void Hero::crouch()
{
	(crouching ? crouching = 0 : crouching = 1);
	if (crouching)
		shape.setSize(Vector2f(width, height/2));
	else
	{
		shape.setSize(Vector2f(width, height));
		y -= height / 2;
	}
}

double Hero::getbottom()
{
	return y + height ;
}

