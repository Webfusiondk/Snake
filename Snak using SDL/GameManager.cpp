#include "GameManager.h"

SDL_Rect GameManager::GetCurrentFood()
{
	return currentFood;
}

GameManager::GameManager(Window* gameWindow)
{
	this->window = window;
}

void GameManager::SnakeEatFood(Snake* snake)
{
	std::vector<SDL_Rect> snakeBody = snake->GetSnake();
	if (snakeBody[2].x == currentFood.x && snakeBody[2].y == currentFood.y)
	{
		isFoodActive = false;
		snake->SetSnakeLenght();
	}
}

void GameManager::SpawnFood()
{
	if (!isFoodActive)
		PosConverter(CreateFood());
	window->DrawFood(currentFood);
}

void GameManager::StartGame(Snake* snake)
{
	if (!notDead)
	{
		m.CheckForKeyDownInput();
		m.MoveSnake(snake);
		window->DrawSnake(snake);
		OutOfBounch(snake);
		SpawnFood();
		SnakeEatFood(snake);
	}
}

void GameManager::SetCurrentFood(SDL_Rect food)
{
	this->currentFood = food;
}

void GameManager::PosConverter(SDL_Rect food)
{
	int newPosX = food.x;
	int newPosY = food.y;
	int tempPosX = food.x;
	int tempPosY = food.y;
	int digtis = 0;
	int lastnumberX = 0;
	int lastnumberY = 0;
	if (food.x > 100)
	{
		digtis = 0;
		while (tempPosX != 0)
		{
			digtis++;
			lastnumberX = tempPosX % 10;
			tempPosX = tempPosX / 10;
		}
		newPosX = newPosX % (lastnumberX * (int)pow(10, digtis - 1));

	}
	if (newPosX < 25 && newPosX > 0)
		food.x = lastnumberX * 100 + 25;

	if (newPosX < 50 && newPosX > 25)
		food.x = lastnumberX * 100 + 50;

	if (newPosX < 75 && newPosX > 50)
		food.x = lastnumberX * 100 + 75;

	if (newPosX < 100 && newPosX > 75)
		food.x = lastnumberX * 100 + 100;

	if (food.y > 100)
	{
		digtis = 0;
		while (tempPosY != 0)
		{
			digtis++;
			lastnumberY = tempPosY % 10;
			tempPosY = tempPosY / 10;
		}
		newPosY = newPosY % (lastnumberY * (int)pow(10, digtis - 1));
	}

	if (newPosY < 25 && newPosY > 0)
		food.y = lastnumberY * 100 + 25;

	if (newPosY < 50 && newPosY > 25)
		food.y = lastnumberY * 100 + 50;

	if (newPosY < 75 && newPosY > 50)
		food.y = lastnumberY * 100 + 75;

	if (newPosY < 100 && newPosY > 75)
		food.y = lastnumberY * 100 + 100;

	if (food.x > 750)
		food.x = 750;

	if (food.y > 750)
		food.y = 750;

	isFoodActive = true;
	SetCurrentFood(food);

}

SDL_Rect GameManager::CreateFood()
{
	SDL_Rect food{ rand() % 750,rand() % 750,25,25 };
	return food;
}

void GameManager::OutOfBounch(Snake* snake)
{
	std::vector<SDL_Rect> snakeBody = snake->GetSnake();
	if (snakeBody[2].x > 800 || snakeBody[2].x < 0 || snakeBody[2].y > 800 || snakeBody[2].y < 0)
	{
		notDead = true;
	}

	if (snakeBody.size() >= 4)
	{
		for (int i = snakeBody.size(); i-- > 3;)
		{
			if (snakeBody[2].x == snakeBody[i].x && snakeBody[2].y == snakeBody[i].y)
			{
				notDead = true;
			}
		}
	}
}
