/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include <memory>

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
	auto image{make_unique<Image>("img/0.bmp")};
	if (!image->wasSuccessful())
	{
		printf("Failed to load media!\n");
		return -1;
	}
	//Load media when space is pressed



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
				case SDLK_RETURN:
					image = std::move(make_unique<Image>( "img/1.bmp" ));
				}
				break;
			}
			else if (e.type == SDL_KEYUP && !e.key.repeat) {
				switch (e.key.keysym.sym) {
				case SDLK_RETURN:
					image = std::move(make_unique<Image>("img/0.bmp"));
				}
				break;
			}
		}
		window.render(*image);
	}

	return 0;
}







