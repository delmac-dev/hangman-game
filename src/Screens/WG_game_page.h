#if !defined(_WG_GAME_PAGE_H_)
#define _WG_GAME_PAGE_H_

#include <SDL2/SDL.h>
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"
#include "WG_button.h"

class WG_Game_Page: public Screen
{
    private:
        int score;
        int attempts;
        int lives;
        int wordCount;
        int activePlayerId;
        bool hasPlayerIdSet;
        string level;
        string playerName;
        string hiddenWord;
        Image bgImage;
        Text title0;
        vector<Button> letterButtons;
        Button pauseButton;
        Button backButton;

    public:
        WG_Game_Page();
        void onInit(SDL_Renderer* renderer,Audio* sounds, int w, int h, int* ascreen);
        void onEvent(SDL_Event event);
        void onLoop(void);
        bool onRender(void);
        void onCleanup(void);
        void setActivePlayer(int a);


};

#endif // _WG_GAME_PAGE_H_