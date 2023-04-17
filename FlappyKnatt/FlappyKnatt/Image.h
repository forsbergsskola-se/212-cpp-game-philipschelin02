#pragma once
#include <SDL.h>
#include <cstdio>
class Image
{
	//The image we will load and show on screen
	SDL_Texture* texture{};
	bool success;
	const char* path;
public:
	Image(const char* path, SDL_Renderer* renderer);
	Image(const Image& other) = delete;
	Image& operator=(const Image& other) = delete;
	~Image();
	bool wasSuccessful() { return success; }
	SDL_Texture* getResource() { return texture; }
};

