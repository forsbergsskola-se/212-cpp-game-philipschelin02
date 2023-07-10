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
#include "CookieModel.h"
#include "CookieView.h"

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
	CookieModel cookieModel{};
	CookieView cookieView{ gFont, &window, &cookieModel };

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
 					cookieModel.addCookie();
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
		window.render(*image, cookieView.textTexture, SDL_Rect{SCREEN_WIDTH/2- cookieView.mWidth/2,SCREEN_HEIGHT/3- cookieView.mHeight/2, cookieView.mWidth, cookieView.mHeight});
	}

	return 0;
}







