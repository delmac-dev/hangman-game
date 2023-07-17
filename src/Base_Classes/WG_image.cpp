#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "WG_image.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Image::Image()
{
    aspectRatio = 1.0;
    imageSurface = NULL;
    imageTexture = NULL;
    imageRenderer = NULL;
}

int Image::Init(SDL_Renderer* renderer, string path, int width, int imgW, int imgH)
{
    if(IMG_Init(IMG_INIT_PNG) < 0){
        cout<< "FAULT INITING IMAGE =>" << SDL_GetError()<<endl;
        return 1;
    };
    imageRenderer = renderer;
    imagePath = path;
    aspectRatio = imgW / imgH;
    setClientW(width);
    
    setClientH(getClientW() / aspectRatio);
    
    imageSurface = IMG_Load(SDL_const_cast(char*, imagePath.c_str()));
    if(imageSurface == NULL) {
    cout<< " imgae class FAULT CREATING SURFACE =>" << SDL_GetError()<<endl;
    return 1;
    }

    imageTexture = SDL_CreateTextureFromSurface( imageRenderer, imageSurface);
    if(imageTexture == NULL) {
        cout<< " image class FAULT CREATING TEXTURE =>" << SDL_GetError()<<endl;
        return 1;
    }

    SDL_FreeSurface(imageSurface);

    return 0;
}

int Image::Render()
{
    
    container = {getClientX(), getClientY(), getClientW(), getClientH()};
    SDL_RenderCopy( imageRenderer, imageTexture, NULL, &container);

    return 0;
}

Image::~Image()
{
    SDL_DestroyTexture(imageTexture);
    IMG_Quit();
    free(imageRenderer);
}