#if !defined(_WG_HOF_H_)
#define _WG_HOF_H_

#include <SDL2/SDL.h>
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"
#include "WG_button.h"
#include "WG_table.h"

class WG_HoF_Page: public Screen
{
    private:
        Image bgImage;
        Text title0;
        Button backButton;
        Button resetButton;
        Table players;

    public:
        void onInit(SDL_Renderer* renderer,Audio* sounds, int w, int h, int* ascreen);
        void onEvent(SDL_Event event);
        void onLoop(void);
        bool onRender(void);
        void onCleanup(void);
};

#endif // _WG_HOF_H_