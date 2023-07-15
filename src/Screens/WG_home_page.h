#if !defined(WG_HOME_PAGE_H)
#define WG_HOME_PAGE_H

#include <SDL2/SDL.h>
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"

class WG_Home_Page: public Screen
{
    private:
        int* activeScreen;
        Image bgImage;
        Text title0;
        Text title1;
        Text para1;

    public:
        void onInit(SDL_Renderer* renderer, SDL_Event* events, int w, int h);
        void onEvent(void);
        void onLoop(void);
        bool onRender();
        void onCleanup(void);
};

#endif // WG_HOME_PAGE_H
