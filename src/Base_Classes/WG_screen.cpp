#include "WG_screen.h"
#include <SDL2/SDL.h>

void Screen::onInit(void)
{
    // todo : to initialise all textures of this screen
};

void Screen::onEvent(void)
{
    // todo : to pass event to each component on this screen
};


/**
 * Render out a color for each instance of a screen
 * 
 * @param renderer pass the renderer from the class its being called
 * @param r pass in the red value
 * @param g pass in the green value
 * @param b pass in the blue value
 * @param a pass in the alpha value
 * 
 * @return true for successful render and false for error occurred
*/
bool Screen::onRender(SDL_Renderer* renderer, int r, int g, int b, int a)
{
    // todo : to render all the textures on this screen
    // get renderer reference from game class
    // create some render test and receive color when called
    if(SDL_SetRenderDrawColor(renderer, r, g, b, a) != 0) return false;

    return true;
};

void Screen::onLoop(void)
{
    // todo : code that run on every loop eg. animation
};

