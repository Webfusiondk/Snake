#define SDL_MAIN_HANDLED
#include "Snake.h"
#include <iostream>
#include "Movement.h"
#include "Window.h"
#include "GameManager.h"

int main() {
	Window* w = new Window("main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
	GameManager* manger = new GameManager(w);
	Snake* snake = new Snake();
	while (true)
	{
		manger->StartGame(snake);
		w->Update();
		SDL_Delay(100);
	}
	return 0;
}