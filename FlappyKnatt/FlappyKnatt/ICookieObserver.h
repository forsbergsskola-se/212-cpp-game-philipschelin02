#pragma once
class ICookieSubject;
class ICookieObserver {
public:
    virtual ~ICookieObserver() {};
    virtual void notifyCookie(ICookieSubject& subject) = 0;
};