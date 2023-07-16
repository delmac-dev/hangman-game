#include <SDL2/SDL.h>
#include <iostream>

#include "WG_hof_page.h"

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
void WG_HoF_Page::onInit(SDL_Renderer* renderer, Audio* sounds,int w, int h, int* ascreen)
{
    string path = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
    SDL_Color titleColor = {165, 42, 42, 255};
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color blue = {95, 42, 165, 255};
    screenRenderer = renderer;
    gameSounds = sounds;
    activeScreen = ascreen;

    bgImage.Init( renderer, path + "gamebg5.png", w, 1024, 1024);
    bgImage.setPosition(0, 0);

    title0.Init( renderer, "hall of fame", path + "future.ttf", 32, titleColor);
    title0.setReference(0, 0, w, h);
    title0.setCenterX(30);

    players.Init( renderer, 120, 18, 14, -1, 0, 0, path + "future.ttf");
    players.setReference(0, 0, w, h);
    players.setColor(titleColor, blue);
    players.setCellHeight(35);
    players.addTableHead("pos", 30);
    players.addTableHead("player", 180);
    players.addTableHead("words", 120);
    players.addTableHead("score", 80);

    players.addTableRow({"#1", "Samuel", "200", "1320"});
    players.addTableRow({"#2", "faruk", "160", "1250"});
    players.addTableRow({"#3", "urusin", "150", "1450"});
    players.addTableRow({"#4", "quayed", "120", "1400"});
    players.addTableRow({"#5", "manuel", "113", "1340"});
    players.addTableRow({"#6", "dela", "109", "1330"});
    players.addTableRow({"#7", "eugeen", "99", "1200"});
    players.addTableRow({"#8", "victor", "87", "900"});
    players.addTableRow({"#9", "midiav", "32", "300"});
    players.addTableRow({"#10", "conclve", "10", "100"});

    int bw = 190;
    int bh = 45;
    int bf = 16;
    backButton.Init( renderer, bh, bw);
    backButton.setReference( 0, 0, w, h);
    backButton.setBottomRight(40, 40);
    backButton.addText("back", path + "future.ttf", white, bf);
    backButton.addBackground(path + "red_button12.png", 190, 45);

    resetButton.Init( renderer, bh, bw);
    resetButton.setReference( 0, 0, w, h);
    resetButton.setBottomLeft(40, 40);
    resetButton.addText("reset", path + "future.ttf", white, bf);
    resetButton.addBackground(path + "red_button12.png", 190, 45);
};

bool WG_HoF_Page::onRender(void)
{
    bgImage.Render();
    title0.Render();
    players.Render();
    backButton.Render();
    resetButton.Render();
};

void WG_HoF_Page::onEvent(SDL_Event event)
{
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            if(backButton.onClick(x, y) == 0) changeScreen(1);
            if(resetButton.onClick(x, y) == 0) cout<<"reset clicked"<<endl;  
        }
    }
};

void WG_HoF_Page::onLoop(void)
{};

void WG_HoF_Page::onCleanup(void)
{};


