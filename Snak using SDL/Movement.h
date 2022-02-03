#pragma once
#include "SDL.h"
#include "Snake.h"
enum class Direction
{
	Up,
	Down,
	Left,
	Right
};

class Movement {
public:
	void CheckForKeyDownInput();
	void MoveSnake(Snake* snake);
private:
	Direction currentDirection;
};