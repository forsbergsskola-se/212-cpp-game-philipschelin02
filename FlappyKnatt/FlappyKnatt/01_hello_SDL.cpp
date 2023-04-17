/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include <memory>
#include <SDL_ttf.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 421;
const int SCREEN_HEIGHT = 212;

using namespace std;

int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	//Start up SDL and create window
	if (!window.wasSuccessful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}


	//Load media
	auto image{make_unique<Image>("img/0.bmp", window.screenRenderer)};
	if (!image->wasSuccessful())
	{
		printf("Failed to load media!\n");
		return -1;
	}
	//Load text
	TTF_Init();
	auto gFont = TTF_OpenFont("font/lazy.ttf", 28);
	SDL_Color textColor = { 0, 0, 0 };
	int cookies = 0;
	// DO ALL OF THIS AGAIN IN LINE 74
	string cookieText = to_string(cookies);
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, cookieText.c_str(), textColor);
	auto textTexture = SDL_CreateTextureFromSurface(window.screenRenderer, textSurface);
	SDL_FreeSurface(textSurface);
	auto mWidth = textSurface->w;
	auto mHeight = textSurface->h;
	// ALL UP TO HERE
	// BUT DON'T DO:   string cookieText = .... but instead just cookieText = ...
	// ALSO NOT auto textTexture = ... but instead textTexture = ...


	// while(!window.quit())
	//     window.update();

	//Hack to get window to stay up
	SDL_Event e; bool quit = false;
	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN && !e.key.repeat) {
				switch (e.key.keysym.sym) {
				case SDLK_SPACE:
					image = std::move(make_unique<Image>( "img/1.bmp", window.screenRenderer));

					// increment cookies
					cookies++;
					SDL_DestroyTexture(textTexture);
					cookieText = to_string(cookies);
					textSurface = TTF_RenderText_Solid(gFont, cookieText.c_str(), textColor);
					textTexture = SDL_CreateTextureFromSurface(window.screenRenderer, textSurface);
					SDL_FreeSurface(textSurface);
					mWidth = textSurface->w;
					mHeight = textSurface->h;
				}
				break;
			}
			else if (e.type == SDL_KEYUP && !e.key.repeat) {
				switch (e.key.keysym.sym) {
				case SDLK_SPACE:
					image = std::move(make_unique<Image>("img/0.bmp", window.screenRenderer));
				}
				break;
			}
		}
		window.render(*image, textTexture, SDL_Rect{SCREEN_WIDTH/2-mWidth/2,SCREEN_HEIGHT/3-mHeight/2, mWidth, mHeight});
	}

	return 0;
}







