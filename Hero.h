#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"


using namespace std;
using namespace sf;

class Hero
{
public:
	RectangleShape shape;
	vector<Bullet> bulletVec;
	int width;
	int height;
	float x = 0, y = 0;
	float xtemp, ytemp;
	float movespeed;
	float fallspeed;
	char direction[4] = { 0,0,0,0 };
	bool falling;
	bool jumping;
	bool moving;
	bool crouching;
	bool shooting;
	void init();
	void draw(RenderWindow& window);
	void input();
	void update(RenderWindow& window);
	void die();
	void shoot(RenderWindow& window);
	void move();
	void fall();
	void crouch();
	float getbottom();
	float gettop();
	float getleft();
	float getright();
};

