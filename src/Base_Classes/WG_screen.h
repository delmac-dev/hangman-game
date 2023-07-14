#if !defined(_WG_SCREEN_H_)
#define _WG_SCREEN_H_

#include <SDL2/SDL.h>

class Screen
{
    public:
        virtual void onInit(void);
        virtual void onEvent(void);
        virtual void onLoop(void);
        virtual bool onRender(SDL_Renderer* renderer, int r, int g, int b, int a);
        virtual void onCleanup(void);
};

#endif // _WG_SCREEN_H_
