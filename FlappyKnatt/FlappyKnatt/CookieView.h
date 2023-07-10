#pragma once
#include "ICookieObserver.h"
#include <SDL_ttf.h>
#include <string>
#include "Window.h"
#include "CookieModel.h"
using namespace std;
class CookieView : ICookieObserver
{
public :
	SDL_Texture* textTexture;
	TTF_Font* gFont;
	SDL_Color textColor = { 0, 0, 0 };
	Window* window;
	CookieModel* cookiemodel;
	int mWidth;
	int mHeight;
	CookieView(TTF_Font* gFont, Window* window, CookieModel* cookiemodel) {
		this->gFont = gFont;
		this->window = window;
		this->cookiemodel = cookiemodel;
		cookiemodel->addObserver(this);
		string cookieText = to_string(cookiemodel->getCookies());
		SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, cookieText.c_str(), textColor);
		textTexture = SDL_CreateTextureFromSurface(window->screenRenderer, textSurface);
		SDL_FreeSurface(textSurface);
		mWidth = textSurface->w;
		mHeight = textSurface->h;
	}

	~CookieView()
	{

	}

	virtual void notifyCookie(ICookieSubject& subject) override {
		SDL_DestroyTexture(textTexture);
		auto cookieText = to_string(cookiemodel->getCookies());
		auto textSurface = TTF_RenderText_Solid(gFont, cookieText.c_str(), textColor);
		textTexture = SDL_CreateTextureFromSurface(window->screenRenderer, textSurface);
		SDL_FreeSurface(textSurface);
		mWidth = textSurface->w;
		mHeight = textSurface->h;
	}
};

