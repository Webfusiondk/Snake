#include "Snake.h"
#include <vector>

void Snake::CreateBodyPart()
{
	if (this->snake.size() < this->snakeLenght)
	{
		this->snake.push_back(SDL_Rect{ snake.back().x,snake.back().y + 30,25,25 });
	}
}

void Snake::CreateSnakeHead()
{
	SDL_Rect base = { 350,350,25,25 };
	SDL_Rect leftEye = { base.x + 5, base.y + 5, 5,5 };
	SDL_Rect rightEye = { base.x + 15, base.y + 5, 5,5 };
	this->snake.push_back(leftEye);
	this->snake.push_back(rightEye);
	this->snake.push_back(base);
}

int Snake::GetSpeed()
{
	return speed;
}

int Snake::GetSnakeLenght()
{
	return this->snakeLenght;
}

std::vector<SDL_Rect> Snake::GetSnake()
{
	return snake;
}

void Snake::SetSnakeLenght()
{
	this->snakeLenght++;
	CreateBodyPart();
}

void Snake::SetSnakeBodyPart(int x, int y)
{
	for (int i = snake.size(); i-- > 0;)
	{
		if (i <= 2)
		{
			snake[i].x += x;
			snake[i].y += y;
		}
		if (i > 2)
		{
			snake[i].x = snake[i - 1].x;
			snake[i].y = snake[i - 1].y;
		}
	}
}

Snake::Snake()
{
	CreateSnakeHead();
}
