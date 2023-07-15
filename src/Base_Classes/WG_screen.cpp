#include "WG_screen.h"
#include <SDL2/SDL.h>

Screen::Screen()
{
    screenRenderer = NULL;
    screenEvents = NULL;
}

void Screen::onInit(SDL_Renderer* renderer, SDL_Event* events)
{
    // todo : to initialise all textures of this screen
    screenRenderer = renderer;
    screenEvents = events;
};

void Screen::onEvent(void)
{
    // todo : to pass event to each component on this screen
};


/**
 * Render out a color for each instance of a screen
 * 
 * @param r pass in the red value
 * @param g pass in the green value
 * @param b pass in the blue value
 * @param a pass in the alpha value
 * 
 * @return true for successful render and false for error occurred
*/
bool Screen::onRender(int r, int g, int b, int a)
{
    // todo : to render all the textures on this screen
    // get renderer reference from game class
    // create some render test and receive color when called
    if(SDL_SetRenderDrawColor(screenRenderer, r, g, b, a) != 0) return false;

    return true;
};

void Screen::onLoop(void)
{
    // todo : code that run on every loop eg. animation
};

void Screen::onCleanup(void)
{
    // todo : code that run on every loop eg. animation
};

