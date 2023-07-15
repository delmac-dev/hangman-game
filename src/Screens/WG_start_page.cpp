#include <SDL2/SDL.h>
#include <iostream>

#include "WG_start_page.h"

using std::string;

void WG_Start_Page::onInit(SDL_Renderer* renderer, SDL_Event* events, int w, int h)
{
    string path = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
    SDL_Color titleColor = {165, 42, 42, 255};
    screenRenderer = renderer;
    screenEvents = events;

    bgImage.Init( renderer, path + "gamebg3.png", w, 1024, 1024);
    bgImage.setPosition(0, 0);
    title0.Init( renderer, "Hangman", path + "future.ttf", 80, titleColor);
    title0.setReference(0, 0, w, h);
    title0.setCenterX(100);
    title1.Init( renderer, "game",  path + "future.ttf", 64, titleColor);
    title1.setReference(0, 0, w, h);
    title1.setCenterX(200);
    title2.Init( renderer, "project",  path + "future.ttf", 20, {42, 151, 165, 255});
    title2.setReference(0, 0, w, h);
    title2.setCenterX(280);
    para1.Init( renderer, "starting...",  path + "future.ttf", 16, {165, 116, 42, 255});
    para1.setReference(0, 0, w, h);
    para1.setCenterX(350);
};

bool WG_Start_Page::onRender(void)
{
    bgImage.Render();
    title0.Render();
    title1.Render();
    title2.Render();
    para1.Render();
};

void WG_Start_Page::onEvent(void)
{};

void WG_Start_Page::onLoop(void)
{};

void WG_Start_Page::onCleanup(void)
{};
