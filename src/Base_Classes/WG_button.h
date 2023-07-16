#if !defined(WG_BUTTON_H)
#define WG_BUTTON_H

#define HEIGHT 24

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "WG_Entity.h"
#include "WG_text.h"
#include "WG_image.h"

using std::vector;

class Button : public Entity
{
    private:
        string buttonText;
        string iconPath;
        string backgroundPath;
        Text textureText;
        vector<Image*> textureBg;
        vector<Image*> textureIcon;
        SDL_Renderer* buttonRenderer;
        SDL_Rect container;
        int activeBg;
        int activeIcon;
        bool hasBackground;
        bool hasText;
        bool hasIcon;
        bool hasRefPoint;

    public:
        Button();
        int Init(SDL_Renderer* r, int h, int w);
        void addBackground(string path, int imgW, int imgH);
        void addBackground(string path, int width,int imgW, int imgH);
        int switchBgIndex(int i);
        void addIcon(string path, int width, int imgW, int imgH);
        int switchIconIndex(int i);
        int addText(string text, string path, SDL_Color color, int size);
        int Render(void);

        int verifyEvent(int mouseX, int mouseY);

        int onClick(int mouseX, int mouseY);
        int onMouseOver(int mouseX, int mouseY);
        
        ~Button();
};

#endif // WG_BUTTON_H
