#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using namespace std;
using namespace sf;

class Bullet
{
public:
	int destPoint;
	float x, y;
	float xtemp, ytemp;
	float angle;
	float size = 5.f;
	float speed = 5.f;
	Vector2f vec;
	RectangleShape shape;
	void init(float x, float y);
	void draw();
	void update();
	void checkCollision();
	void calcVector();

};

