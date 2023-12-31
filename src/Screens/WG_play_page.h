#if !defined(_WG_PLAY_PAGE_H_)
#define _WG_PLAY_PAGE_H_

#include "WG_screen.h"
#include <SDL2/SDL.h>
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"
#include "WG_button.h"
#include "models.h"
#include "WG_filezilla.h"

class WG_Play_Page: public Screen
{
    private:
        bool dataModified;
        bool isActive;
        bool isDeleteActivated;
        int maxSaves;
        int deleteState;
        int* routeButtonID;
        int* activePlayerID;
        int refHeight;
        int refWidth;
        string assertsPath;
        Image bgImage;
        Text title0;
        Text title1;
        vector<Button*> routeButtons;
        Filezilla<WG_Data>* gameData; 
        Button backButton;
        Button deleteButton;

        void createRouteButtons(int ypos, int gap);

    public:
        WG_Play_Page();
        void onInit(SDL_Renderer* renderer,Audio* sounds, Filezilla<WG_Data>* gameD,int w, int h, int* ascreen, int* bID, int*pID);
        void onEvent(SDL_Event event);
        void onLoop(void);
        bool onRender(void);
        void onCleanup(void);

};

#endif // _WG_PLAY_PAGE_H_
