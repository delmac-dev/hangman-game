#include <SDL2/SDL.h>
#include <iostream>

#include "WG_Play_page.h"

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
void WG_Play_Page::onInit(SDL_Renderer* renderer, Audio* sounds,int w, int h, int* ascreen)
{
    string path = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
    SDL_Color titleColor = {165, 42, 42, 255};
    SDL_Color white = {255, 255, 255, 255};
    screenRenderer = renderer;
    gameSounds = sounds;
    activeScreen = ascreen;

    bgImage.Init( renderer, path + "gamebg5.png", w, 1024, 1024);
    bgImage.setPosition(0, 0);

    title0.Init( renderer, "start", path + "future.ttf", 64, titleColor);
    title0.setReference(0, 0, w, h);
    title0.setCenterX(70);
    title1.Init( renderer, "game", path + "future.ttf", 64, titleColor);
    title1.setReference(0, 0, w, h);
    title1.setCenterX(130);

    int bw = 190;
    int bh = 45;
    int bf = 16;
    newGameButton1.Init( renderer, bh, bw);
    newGameButton1.setReference( 0, 0, w, h);
    newGameButton1.setCenterX(240);
    newGameButton1.addText("ericson", path + "future.ttf", white, bf);
    newGameButton1.addBackground(path + "red_button12.png", 190, 45);

    newGameButton2.Init( renderer, bh, bw);
    newGameButton2.setReference( 0, 0, w, h);
    newGameButton2.setCenterX(300);
    newGameButton2.addText("new game", path + "future.ttf", white, bf);
    newGameButton2.addBackground(path + "red_button12.png", 190, 45);

    newGameButton3.Init( renderer, bh, bw);
    newGameButton3.setReference( 0, 0, w, h);
    newGameButton3.setCenterX(360);
    newGameButton3.addText("new game", path + "future.ttf", white, bf);
    newGameButton3.addBackground(path + "red_button12.png", 190, 45);

    newGameButton4.Init( renderer, bh, bw);
    newGameButton4.setReference( 0, 0, w, h);
    newGameButton4.setCenterX(420);
    newGameButton4.addText("new game", path + "future.ttf", white, bf);
    newGameButton4.addBackground(path + "red_button12.png", 190, 45);

    backButton.Init( renderer, bh, bw);
    backButton.setReference( 0, 0, w, h);
    backButton.setBottomRight(40, 40);
    backButton.addText("back", path + "future.ttf", white, bf);
    backButton.addBackground(path + "red_button12.png", 190, 45);
};

bool WG_Play_Page::onRender(void)
{
    bgImage.Render();
    title0.Render();
    title1.Render();
    newGameButton1.Render();
    newGameButton2.Render();
    newGameButton3.Render();
    newGameButton4.Render();
    backButton.Render();
};

void WG_Play_Page::onEvent(SDL_Event event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(event.button.button = SDL_BUTTON_LEFT)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if(newGameButton1.onClick(x, y) == 0) changeScreen(8);
            if(newGameButton2.onClick(x, y) == 0) changeScreen(7);
            if(newGameButton3.onClick(x, y) == 0) changeScreen(7);
            if(newGameButton4.onClick(x, y) == 0) changeScreen(7);
            if(backButton.onClick(x, y) == 0) changeScreen(1);
        }
    }
};

void WG_Play_Page::onLoop(void)
{};

void WG_Play_Page::onCleanup(void)
{};


