#include <SDL2/SDL.h>
#include <iostream>

#include "WG_game_page.h"

using std::cout;
using std::endl;
using std::string;


WG_Game_Page::WG_Game_Page()
{
    activePlayerId = 0;
    hasPlayerIdSet = false;
    score = 0;
    attempts = 0;
    lives =0;
    wordCount = 0;
}

/**
 * Initialise the home screen of the game 
 * 
 * @param renderer a pointer to the game renderer to render textures
 * @param sounds the game soun effects pointer from the game class
 * @param w the width of the game window
 * @param h the height of the game window
 * @param ascreen the activescreen variable pointer from the game class
 * inother to be able to change screens;
*/
void WG_Game_Page::onInit(SDL_Renderer* renderer, Audio* sounds,int w, int h, int* ascreen)
{
    string path = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
    SDL_Color titleColor = {165, 42, 42, 255};
    SDL_Color white = {255, 255, 255, 255};
    screenRenderer = renderer;
    gameSounds = sounds;
    activeScreen = ascreen;

    bgImage.Init( renderer, path + "gamebg5.png", w, 1024, 1024);
    bgImage.setPosition(0, 0);
    title0.Init( renderer, "game", path + "future.ttf", 48, titleColor);
    title0.setReference(0, 0, w, h);
    title0.setCenterX(70);

    int bw = 190;
    int bh = 45;
    int bf = 16;
    pauseButton.Init( renderer, bh, bw);
    pauseButton.setReference( 0, 0, w, h);
    pauseButton.setBottomLeft(40, 40);
    pauseButton.addText("pause", path + "future.ttf", white, bf);
    pauseButton.addBackground(path + "red_button12.png", 190, 45);

    backButton.Init( renderer, bh, bw);
    backButton.setReference( 0, 0, w, h);
    backButton.setBottomRight(40, 40);
    backButton.addText("back", path + "future.ttf", white, bf);
    backButton.addBackground(path + "red_button12.png", 190, 45);
};

bool WG_Game_Page::onRender(void)
{
    bgImage.Render();
    title0.Render();
    pauseButton.Render();
    backButton.Render();
};

void WG_Game_Page::onEvent(SDL_Event event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(event.button.button = SDL_BUTTON_LEFT)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if(pauseButton.onClick(x, y) == 0) cout<<"paused"<<endl;
            if(backButton.onClick(x, y) == 0) changeScreen(1);
        }
    }
};

void WG_Game_Page::onLoop(void)
{};

void WG_Game_Page::onCleanup(void)
{};

void WG_Game_Page::setActivePlayer(int a)
{
    activePlayerId = a;
    hasPlayerIdSet = true;
}


