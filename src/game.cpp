#include <iostream>
#include <SDL2/SDL.h>

#include "game.h"
#include "models.h"
#include "WG_filezilla.h"
#include "WG_filezilla.cpp"
#include "WG_audio.h"

using std::cout;
using std::endl;
using std::cin;

#define WG_HEIGHT 640
#define WG_WIDTH 640

Game::Game()
{
    score = 0;
    attempts = 0;
    lives =0;
    wordCount = 0;
    activePage = 0;
    assertPath = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
    isRunning = true;
    loading = 0;
    loaded = false;
    window = NULL;
    renderer = NULL;
    surface = NULL;
};

int Game::onInit(void)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) return false;
    if(gameSounds.Init() != 0) return false;
    
    window = SDL_CreateWindow("Hangman Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WG_HEIGHT, WG_WIDTH, SDL_WINDOW_ALLOW_HIGHDPI);
    if(window == NULL) return false;
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        cout<<SDL_GetError()<<endl;
        return false;
    };

    Word_Cluster.read();
    Player_Cluster.read();
    Setting_Cluster.read();
    GameData_Cluster.read();

    gameSounds.addSoundEffect(assertPath + "click1.ogg");
    gameSounds.addSoundEffect(assertPath + "click2.ogg");

    pages.StartPage.onInit( renderer, &gameSounds, WG_WIDTH, WG_HEIGHT, &activePage);
    pages.HomePage.onInit( renderer, &gameSounds ,WG_WIDTH, WG_HEIGHT, &activePage);
    pages.HofPage.onInit( renderer, &gameSounds ,WG_WIDTH, WG_HEIGHT, &activePage);

    return 0;
};

int Game::onExecute(void)
{
    if(onInit() != 0) {
        return 1;
    }

    while (isRunning)
    {
        if(SDL_WaitEvent(&events))
        {
            onEvent();
        }
        if(onRender() == false) cout<<SDL_GetError()<<endl;
        onLoop();
    }

    onCleanup();
    return 0;
};

void Game::onEvent()
{
    if(events.type == SDL_QUIT) isRunning = false;

    switch (activePage)
    {
        case 0:
            pages.StartPage.onEvent(events);
            break;
        case 1:
            pages.HomePage.onEvent(events);
            break;
        case 3:
            pages.HofPage.onEvent(events);
            break;
    }
};

bool Game::onRender(void)
{
    SDL_RenderClear(renderer);
    switch (activePage)
    {
        case 0:
            pages.StartPage.onRender();
            break;
        case 1:
            pages.HomePage.onRender();
            break;
        case 3:
            pages.HofPage.onRender();
            break;
    }
    SDL_RenderPresent(renderer);

    return true;
};

void Game::onLoop(void)
{
    switch (activePage)
    {
        case 0:
            pages.StartPage.onLoop();
            break;
    }
};

void Game::onCleanup(void)
{
    pages.StartPage.onCleanup();
    pages.HomePage.onCleanup();
    pages.HofPage.onCleanup();
    SDL_DestroyWindow(window);
    SDL_FreeSurface(surface);
    SDL_Quit();
};


