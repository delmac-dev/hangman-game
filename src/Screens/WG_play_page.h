#if !defined(_WG_PLAY_PAGE_H_)
#define _WG_PLAY_PAGE_H_

#include "WG_screen.h"
#include <SDL2/SDL.h>
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"
#include "WG_button.h"

class WG_Play_Page: public Screen
{
    private:
        Image bgImage;
        Text title0;
        Text title1;
        Button newGameButton1;
        Button newGameButton2;
        Button newGameButton3;
        Button newGameButton4;
        Button backButton;

        // fututre list of buttons rather

    public:
        void onInit(SDL_Renderer* renderer,Audio* sounds, int w, int h, int* ascreen);
        void onEvent(SDL_Event event);
        void onLoop(void);
        bool onRender(void);
        void onCleanup(void);

};

#endif // _WG_PLAY_PAGE_H_
