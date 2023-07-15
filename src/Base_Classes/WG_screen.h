#if !defined(WG_SCREEN_H)
#define WG_SCREEN_H

#include <SDL2/SDL.h>

class Screen
{
    protected:
        SDL_Renderer* screenRenderer;
        SDL_Event* screenEvents;

    public:
        Screen();
        virtual void onInit(SDL_Renderer* renderer, SDL_Event* events);
        virtual void onEvent(void);
        virtual void onLoop(void);
        virtual bool onRender(int r, int g, int b, int a);
        virtual void onCleanup(void);
};

#endif // WG_SCREEN_H
