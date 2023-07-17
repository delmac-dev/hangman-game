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
    buttonRenderer = 0;
    activeBg = 0;
    activeIcon = 0;
    buttonID = -1;
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
    textureBg.push_back(new Image);
    textureBg.back()->Init(buttonRenderer, path, getClientW(), imgW, imgH);
    textureBg.back()->setReference(getClientX(), getClientY(), getClientW(), getClientH());
    textureBg.back()->setCenter();
};

void Button::addBackground(string path, int width,int imgW, int imgH)
{
    hasBackground = true;
    textureBg.push_back(new Image);
    textureBg.back()->Init(buttonRenderer, path, width, imgW, imgH);
    textureBg.back()->setReference(getClientX(), getClientY(), getClientW(), getClientH());
    textureBg.back()->setCenter();
};

int Button::switchBgIndex(int i)
{
    if(i >= 0 && i <= (textureBg.size()-1)) activeBg = i;
    else return 1;

    return 0;
}

void Button::addIcon(string path, int width, int imgW, int imgH)
{
    hasIcon = true;
    textureIcon.push_back(new Image);
    textureIcon.back()->Init( buttonRenderer, path, width, imgW, imgH);
    textureIcon.back()->setReference(getClientX(), getClientY(), getClientW(), getClientH());
    textureIcon.back()->setCenter();
};

int Button::switchIconIndex(int i)
{
    if(i >= 0 && i <= (textureIcon.size()-1)) activeIcon = i;
    else return 1;

    return 0;
}

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
    if(hasBackground) textureBg[activeBg]->Render();

    if(hasIcon) textureIcon[activeIcon]->Render();
    
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
 * 
 * @return 0 if true and 1 if false
 * 
*/
int Button::onClick(int mouseX, int mouseY)
{
    if(verifyEvent(mouseX, mouseY) != 0) return 1; 

    return 0;
}

/**
 * This function listens to any mouseover event on the button
 * 
 * @param mouseX the x position of the event
 * @param mouseY the y position of the event
 * 
 * @return 0 if true and 1 if false
 * 
*/
int Button::onMouseOver(int mouseX, int mouseY)
{
    if(verifyEvent(mouseX, mouseY) != 0) return 1; 

    return 0;
}

void Button::setButtonID(int i)
{
    buttonID = i;
}

int Button::getButtonID()
{
    return buttonID;
}

Button::~Button()
{
    textureBg.clear();
    textureIcon.clear();
};