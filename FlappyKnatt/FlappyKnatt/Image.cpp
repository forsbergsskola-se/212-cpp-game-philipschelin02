#include "Image.h"
#include "SDL.h"
#include <cstdio>

Image::Image(const char* path) : success{}, path{ path } {

	//Load splash image
	imageSurface = SDL_LoadBMP(path);
	if (!imageSurface)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}
	printf("Created Image: %s\n", path);
	success = true;
}

Image::~Image() {
	printf("Destroyed Image: %s\n", path);
	//Dealloacate surface
	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
}