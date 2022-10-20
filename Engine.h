#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

#define DEFAULT_WIDTH 400;
#define DEFAULT_HEIGHT 400;

class Engine
{
public:
	RenderWindow window;
	bool fullscreen;
	bool mediumscreen;
	bool fullrefresh;
	bool color_pattern;
	int width;
	int height;
	int R = 0, G = 255;

	Engine() {
		fullscreen = 0;
		mediumscreen = 0;
		fullrefresh = 0;
		width = DEFAULT_WIDTH;
		height = DEFAULT_HEIGHT;
		color_pattern = 0;
	};
	int init() {
		int success = 0;
		//inicjalizacja bibliotek
		return success;
	};

	void update()
	{
		//update commands
	}

	void draw()
	{
		if (R == 255 || R == 0) { color_pattern = !color_pattern; puts("color patter changed"); }
		if(color_pattern){ R++; G--; }
		else { R--; G++; }
		window.clear(Color(R, G, 10,255));
		window.display();
	}

	void input()
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
			if (Keyboard::isKeyPressed(Keyboard::F))
			{
				if (fullscreen) window.create(VideoMode::getFullscreenModes()[0], "Window");
				if (!fullscreen) window.create(VideoMode(width, height), "Window");
				fullscreen = !fullscreen;
				puts("Fullscreen changed");
			}
			if (Keyboard::isKeyPressed(Keyboard::O))
			{
				if (fullrefresh) window.setFramerateLimit(60);
				if (!fullrefresh) window.setFramerateLimit(30);
				fullrefresh = !fullrefresh;
				puts("Framerate changed");
			}
			/*if (Keyboard::isKeyPressed(Keyboard::G))
			{
				if (mediumscreen) window.create(VideoMode(width, height), "Window");
				if (!mediumscreen) window.create(VideoMode(2*width, 2*height), "Window");
				mediumscreen = !mediumscreen;
			}*/
		}
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
		}

		return 0;
	}
	~Engine() = default;
};

