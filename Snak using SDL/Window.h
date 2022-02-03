#pragma once
#include "SDL.h"
#include <vector>
#include "Snake.h"
class Window {
public:
	Window(const char* title, int x, int y, int w, int h, Uint32 flags);
	void Update();
	void Clear();
	void DrawSnake(Snake* snake);
	void DrawFood(SDL_Rect food);
	static SDL_Renderer* CreateRenderer();
private:
	SDL_Window* window;
};