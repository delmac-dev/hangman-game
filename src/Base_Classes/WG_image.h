#if !defined(WG_IMAGE_H)
#define WG_IMAGE_H

#include<iostream>
#include <SDL2/SDL.h>
#include "WG_Entity.h"

using std::string;

class Image: public Entity
{
    private:
        float aspectRatio;
        string imagePath;
        SDL_Surface* imageSurface;
        SDL_Texture* imageTexture;
        SDL_Renderer* imageRenderer;
        SDL_Rect container;

    public:
        Image();
        int Init(SDL_Renderer* renderer, string path, int posX, int posY, int width, int imgWidth, int imgHeight);
        int Render();
        ~Image();
};

#endif // WG_IMAGE_H
