#include <iostream>
#include <SDL2/SDL.h>
#include "WG_button.h"

Button::Button(SDL_Renderer* renderer,SDL_Event* e, int posX, int posY, int height, int width)
{
    buttonRenderer = renderer;
    event = e;
    positionX = posX;
    positionY = posY;
    clientHeight = height;
    clientWidth = width;
    hasBackground = false;
    hasText = false;
    hasIcon = false;
    iconPath = "default";
    buttonText = "default";
    backgroundPath = "default";
    container = {positionX, positionY, clientWidth, clientHeight};
};

void Button::addBackground(string path)
{
    backgroundPath = path;
    hasBackground = true;
};

void Button::addBackground(string path, int imgWidth, int imgHeight)
{
    hasBackground = true;
};

void Button::addIcon(string path, string position, int width, int imgWidth, int imgHeight)
{
    iconPath = path;
    hasIcon = true;

    // calculate height from the imgWidth and imgHeight
};

void Button::addText(string text, string path,SDL_Color color, int size, string position)
{
    hasText = true;
    // todo : set the position according to RIGHT | CENTER | LEFT 
    textureText.Init( buttonRenderer, text, path, size, color, 0, 0);
};

void Button::render()
{
    // SDL_RenderCopy( buttonRenderer, buttonTexture, NULL, &container);
    // todo render a rectangle with no color for the button primarily

    if(hasBackground) textureBackground.Render();
    
    if(hasIcon) textureIcon.Render();
    
    if(hasText) textureText.Render();
};

int Button::verifyEvent(int mouseX, int mouseY)
{
    if (mouseX >= positionX && 
        mouseX <= clientWidth && 
        mouseY >= positionY &&
        mouseY <= clientHeight)
    {
        return 0;
    }

    return 1;
}

int Button::onClick(int mouseX, int mouseY, int rValue)
{
    if(verifyEvent(mouseX, mouseY) != 0) return 0; 

    return rValue;
}

int Button::onMouseOver(int mouseX, int mouseY, int rValue)
{
    if(verifyEvent(mouseX, mouseY) != 0) return 0; 

    return rValue;
}

int Button::onKeyPressed(int key, int rValue)
{
    if(event->key.keysym.sym != key) return 0;

    return rValue;
}

Button::~Button()
{
    textureText.~Text();
    textureIcon.~Image();
    textureBackground.~Image();
};