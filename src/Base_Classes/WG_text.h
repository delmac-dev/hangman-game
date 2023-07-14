#if !defined(WG_TEXT_H)
#define WG_TEXT_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "WG_Entity.h"

using std::string;

class Text: public Entity
{
    private:
        string fontText;
        string fontPath;
        int fontSize;
        TTF_Font* font;
        SDL_Color fontColor;
        SDL_Surface* fontSurface;
        SDL_Texture* fontTexture;
        SDL_Renderer* fontRenderer;
        SDL_Rect container;

    public:
        Text();
        int Init(SDL_Renderer* renderer ,string text,string path,int size,SDL_Color color,int posX,int posY);
        int Render();
        ~Text();
};

#endif // WG_TEXT_H
