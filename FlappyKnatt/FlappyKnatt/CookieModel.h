#pragma once
#include "ICookieSubject.h"
class CookieModel : public ICookieSubject
{
	int cookies{};
public:
	void addCookie() {
		cookies++;
		raiseCookie(this);
	}
	int getCookies() {
		return cookies;
	}

};

