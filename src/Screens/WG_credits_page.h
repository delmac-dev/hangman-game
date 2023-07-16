#if !defined(WD_CREDITS_PAGE_H)
#define WD_CREDITS_PAGE_H

#include <SDL2/SDL.h>
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"
#include "WG_button.h"

class WG_Credits_Page: public Screen
{
    private:
        Image bgImage;
        Text title0;
        Button startGameButton;
        Button backButton;

    public:
        void onInit(SDL_Renderer* renderer,Audio* sounds, int w, int h, int* ascreen);
        void onEvent(SDL_Event event);
        void onLoop(void);
        bool onRender(void);
        void onCleanup(void);

};

#endif // WD_CREDITS_PAGE_H
