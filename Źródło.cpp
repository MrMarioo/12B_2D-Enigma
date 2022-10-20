#include <iostream>
#include "Engine.h"

int main() {
	Engine engine;
	if (engine.init() == 0)
		cout << "Initiation complete correctly\n";
	engine.gameLoop();
	return 0;
	
}