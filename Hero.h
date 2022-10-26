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
	double x;
	double y;
	double movespeed;
	double fallspeed;
	char direction;
	bool falling;
	bool moving;
	void init();
	RectangleShape draw();
	void input();
	void update();
	void die();
	void shoot();
	void move();
	void fall();

};

