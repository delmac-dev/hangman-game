#include <iostream>
#include <SDL2/SDL.h>

#include "game.h"
#include "models.h"
#include "WG_filezilla.h"
#include "WG_filezilla.cpp"

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
    activePage = 1;
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


    pages.StartPage.onInit( renderer, &events, WG_WIDTH, WG_HEIGHT);
    pages.HomePage.onInit( renderer, &events, WG_WIDTH, WG_HEIGHT);


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
            pages.StartPage.onEvent();
            break;
    }
};

bool Game::onRender(void)
{
    // SDL_SetRenderDrawColor( renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    switch (activePage)
    {
        case 0:
            pages.StartPage.onRender();
            break;
        case 1:
            pages.HomePage.onRender();
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
    SDL_DestroyWindow(window);
    SDL_FreeSurface(surface);
    SDL_Quit();
};


