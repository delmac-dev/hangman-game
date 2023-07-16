#if !defined(WG_START_PAGE_H)
#define WG_START_PAGE_H

#include <SDL2/SDL.h>
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"

class WG_Start_Page: public Screen
{
    private:
        Image bgImage;
        Text title0;
        Text title1;
        Text title2;
        Text para1;

    public:
        void onInit(SDL_Renderer* renderer,Audio* sounds, int w, int h, int* ascreen);
        void onEvent(SDL_Event event);
        void onLoop(void);
        bool onRender();
        void onCleanup(void);
};

#endif // WG_START_PAGE_H
