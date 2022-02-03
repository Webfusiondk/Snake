#pragma once
#include "SDL.h"
#include <vector>

class Snake {
public:
	void CreateBodyPart();
	void CreateSnakeHead();
	int GetSpeed();
	int GetSnakeLenght();
	std::vector<SDL_Rect> GetSnake();

	void SetSnakeLenght();
	void SetSnakeBodyPart(int x, int y);
	Snake();
private:
	int speed = 25;
	int snakeLenght = 3;
	std::vector<SDL_Rect> snake;
};