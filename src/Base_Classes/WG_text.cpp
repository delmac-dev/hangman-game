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
    fontText = "default";
    fontPath = "default";
    fontSize = 0;
    font = NULL;
    fontColor = {0, 0, 0};
    fontSurface = NULL;
    fontTexture = NULL;
    fontRenderer = NULL;
    container = {0, 0, 0, 0};
}

int Text::Init(SDL_Renderer* renderer, string text, string path, int size, SDL_Color color, int posX, int posY)
{
    if(TTF_Init() < 0){ 
        cout<<TTF_GetError()<<endl;
        return 1;
    };
    fontText = text;
    fontSize = size;
    fontColor = color;
    fontPath = path;
    font = TTF_OpenFont(const_cast<char*>(fontPath.c_str()), fontSize);
    positionX = posX;
    positionY = posY;
    clientHeight = clientHeight = fontSize + 6;
    fontRenderer = renderer;
    clientWidth = TTF_FontAscent(font)  * text.length();
    container = { positionX, positionY, clientWidth, clientHeight};
    fontSurface = TTF_RenderText_Solid( font, const_cast<char*>(fontText.c_str()), fontColor);
    fontTexture = SDL_CreateTextureFromSurface( fontRenderer, fontSurface);
    SDL_FreeSurface( fontSurface);

    return 0;
};


int Text::Render()
{
    SDL_RenderCopy( fontRenderer, fontTexture, NULL, &container);
};

Text::~Text()
{
    SDL_DestroyTexture(fontTexture);
    TTF_CloseFont( font );
    TTF_Quit();
    free(fontRenderer);
}