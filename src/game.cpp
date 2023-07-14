#include <iostream>
#include <SDL2/SDL.h>

#include "game.h"
#include "models.h"
#include "WG_filezilla.h"
#include "WG_filezilla.cpp"

Game::Game()
{
    score = 0;
    attempts = 0;
    lives =0;
    wordCount = 0;
    level = "";
    playerName = "";
    hiddenWord = "";
    windowHeight = 640;
    windowWidth = 640;
    activePage = 0;
    isRunning = true;
    loading = 0;
    loaded = false;
    window = NULL;
    renderer = NULL;
    surface = NULL;
};

bool Game::onInit(void)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) return false;
    
    window = SDL_CreateWindow("Hangman Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_ALLOW_HIGHDPI);
    if(window == NULL) return false;
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) return false;

    // todo : read all data
    // Word_Cluster.read();
    // Player_Cluster.read();
    // Setting_Cluster.read();
    // GameData_Cluster.read();

    // todo : initialise start page;
    pages.StartPage.onInit();

    return true;
};

int Game::onExecute(void)
{
    if(onInit() == false) {
        return 1;
    }

    SDL_Event Event;

    while (isRunning)
    {
        while (SDL_PollEvent(&Event))
        {
            onEvent(&Event);
        }
        if(onRender() == false) return 1;
        onLoop();
    }

    onCleanup();
    return 0;
};

void Game::onEvent(SDL_Event* event)
{
    static int tep = 0;
    if(event -> type == SDL_QUIT) isRunning = false;
    if(event -> type == SDL_KEYDOWN) tep ++;

    activePage = tep % 9;

    // todo : switch statement to handle events
    switch (activePage)
    {
        case 0:
            pages.StartPage.onEvent();
            break;
        case 1: // todo HOME SCREEN
            pages.HomePage.onEvent();
            break;
        case 2: // todo EXIT SCREEN
            pages.ExitPage.onEvent();
            break;
        case 3: // todo HOF SCREEN
            pages.HofPage.onEvent();
            break;
        case 4: // todo HELP SCREEN
            pages.HelpPage.onEvent();
            break;
        case 5: // todo CREDITS SCREEN
            pages.CreditsPage.onEvent();
            break;
        case 7: // todo PLAY INIT SCREEN
            pages.PlayMenuPage.onEvent();
            break;
        case 8: // todo PLAYER INIT SCREEN
            pages.PlayerInitPage.onEvent();
            break;
        case 6: // todo DE GAME SCREEN
            pages.DeGamePage.onEvent();
            break;
    }
};

bool Game::onRender(void)
{
    // todo A switch statement to render a screen
    switch (activePage)
    {
        case 0: // todo START SCREEN
            if(pages.StartPage.onRender(renderer, 255,140, 234, 255) != true) return false;
            break;
        case 1: // todo HOME SCREEN
            if(pages.HomePage.onRender(renderer, 0,0, 34, 255) != true) return false;
            break;
        case 2: // todo EXIT SCREEN
            if(pages.ExitPage.onRender(renderer, 20,140, 134, 255) != true) return false;
            break;
        case 3: // todo HOF SCREEN
            if(pages.HofPage.onRender(renderer, 255, 0, 24, 255) != true) return false;
            break;
        case 4: // todo HELP SCREEN
            if(pages.HelpPage.onRender(renderer, 25, 0, 234, 255) != true) return false;
            break;
        case 5: // todo CREDITS SCREEN
            if(pages.CreditsPage.onRender(renderer, 190,140, 0, 255) != true) return false;
            break;
        case 7: // todo PLAY INIT SCREEN
            if(pages.PlayMenuPage.onRender(renderer, 45,100, 204, 255) != true) return false;
            break;
        case 8: // todo PLAYER INIT SCREEN
            if(pages.PlayerInitPage.onRender(renderer, 250,100, 224, 255) != true) return false;
            break;
        case 6: // todo DE GAME SCREEN
            if(pages.DeGamePage.onRender(renderer, 10,50, 24, 255) != true) return false;
            break;
    }

    if(SDL_RenderClear(renderer) != 0) return false;
    SDL_RenderPresent(renderer);

    return true;
};

void Game::onLoop(void)
{
    // todo : each page handle their loop code
    switch (activePage)
    {
        case 0: // todo START SCREEN
            // a switch statement for loading that inits all other pages
            switch (loading)
            {
                case 0:
                    // todo: Initialise HOME SCREEN
                    break;
                case 1:
                    // todo: Initialise EXIT SCREEN
                    break;
                case 2:
                    // todo: Initialise HOF SCREEN
                    break;
                case 3:
                    // todo: Initialise HELP SCREEN
                    break;
                case 4:
                    // todo: Initialise CREDITS SCREEN
                    break;
                case 5:
                    // todo: Initialise PLAY INIT SCREEN
                    break;
                case 6:
                    // todo: Initialise PLAYER INIT SCREEN
                    break;
                case 7:
                    // todo: Initialise DE GAME SCREEN
                    break;
            }
            pages.StartPage.onLoop(); // increase the loading ++
            break;

        case 1: // todo HOME SCREEN
            pages.HomePage.onLoop();
            break;
        case 2: // todo EXIT SCREEN
            pages.ExitPage.onLoop();
            break;
        case 3: // todo HOF SCREEN
            pages.HofPage.onLoop();
            break;
        case 4: // todo HELP SCREEN
            pages.HelpPage.onLoop();
            break;
        case 5: // todo CREDITS SCREEN
            pages.CreditsPage.onLoop();
            break;
        case 7: // todo PLAY INIT SCREEN
            pages.PlayMenuPage.onLoop();
            break;
        case 8: // todo PLAYER INIT SCREEN
            pages.PlayerInitPage.onLoop();
            break;
        case 6: // todo DE GAME SCREEN
            pages.DeGamePage.onLoop();
            break;
    }
};

void Game::onCleanup(void)
{
    pages.StartPage.onCleanup();
    pages.HomePage.onCleanup();
    pages.ExitPage.onCleanup();
    pages.HofPage.onCleanup();
    pages.HelpPage.onCleanup();
    pages.CreditsPage.onCleanup();
    pages.PlayerInitPage.onCleanup();
    pages.PlayMenuPage.onCleanup();
    pages.DeGamePage.onCleanup();
    SDL_DestroyWindow(window);
    SDL_FreeSurface(surface);
    SDL_Quit();
};


