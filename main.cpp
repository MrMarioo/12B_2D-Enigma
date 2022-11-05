#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Engine.h"

using namespace std;
using namespace sf;

int main()
{
	Engine engine;
	if (engine.init() == 0)
		cout << "Initiation complete correctly\n";

	engine.gameLoop();
	return 0;
}