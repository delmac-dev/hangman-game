#include <SDL2/SDL.h>
#include <iostream>

#include "WG_Home_page.h"

using std::cout;
using std::endl;
using std::string;

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
void WG_Home_Page::onInit(SDL_Renderer* renderer, Audio* sounds,int w, int h, int* ascreen)
{
    string path = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
    SDL_Color titleColor = {165, 42, 42, 255};
    SDL_Color white = {255, 255, 255, 255};
    screenRenderer = renderer;
    gameSounds = sounds;
    activeScreen = ascreen;

    bgImage.Init( renderer, path + "gamebg5.png", w, 1024, 1024);
    bgImage.setPosition(0, 0);
    title0.Init( renderer, "game", path + "future.ttf", 64, titleColor);
    title0.setReference(0, 0, w, h);
    title0.setCenterX(70);
    title1.Init( renderer, "menu", path + "future.ttf", 64, titleColor);
    title1.setReference(0, 0, w, h);
    title1.setCenterX(130);

    int bw = 190;
    int bh = 45;
    int bf = 16;
    startGameButton.Init( renderer, bh, bw);
    startGameButton.setReference( 0, 0, w, h);
    startGameButton.setCenterX(240);
    startGameButton.addText("play game", path + "future.ttf", white, bf);
    startGameButton.addBackground(path + "red_button12.png", 190, 45);

    HofButton.Init( renderer, bh, bw);
    HofButton.setReference( 0, 0, w, h);
    HofButton.setCenterX(300);
    HofButton.addText("Hall of fame", path + "future.ttf", white, bf);
    HofButton.addBackground(path + "red_button12.png", 190, 45);

    helpButton.Init( renderer, bh, bw);
    helpButton.setReference( 0, 0, w, h);
    helpButton.setCenterX(360);
    helpButton.addText("help", path + "future.ttf", white, bf);
    helpButton.addBackground(path + "red_button12.png", 190, 45);

    creditsButton.Init( renderer, bh, bw);
    creditsButton.setReference( 0, 0, w, h);
    creditsButton.setCenterX(420);
    creditsButton.addText("credits", path + "future.ttf", white, bf);
    creditsButton.addBackground(path + "red_button12.png", 190, 45);

    exitButton.Init( renderer, bh, bw);
    exitButton.setReference( 0, 0, w, h);
    exitButton.setCenterX(480);
    exitButton.addText("exit game", path + "future.ttf", white, bf);
    exitButton.addBackground(path + "red_button12.png", 190, 45);
};

bool WG_Home_Page::onRender(void)
{
    bgImage.Render();
    title0.Render();
    title1.Render();
    startGameButton.Render();
    HofButton.Render();
    helpButton.Render();
    creditsButton.Render();
    exitButton.Render();
};

void WG_Home_Page::onEvent(SDL_Event event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(event.button.button = SDL_BUTTON_LEFT)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if(startGameButton.onClick(x, y) == 0) changeScreen(2);
            if(HofButton.onClick(x, y) == 0) changeScreen(3);
            if(helpButton.onClick(x, y) == 0) changeScreen(4);
            if(creditsButton.onClick(x, y) == 0) changeScreen(5);
            if(exitButton.onClick(x, y) == 0) changeScreen(6);
        }
    }
};

void WG_Home_Page::onLoop(void)
{};

void WG_Home_Page::onCleanup(void)
{};


