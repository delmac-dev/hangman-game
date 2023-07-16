#if !defined(WG_SCREEN_H)
#define WG_SCREEN_H

#include <SDL2/SDL.h>
#include "WG_audio.h"

class Screen
{
    protected:
        int* activeScreen;
        SDL_Renderer* screenRenderer;
        Audio* gameSounds;

    public:
        Screen();
        void changeScreen(int i);
};

#endif // WG_SCREEN_H
