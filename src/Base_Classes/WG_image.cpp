#include <SDL2/SDL.h>

#include "WG_image.h"

Image::Image()
{
    aspectRatio = 1.0;
    imagePath = "default";
    imageSurface = NULL;
    imageTexture = NULL;
    imageRenderer = NULL;
    container = {0 , 0 , 0, 0 };
}

int Image::Init(SDL_Renderer* renderer, string path, int posX, int posY, int width, int imgWidth, int imgHeight)
{
    imageRenderer = renderer;
    imagePath = path;
    positionX = posX;
    positionY = posY;
    clientWidth = width;
    aspectRatio = imgWidth / imgHeight;
    clientHeight = imgWidth / aspectRatio; // future : make it zero proof
    container = {positionX, positionY, clientWidth, clientHeight};
    
    //  todo: set imageSurface
    //  todo: set imageTexture

    SDL_FreeSurface(imageSurface);
}

int Image::Render()
{
    SDL_RenderCopy( imageRenderer, imageTexture, NULL, &container);
}

Image::~Image()
{
    SDL_DestroyTexture(imageTexture);
    free(imageRenderer);
}