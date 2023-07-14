#if !defined(WG_BUTTON_H)
#define WG_BUTTON_H

#include <iostream>
#include <SDL2/SDL.h>

#include "WG_Entity.h"
#include "WG_text.h"
#include "WG_image.h"

class Button : public Entity
{
    private:
        string buttonText;
        string iconPath;
        string backgroundPath;
        Text textureText;
        Image textureBackground;
        Image textureIcon;
        SDL_Renderer* buttonRenderer;
        SDL_Event* event;
        SDL_Rect container;
        bool hasBackground;
        bool hasText;
        bool hasIcon;

    public:
        Button(SDL_Renderer* renderer,SDL_Event* e, int posX, int posY, int height, int width);
        void addBackground(string path);
        void addBackground(string path, int imgWidth, int imgHeight);
        void addIcon(string path, string position, int width, int imgWidth, int imgHeight);
        void addText(string text, string path, SDL_Color color, int size, string position);
        void render();

        int verifyEvent(int mouseX, int mouseY);

        int onClick(int mouseX, int mouseY, int rValue);
        int onMouseOver(int mouseX, int mouseY, int rValue);
        int onKeyPressed(int key, int rValue);
        
        ~Button();
};

#endif // WG_BUTTON_H
