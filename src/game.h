#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "screens.h"
#include "models.h"
#include "WG_filezilla.h"
#include "WG_image.h"
#include "WG_audio.h"

using std::string;
using std::vector;


class Game
{
    private:
        string assertPath;
        string dataPath;
        Filezilla<WG_Word> wordStore;
        Filezilla<WG_Players> playerStore;
        Filezilla<WG_Data> dataStore;
        int windowHeight;
        int windowWidth;
        int activePage;
        int activeButtonID;
        int activePlayerID;
        Screens pages;
        bool isRunning;
        Image bgImage;
        SDL_Window* window;
        SDL_Surface* surface;
        SDL_Renderer* renderer;
        SDL_Event events;
        Audio gameSounds;
    
    public:
        Game(void);
        int onExecute(void);
        int onInit(void);
        void onEvent();
        bool onRender(void);
        void onLoop(void);
        void onCleanup(void);
};

#endif