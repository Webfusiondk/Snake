#pragma once
#include "Snake.h"
#include <time.h>
#include "SDL.h"
#include "Window.h"
#include "Movement.h"
class GameManager {
public:
	SDL_Rect GetCurrentFood();
	GameManager(Window* gameWindow);
	void SnakeEatFood(Snake* snake);
	void SpawnFood();
	void StartGame(Snake* snake);
	void StartGameOnSpacePress();
	void SetCurrentFood(SDL_Rect food);
	void PosConverter(SDL_Rect food);
	SDL_Rect CreateFood();
private:
	void OutOfBounch(Snake* snake);
	bool notDead = false;
	Window* window;
	Movement m;
	SDL_Rect currentFood;
	bool isFoodActive = false;
};