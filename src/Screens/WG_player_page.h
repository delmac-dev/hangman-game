#if !defined(_WG_PLAYER_H_)
#define _WG_PLAYER_H_

#include <SDL2/SDL.h>
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"
#include "WG_button.h"

class WG_Player_Page: public Screen
{
    private:
        Image bgImage;
        Text title0;
        Button startGameButton;
        Button backButton;
        Button quitButton;
    public:
        void onInit(SDL_Renderer* renderer,Audio* sounds, int w, int h, int* ascreen);
        void onEvent(SDL_Event event);
        void onLoop(void);
        bool onRender(void);
        void onCleanup(void);

};

#endif // _WG_PLAYER_H_
