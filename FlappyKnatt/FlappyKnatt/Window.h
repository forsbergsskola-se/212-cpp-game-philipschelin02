#pragma once
#include "Image.h"
class Window
{
	//The window we'll be rendering to
	SDL_Window* window{};
	//Whether Window Startup was successful
	bool success;

public:
	//The surface contained by the window
	SDL_Renderer* screenRenderer{};

	Window(int width, int height);
	~Window();
	bool wasSuccessful() { return success; }
	void render(Image& image);
};

