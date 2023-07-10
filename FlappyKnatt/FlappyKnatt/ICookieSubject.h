#pragma once
#include <vector>
#include "ICookieObserver.h"
class ICookieSubject {
private:
    std::vector<ICookieObserver*> cookieObservers;
public:
    void addObserver(ICookieObserver* observer) {
        cookieObservers.push_back(observer);
    }
    void removeObserver(ICookieObserver* observer) {
        cookieObservers.erase(std::remove(cookieObservers.begin(), cookieObservers.end(), observer), cookieObservers.end());
    }
    void raiseCookie(ICookieSubject* subject) {
        for (auto observer : cookieObservers) {
            // notify observer that we died
            observer->notifyCookie(*this);
        }
    }
};
