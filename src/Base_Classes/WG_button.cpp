#include <iostream>
#include <SDL2/SDL.h>
#include "WG_button.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Button::Button()
{
    hasBackground = false;
    hasText = false;
    hasIcon = false;
    hasRefPoint = false;
    buttonRenderer = 0;
}

/**
 * Initialise an instance of a button with its
 * Renderer, Event, X psition, Y position
 * 
 * @param r the renderer for the button
 * @param e events from the window
 * @param h the height of the button
 * @param w the width of the button
 * 
 * @return 0 on success
 * 
*/
int Button::Init(SDL_Renderer* r, int h, int w)
{
    buttonRenderer = r;
    setClientH(h);
    setClientW(w);

    return 0;
};

void Button::addBackground(string path, int imgW, int imgH)
{
    hasBackground = true;
    textureBackground.Init( buttonRenderer, path, getClientW(), imgW, imgH);
    textureBackground.setReference(getClientX(), getClientY(), getClientW(), getClientH());
    textureBackground.setCenter();
};

void Button::addBackground(string path, int width,int imgW, int imgH)
{
    hasBackground = true;
    textureBackground.Init( buttonRenderer, path, width, imgW, imgH);
    textureBackground.setReference(getClientX(), getClientY(), getClientW(), getClientH());
    textureBackground.setCenter();
};

void Button::addIcon(string path, int width, int imgW, int imgH)
{
    hasIcon = true;
    textureIcon.Init( buttonRenderer, path, width, imgW, imgH);
    textureIcon.setReference(getClientX(), getClientY(), getClientW(), getClientH());
    textureIcon.setCenter();
};

int Button::addText(string text, string path,SDL_Color color, int size)
{
    hasText = true;
    textureText.Init( buttonRenderer, text, path, size, color);
    textureText.setReference(getClientX(), getClientY(), getClientW(), getClientH());
    textureText.setCenter();
    return 0;
};

int Button::Render(void)
{
    if(hasBackground) textureBackground.Render();

    if(hasIcon) textureIcon.Render();
    
    if(hasText) textureText.Render();

    return 0;
};

int Button::verifyEvent(int mouseX, int mouseY)
{
    if (mouseX >= getClientX() &&  
        mouseX <= (getClientW() + getClientX()) && 
        mouseY >= getClientY() && 
        mouseY <= (getClientH() + getClientY()))
    {
        return 0;
    }

    return 1;
}

/**
 * This function listens to any click event on the button
 * 
 * @param mouseX the x position of the event
 * @param mouseY the y position of the event
 * @param r specified return value you want to listen to
 * 
 * @return default return value is 0 DON'T LISTEN FOR IT
 * 
*/
int Button::onClick(int mouseX, int mouseY, int r)
{
    if(verifyEvent(mouseX, mouseY) != 0) return 0; 

    return r;
}

/**
 * This function listens to any mouseover event on the button
 * 
 * @param mouseX the x position of the event
 * @param mouseY the y position of the event
 * @param r specified return value you want to listen to
 * 
 * @return default return value is 0 DON'T LISTEN FOR IT
 * 
*/
int Button::onMouseOver(int mouseX, int mouseY, int rValue)
{
    if(verifyEvent(mouseX, mouseY) != 0) return 0; 

    return rValue;
}

Button::~Button()
{
    // textureText.~Text();
    // textureIcon.~Image();
    // textureBackground.~Image();
};