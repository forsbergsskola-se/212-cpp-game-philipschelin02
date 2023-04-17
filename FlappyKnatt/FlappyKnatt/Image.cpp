#include "Image.h"
#include "SDL.h"
#include <cstdio>

Image::Image(const char* path, SDL_Renderer* renderer) : success{}, path{ path } {

	//Load splash image
	auto imageSurface = SDL_LoadBMP(path);
	if (!imageSurface)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}
	printf("Created Image: %s\n", path);

	// create texture from surface

	texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
	if (texture == NULL)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
	}


	//Dealloacate surface
	SDL_FreeSurface(imageSurface);
	success = true;
}

Image::~Image() {
	// destroy texture
	SDL_DestroyTexture(texture);

	printf("Destroyed Image: %s\n", path);
	texture = nullptr;
}