#include "Window.h"
#include "Movement.h"
static SDL_Renderer* render;

Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags)
{
	window = SDL_CreateWindow(title, x, y, w, h, flags);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Window::Update()
{
	SDL_RenderPresent(render);
	Clear();
}

void Window::Clear()
{
	SDL_RenderClear(render);
}

void Window::DrawSnake(Snake* snake)
{
	std::vector<SDL_Rect> snakeBody = snake->GetSnake();
	for (int i = 2; i < snakeBody.size(); i++)
	{
		SDL_SetRenderDrawColor(render, 179, 0, 13, 255);
		SDL_RenderDrawRect(render, &snakeBody[i]);
		SDL_RenderFillRect(render, &snakeBody[i]);
	}
	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	SDL_RenderDrawRect(render, &snakeBody[0]);
	SDL_RenderDrawRect(render, &snakeBody[1]);
	SDL_RenderFillRect(render, &snakeBody[0]);
	SDL_RenderFillRect(render, &snakeBody[1]);
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
}

void Window::DrawFood(SDL_Rect food)
{
	SDL_SetRenderDrawColor(render, 255, 201, 31, 255);
	SDL_RenderDrawRect(render, &food);
	SDL_RenderFillRect(render, &food);
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
}

SDL_Renderer* Window::CreateRenderer()
{
	return render;
}

