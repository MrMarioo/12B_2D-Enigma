#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using namespace std;
using namespace sf;

class Hero
{
public:
	RectangleShape shape;
	int width;
	int height;
	float x=0;
	float y=0;
	float movespeed;
	float fallspeed;
	char direction[4] = { 0,0,0,0 };
	bool falling;
	bool jumping;
	bool moving;
	bool crouching;
	void init();
	RectangleShape draw();
	void input();
	void update();
	void die();
	void shoot();
	void move();
	void fall();
	void crouch();
	double getbottom();
};

