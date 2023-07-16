#if !defined(WG_HELP_PAGE_H)
#define WG_HELP_PAGE_H

#include <SDL2/SDL.h>
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"
#include "WG_button.h"

class WG_Help_Page: public Screen
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

#endif // WG_HELP_PAGE_H
