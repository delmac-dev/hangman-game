#include <SDL2/SDL.h>
#include <iostream>

#include "WG_Play_page.h"

using std::cout;
using std::endl;
using std::string;


WG_Play_Page:: WG_Play_Page()
{
    dataModified = true;
    notActive = true;
    maxSaves = 4;
    assertsPath = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
}

/**
 * Initialise the home screen of the game 
 * 
 * @param renderer a pointer to the game renderer to render textures
 * @param sounds the game soun effects pointer from the game class
 * @param w the width of the game window
 * @param h the height of the game window
 * @param ascreen the activescreen variable pointer from the game class
 * @param gameD the game saved data
 * inother to be able to change screens;
*/
void WG_Play_Page::onInit(SDL_Renderer* renderer, Audio* sounds,int w, int h, int* ascreen,int* bID, int* pID)
{
    SDL_Color titleColor = {165, 42, 42, 255};
    SDL_Color white = {255, 255, 255, 255};
    screenRenderer = renderer;
    gameSounds = sounds;
    activeScreen = ascreen;
    routeButtonID = bID;
    activePlayerID = pID;
    refWidth = w;
    refHeight = h;
    // cout<<"from play menu "<<gameData->getData().size()<<endl;

    bgImage.Init( renderer, assertsPath + "gamebg5.png", w, 1024, 1024);
    bgImage.setPosition(0, 0);

    title0.Init( renderer, "start", assertsPath + "future.ttf", 64, titleColor);
    title0.setReference(0, 0, refWidth, refHeight);
    title0.setCenterX(70);
    title1.Init( renderer, "game", assertsPath + "future.ttf", 64, titleColor);
    title1.setReference(0, 0, refWidth, refHeight);
    title1.setCenterX(130);

    backButton.Init( renderer, 45, 190);
    backButton.setReference( 0, 0, refWidth, refHeight);
    backButton.setBottomRight(100, 40);
    backButton.addText("backs", assertsPath + "future.ttf", white, 16);
    backButton.addBackground(assertsPath + "red_button12.png", 190, 45);
};

void WG_Play_Page::createRouteButtons(int ypos, int gap)
{
    for( int i = 0; i < maxSaves; i++)
    {
        string text = "new game";
        int bID = -1;
        SDL_Color color = {255, 255, 255, 255};
        routeButtons.push_back(new Button());
        routeButtons.back()->Init( screenRenderer, 45, 190);
        routeButtons.back()->setReference(0, 0, refWidth, refHeight);
        routeButtons.back()->setCenterX(ypos + (gap * i) + (45 * i));
        routeButtons.back()->addBackground(assertsPath + "red_button12.png", 190, 45);
        // if(gameData && gameData->getData().size() != 0)
        // {
        //     for(auto j : gameData->getData())
        //     {
        //         if( j.buttonID == i)
        //         {
        //             text = j.playerName;
        //             bID = j.index;
        //         }
        //     }
        // }
        routeButtons.back()->addText(text, assertsPath + "future.ttf", color, 16);
        routeButtons.back()->setButtonID(bID);
        routeButtons.back()->upDateText("hghjgj");
    }
}

bool WG_Play_Page::onRender(void)
{
    bgImage.Render();
    title0.Render();
    title1.Render();
    for(auto i : routeButtons)
        i->Render();
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
            // for(int i = 0; i < routeButtons.size(); i++)
            // {
            //     if(routeButtons[i].onClick(x, y) == 0)
            //     {
            //         if(routeButtons[i].getButtonID() == -1) {
            //             *routeButtonID = i;
            //             changeScreen(7);
            //         }
            //         else{
            //             *activePlayerID = routeButtons[i].getButtonID();
            //             changeScreen(8);
            //         };
            //     }
            // }
            if(backButton.onClick(x, y) == 0) changeScreen(1);
        }
    }
};

void WG_Play_Page::onLoop(void)
{
    if(!notActive && !dataModified) return;
    createRouteButtons(250, 30);
    notActive = false;
    dataModified = false;
};

void WG_Play_Page::onCleanup(void)
{
    // todo : delete all pointers
    routeButtons.clear();
};


