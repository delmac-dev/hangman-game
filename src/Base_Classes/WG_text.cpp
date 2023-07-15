#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "WG_text.h"
#include "WG_Entity.h"

using std::cout;
using std::endl;
using std::string;

Text::Text()
{
    fontSize = 0;
    font = NULL;
    fontColor = {0, 0, 0};
    fontSurface = NULL;
    fontTexture = NULL;
    fontRenderer = NULL;
    container = {0, 0, 0, 0};
}

/**
 * Initialise any font for display on the screen
 * 
 * @param renderer the renderer handling the font display on the screen
 * @param text the text to render on the screen
 * @param path the path to the font style to render
 * @param size the size of the font to render
 * @param color the color of the font in rgba ie. {red (0 - 255), green (0 - 255), blue (0 - 255), alpha (0 - 255)}
 * 
 * @return 0 on success and 1 on error
*/
int Text::Init(SDL_Renderer* renderer, string text, string path, int size, SDL_Color color)
{
    if(TTF_Init() < 0){ 
        cout<<TTF_GetError()<<endl;
        return 1;
    };
    fontText = text;
    fontSize = size;
    fontColor = color;
    fontPath = path;
    fontRenderer = renderer;
    font = TTF_OpenFont(SDL_const_cast(char*, fontPath.c_str()), fontSize);
    if(font == NULL) {
        cout<< "FAULT CREATING FONT =>" << SDL_GetError()<<endl;
        return 1;
    }
    setClientH(fontSize + 10);
    setClientW(TTF_FontAscent(font)  * text.length());
    fontSurface = TTF_RenderText_Solid( font, SDL_const_cast(char*, fontText.c_str()), fontColor);
    if(fontSurface == NULL) {
        cout<< "FAULT CREATING SURFACE =>" << SDL_GetError()<<endl;
        return 1;
    
    }
    fontTexture = SDL_CreateTextureFromSurface( fontRenderer, fontSurface);
    if(fontSurface == NULL) {
        cout<< "FAULT CREATING TEXTURE =>" << SDL_GetError()<<endl;
        return 1;
    }
    SDL_FreeSurface( fontSurface);
    return 0;
};

int Text::Render()
{
    container = {getClientX(), getClientY(), getClientW(), getClientH()};
    if(SDL_RenderCopy( fontRenderer, fontTexture, NULL, &container) != 0) return 1;

    return 0;
};

Text::~Text()
{
    SDL_DestroyTexture(fontTexture);
    if (font) TTF_CloseFont( font );
    TTF_Quit();
    free(fontRenderer);
}