#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <SDL2/SDL.h>

#include "screens.h"
#include "models.h"
#include "WG_filezilla.h"
#include "WG_image.h"

using std::string;

class Game
{
    private:
        int score;
        int attempts;
        int lives;
        int wordCount;
        string level;
        string playerName;
        string hiddenWord;

        Filezilla<Model_Word> Word_Cluster;
        Filezilla<Model_Players> Player_Cluster;
        Filezilla<Model_Settings> Setting_Cluster;
        Filezilla<Model_Game_Data> GameData_Cluster;

        int windowHeight;
        int windowWidth;
        int activePage;
        Screens pages;
        bool isRunning;
        int loading;
        bool loaded;
        Image bgImage;

        SDL_Window* window;
        SDL_Surface* surface;
        SDL_Renderer* renderer;
        SDL_Event events;
    
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