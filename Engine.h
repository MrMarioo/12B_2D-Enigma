#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Hero.h"
#include "Map.h"

using namespace std;
using namespace sf;

class Engine
{
public:
	Map map;
	RenderWindow window;
	RectangleShape heroShape;
	Texture texture;
	Sprite sprite;
	Hero hero;
	Clock clock;
	Time elapsed;
	int width = 500;
	int height = 500;
	int init() {
		int success = 0;
		//inicjalizacja bibliotek
		map.getLevel();
		hero.init();
		return success;
	};

	void update()
	{
		//update commands
		hero.update(window);
	}

	void draw()
	{
		window.clear(Color::Black);
		map.draw(window);
		hero.draw(window);
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


