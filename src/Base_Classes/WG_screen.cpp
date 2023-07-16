#include "WG_screen.h"
#include <SDL2/SDL.h>
#include "WG_audio.h"

Screen::Screen()
{
    screenRenderer = NULL;
}

void Screen::changeScreen(int i)
{
    *activeScreen = i;
}


