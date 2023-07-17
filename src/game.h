#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <SDL2/SDL.h>

#include "screens.h"
#include "models.h"
#include "WG_filezilla.h"
#include "WG_image.h"
#include "WG_audio.h"

using std::string;

class Game
{
    private:
        string assertPath;
        string dataPath;
        Filezilla<Model_Word> Word_Cluster;
        Filezilla<Model_Players> Player_Cluster;
        Filezilla<Model_Game_Data> GameData;

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