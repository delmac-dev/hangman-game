#include <SDL2/SDL.h>
#include <iostream>

#include "WG_Home_page.h"

using std::string;

void WG_Home_Page::onInit(SDL_Renderer* renderer, SDL_Event* events, int w, int h)
{
    string path = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
    SDL_Color titleColor = {165, 42, 42, 255};
    screenRenderer = renderer;
    screenEvents = events;

    bgImage.Init( renderer, path + "gamebg5.png", w, 1024, 1024);
    bgImage.setPosition(0, 0);
    title0.Init( renderer, "game", path + "future.ttf", 80, titleColor);
    title0.setReference(0, 0, w, h);
    title0.setCenterX(140);
    title1.Init( renderer, "menu", path + "future.ttf", 80, titleColor);
    title1.setReference(0, 0, w, h);
    title1.setCenterX(210);
    para1.Init( renderer, "some content goes here",  path + "future.ttf", 16, {165, 42, 89, 255});
    para1.setReference(0, 0, w, h);
    para1.setCenterX(350);
};

bool WG_Home_Page::onRender(void)
{
    bgImage.Render();
    title0.Render();
    title1.Render();
    para1.Render();
};

void WG_Home_Page::onEvent(void)
{};

void WG_Home_Page::onLoop(void)
{};

void WG_Home_Page::onCleanup(void)
{};
