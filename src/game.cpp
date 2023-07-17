#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>

#include "game.h"
#include "models.h"
#include "WG_filezilla.h"
#include "WG_filezilla.cpp"
#include "WG_audio.h"

#define WG_HEIGHT 640
#define WG_WIDTH 640

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::fstream;
using std::ios;
using std::to_string;

Game::Game()
{
    activePage = 0;
    assertPath = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
    dataPath = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\data\\";
    isRunning = true;
    window = NULL;
    renderer = NULL;
    surface = NULL;
    activeButtonID = 0;
    activePlayerID = 0;
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

    wordStore.setPath(dataPath + "words.dat");
    playerStore.setPath(dataPath + "players.dat");
    dataStore.setPath(dataPath + "data.dat");

    wordStore.read();
    playerStore.read();
    dataStore.read();

    gameSounds.addSoundEffect(assertPath + "click1.ogg");
    gameSounds.addSoundEffect(assertPath + "click2.ogg");

    pages.StartPage.onInit( renderer, &gameSounds, WG_WIDTH, WG_HEIGHT, &activePage);
    pages.HomePage.onInit( renderer, &gameSounds ,WG_WIDTH, WG_HEIGHT, &activePage);
    pages.HofPage.onInit( renderer, &gameSounds ,WG_WIDTH, WG_HEIGHT, &activePage);
    pages.PlayMenuPage.onInit( renderer, &gameSounds ,WG_WIDTH, WG_HEIGHT, &activePage, &activeButtonID, &activePlayerID);
    pages.HelpPage.onInit( renderer, &gameSounds ,WG_WIDTH, WG_HEIGHT, &activePage);
    pages.CreditsPage.onInit( renderer, &gameSounds ,WG_WIDTH, WG_HEIGHT, &activePage);
    pages.PlayerInitPage.onInit( renderer, &gameSounds ,WG_WIDTH, WG_HEIGHT, &activePage);
    pages.DeGamePage.onInit( renderer, &gameSounds ,WG_WIDTH, WG_HEIGHT, &activePage);

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
        onLoop();
        onRender();
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
        case 2:
            pages.PlayMenuPage.onEvent(events);
            break;
        case 3:
            pages.HofPage.onEvent(events);
            break;
        case 4:
            pages.HelpPage.onEvent(events);
            break;
        case 5:
            pages.CreditsPage.onEvent(events);
            break;
        case 6:
            isRunning = false;
            break;
        case 7:
            pages.PlayerInitPage.onEvent(events);
            break;
        case 8:
            pages.DeGamePage.onEvent(events);
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
        case 2:
            pages.PlayMenuPage.onRender();
            break;
        case 3:
            pages.HofPage.onRender();
            break;
        case 4:
            pages.HelpPage.onRender();
            break;
        case 5:
            pages.CreditsPage.onRender();
            break;
        case 7:
            pages.PlayerInitPage.onRender();
            break;
        case 8:
            pages.DeGamePage.onRender();
            break;
    }
    SDL_RenderPresent(renderer);

    return true;
};

void Game::onLoop(void)
{
    switch (activePage)
    {
        case 2:
            pages.PlayMenuPage.onLoop();
            break;
    }
};

void Game::onCleanup(void)
{
    pages.StartPage.onCleanup();
    pages.HomePage.onCleanup();
    pages.PlayMenuPage.onCleanup();
    pages.HofPage.onCleanup();
    pages.HelpPage.onCleanup();
    pages.CreditsPage.onCleanup();
    pages.PlayerInitPage.onCleanup();
    pages.DeGamePage.onCleanup();
    SDL_DestroyWindow(window);
    SDL_FreeSurface(surface);
    SDL_Quit();
};


