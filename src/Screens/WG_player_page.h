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
        bool dataModified;
        bool notActive;
        bool textUpdated;
        int* routeButtonID;
        int* activePlayerID;
        int refHeight;
        int refWidth;
        string textInput;
        string assertsPath;
        Image bgImage;
        Text title0;
        vector<string> letters;
        Button inputField;
        Button deleteButton;
        Button proceedButton;
        Button backButton;
        Button quitButton;
        vector<Button*> keyButtons;
        void createKeyButtons(int tinr,int vypos, int cgap,int rgap, int bw, int bh);
    public:
        WG_Player_Page();
        void onInit(SDL_Renderer* renderer,Audio* sounds, int w, int h, int* ascreen);
        void onEvent(SDL_Event event);
        void onLoop(void);
        bool onRender(void);
        void onCleanup(void);

};

#endif // _WG_PLAYER_H_
