#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Hero.h"

using namespace std;
using namespace sf;

static RenderWindow window;

class Engine
{
public:
	RectangleShape heroShape;
	Hero hero;
	Clock clock;
	Time elapsed;
	int width = 800;
	int height = 600;
	int init() {
		int success = 0;
		//inicjalizacja bibliotek
		hero.init();
		return success;
	};

	void update()
	{
		//update commands
		hero.update();
	}

	void draw()
	{
		window.clear(Color::Black);
		heroShape = hero.draw();
		window.draw(heroShape);
		window.display();
	}

	void input()
	{
		Event event;
		while (window.pollEvent(event) )
		{
			if (event.type == Event::Closed) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
			if (Event::KeyReleased)
				clock.restart();//restart
		}
		hero.input();
	}

	int gameLoop()
	{
		window.create(VideoMode(width, height), "Window");
		window.setFramerateLimit(60);
		while (window.isOpen())
		{
			draw();
			input();
			update();
			elapsed = clock.getElapsedTime();
		}

		return 0;
	}
	~Engine() = default;
};


