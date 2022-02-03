#include "Movement.h"
#include <iostream>
void Movement::CheckForKeyDownInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_w)
		{
			currentDirection = Direction::Up;
		}
		if (event.key.keysym.sym == SDLK_s)
		{
			currentDirection = Direction::Down;
		}
		if (event.key.keysym.sym == SDLK_a)
		{
			currentDirection = Direction::Left;
		}
		if (event.key.keysym.sym == SDLK_d)
		{
			currentDirection = Direction::Right;
		}
	}
}

void Movement::MoveSnake(Snake* snake)
{
	if (currentDirection == Direction::Up)
		snake->SetSnakeBodyPart(0, -25);
	if (currentDirection == Direction::Down)
		snake->SetSnakeBodyPart(0, 25);
	if (currentDirection == Direction::Left)
		snake->SetSnakeBodyPart(-25, 0);
	if (currentDirection == Direction::Right)
		snake->SetSnakeBodyPart(25, 0);
}

