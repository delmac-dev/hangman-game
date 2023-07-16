#if !defined(WG_HOME_PAGE_H)
#define WG_HOME_PAGE_H

#include <SDL2/SDL.h>
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"
#include "WG_button.h"

class WG_Home_Page: public Screen
{
    private:
        Image bgImage;
        Text title0;
        Text title1;
        Button startGameButton;
        Button HofButton;
        Button helpButton;
        Button creditsButton;
        Button exitButton;

    public:
        void onInit(SDL_Renderer* renderer,Audio* sounds, int w, int h, int* ascreen);
        void onEvent(SDL_Event event);
        void onLoop(void);
        bool onRender(void);
        void onCleanup(void);
};

#endif // WG_HOME_PAGE_H
