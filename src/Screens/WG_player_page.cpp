#include <SDL2/SDL.h>
#include <iostream>

#include "WG_player_page.h"

using std::cout;
using std::endl;
using std::string;

WG_Player_Page::WG_Player_Page()
{
    textUpdated = false;
    assertsPath = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
    letters = {"a","b","c","d","e","f","g","h","i","j","k","l","m",
                "n","o","p","q","r","s","t","u","v","w","x","y","z"};
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
void WG_Player_Page::onInit(SDL_Renderer* renderer, Audio* sounds,int w, int h, int* ascreen)
{
    SDL_Color titleColor = {165, 42, 42, 255};
    SDL_Color white = {255, 255, 255, 255};
    screenRenderer = renderer;
    gameSounds = sounds;
    activeScreen = ascreen;
    refHeight = h;
    refWidth = w;

    bgImage.Init( renderer, assertsPath + "gamebg5.png", w, 1024, 1024);
    bgImage.setPosition(0, 0);
    title0.Init( renderer, "new player", assertsPath + "future.ttf", 48, titleColor);
    title0.setReference(0, 0, w, h);
    title0.setCenterX(70);

    int bw = 190;
    int bh = 45;
    int bf = 16;

    inputField.Init( renderer, 49, 190);
    inputField.setReference( 0, 0, w, h);
    inputField.setCenterX(160);
    inputField.addText(" ", assertsPath + "future.ttf", {165, 42, 89, 255}, 20);
    inputField.addBackground(assertsPath + "textInput.png", 190, 49);

    createKeyButtons(7, 240, 15, 15, 49, 45);

    deleteButton.Init( renderer, 49, 45);
    deleteButton.setReference( 0, 0, w, h);
    deleteButton.setPosition(103, 420);
    deleteButton.addBackground(assertsPath + "blue_button12.png", 49, 45);

    proceedButton.Init( renderer, 49, 45);
    proceedButton.setReference( 0, 0, w, h);
    proceedButton.setPosition(487, 420);
    proceedButton.addBackground(assertsPath + "blue_button12.png", 49, 45);

    backButton.Init( renderer, bh, bw);
    backButton.setReference( 0, 0, w, h);
    backButton.setBottomRight(40, 40);
    backButton.addText("back", assertsPath + "future.ttf", white, bf);
    backButton.addBackground(assertsPath + "red_button12.png", 190, 45);

    quitButton.Init( renderer, bh, bw);
    quitButton.setReference( 0, 0, w, h);
    quitButton.setBottomLeft(40, 40);
    quitButton.addText("quit", assertsPath + "future.ttf", white, bf);
    quitButton.addBackground(assertsPath + "red_button12.png", 190, 45);
};

/**
 * display the keys on the screens
 * 
 * @param tinr the total number of buttons per row ie total in row tinr
 * @param vypos the virtual container y position
 * @param cgap the column gap between each button
 * @param rgap the row gap between each button
 * @param bw the width of the buttons
 * @param bh the height of the button 
 * 
*/
void WG_Player_Page::createKeyButtons(int tinr,int vypos, int cgap,int rgap, int bw, int bh)
{
    int virtualXPos, virtualYPos;
    int totalRows = ((letters.size() - (letters.size() % tinr)) /tinr) + 1;
    int totalCol = tinr;
    bool nextRow = true;
    int ycount = 1;
    int yitr = 0; // y iteration
    SDL_Color color = {255, 255, 255, 255};
    for (int i = 0; i < letters.size(); i++)
    {
        int xitr = i % tinr;
        if(xitr == 0) nextRow = true;
        if(nextRow)
        {
            totalCol = totalRows == ycount ? letters.size() - (tinr * (totalRows - 1)) : tinr;
            int virtualWidth = (bw * totalCol) + (cgap * (totalCol -1));
            virtualXPos = ((refWidth - 0) - virtualWidth) / 2;
            virtualYPos = vypos + (bh * yitr) + (cgap * yitr);
            ycount++;
            yitr++;
            nextRow = false;
        }
        keyButtons.push_back(new Button);
        keyButtons.back()->Init( screenRenderer, bh, bw);
        keyButtons.back()->setPosition(virtualXPos + (bw * xitr) + (cgap * xitr), virtualYPos);
        keyButtons.back()->addText(letters[i], assertsPath + "future.ttf", color, 20);
        keyButtons.back()->addBackground(assertsPath + "blue_button12.png", 49, 45);
        keyButtons.back()->setButtonID(i);
    }
}

bool WG_Player_Page::onRender(void)
{
    bgImage.Render();
    title0.Render();
    inputField.Render();
    for(auto i : keyButtons)
        i->Render();
    deleteButton.Render();
    proceedButton.Render();
    backButton.Render();
    quitButton.Render();
};

void WG_Player_Page::onEvent(SDL_Event event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(event.button.button = SDL_BUTTON_LEFT)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if(backButton.onClick(x, y) == 0) {
                changeScreen(2);
                textInput = "";
                textUpdated = true;
            }
            if(quitButton.onClick(x, y) == 0) 
            {
                changeScreen(1);
                textInput = "";
                textUpdated = true;
            };
            for(auto i : keyButtons)
            {
                if(i->onClick(x, y) == 0){
                    gameSounds->playSound(0, 0);
                    textInput += letters[i->getButtonID()];
                    textUpdated = true;
                };
            }
        }
    }
};

void WG_Player_Page::onLoop(void)
{
    if(textUpdated)
    {
        cout<<textInput<<endl;
        inputField.upDateText(textInput);
        textUpdated = false;
    }
};

void WG_Player_Page::onCleanup(void)
{};


