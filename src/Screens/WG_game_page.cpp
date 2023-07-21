#include <SDL2/SDL.h>
#include <iostream>

#include "WG_game_page.h"
#include "WG_filezilla.cpp"

using std::cout;
using std::endl;
using std::string;
using std::to_string;

WG_Game_Page::WG_Game_Page()
{
    isGameOver = false;
    isGamePaused = false;
    isActive = false;

    assertsPath = "C:\\Users\\Delmac\\Desktop\\Kill_Shot\\asserts\\";
    playerName = "dino";
    score = 0;
    attempts = 0;
    lives =0;
    wordCount = 0;
    clues = 0;
    refHeight = 0;
    refWidth = 0;
    hiddenWord = "person";
    isHWordChanged = true;
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
void WG_Game_Page::onInit(SDL_Renderer* renderer, Audio* sounds, Filezilla<WG_Data>* gameD, Filezilla<WG_Word>* wordD, Filezilla<WG_Players>* playerD, int w, int h, int* ascreen, int*pID)
{
    SDL_Color titleColor = {165, 42, 42, 255};
    SDL_Color white = {255, 255, 255, 255};
    screenRenderer = renderer;
    gameSounds = sounds;
    activeScreen = ascreen;
    gameData = gameD;
    wordData = wordD;
    playerData = playerD;
    activePlayerID = pID;
    refHeight = h;
    refWidth = w;

    bgImage.Init( renderer, assertsPath + "gamebg5.png", w, 1024, 1024);
    bgImage.setPosition(0, 0);

    livesText.Init( screenRenderer, "lives", assertsPath + "future.ttf", 14, {233, 156, 132, 255});
    livesText.setReference(0, 0, refWidth, refHeight);
    livesText.setTopLeft(30, 70);

    attemptsText.Init( screenRenderer, "attempts", assertsPath + "future.ttf", 14, {233, 156, 132, 255});
    attemptsText.setReference(0, 0, refWidth, refHeight);
    attemptsText.setCenterX(70);

    cluesText.Init( screenRenderer, "clues", assertsPath + "future.ttf", 14, {233, 156, 132, 255});
    cluesText.setReference(0, 0, refWidth, refHeight);
    cluesText.setTopRight(50, 70);

    levelText.Init( screenRenderer, "level", assertsPath + "future.ttf", 14, {233, 156, 132, 255});
    levelText.setReference(0, 0, refWidth, refHeight);
    levelText.setTopLeft(30, 140);

    scoreText.Init( screenRenderer, "score", assertsPath + "future.ttf", 14, {233, 156, 132, 255});
    scoreText.setReference(0, 0, refWidth, refHeight);
    scoreText.setCenterX(140);

    wordText.Init( screenRenderer, "words", assertsPath + "future.ttf", 14, {233, 156, 132, 255});
    wordText.setReference(0, 0, refWidth, refHeight);
    wordText.setTopRight(50, 140);

    createKeyButtons( 9, 240, 10, 10, 49, 45);

    pauseButton.Init( renderer, 45, 190);
    pauseButton.setReference( 0, 0, w, h);
    pauseButton.setBottomLeft(40, 40);
    pauseButton.addText("pause", assertsPath + "future.ttf", white, 16);
    pauseButton.addBackground(assertsPath + "red_button12.png", 190, 45);

    backButton.Init( renderer, 45, 190);
    backButton.setReference( 0, 0, w, h);
    backButton.setBottomRight(40, 40);
    backButton.addText("back", assertsPath + "future.ttf", white, 16);
    backButton.addBackground(assertsPath + "red_button12.png", 190, 45);
};

bool WG_Game_Page::onRender(void)
{
    bgImage.Render();
    playerNameText.Render();
    livesText.Render();
    livesValue.Render();
    attemptsText.Render();
    attemptsValue.Render();
    cluesText.Render();
    cluesValue.Render();
    levelText.Render();
    levelValue.Render();
    scoreText.Render();
    scoreValue.Render();
    wordText.Render();
    wordCountValue.Render();
    for(auto i: letterButtons)
        i->Render();
    for(auto i: hiddenButtons)
        i->Render();
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
            if(!isGameOver && !isGamePaused)
            {
                for(auto i : letterButtons)
                {
                    if(i->onClick(x, y) == 0)
                    {     
                        buttonState = 2;
                        i->switchBgIndex(buttonState);
                    }
                }
                if(pauseButton.onClick(x, y) == 0) cout<<"paused"<<endl;
                if(backButton.onClick(x, y) == 0) 
                {
                    isActive = false;
                    changeScreen(1);
                };
            }
            else if(isGameOver)
            {
                // handle clicks on replay
                // hangle clicks on back to mainmenu
                cout<<"game over"<<endl;
            }
            else if(isGamePaused)
            {
                //clicks on return to game
                //clicks on restart
                //clicks on back to mainmenu
                cout<<"game paused"<<endl;
            }
        }
    }
};

void WG_Game_Page::onLoop(void)
{
    loadOnActive();

    loadLives();
    loadAttempts();
    loadClues();
    loadLevel();
    loadScore();
    loadWordCount();

    if(isHWordChanged)
    {
        createHiddenButton(460, 5, 45, 49);
        isHWordChanged = false;
    }
};

void WG_Game_Page::onCleanup(void)
{
    playerNameText.cleanUp();
    livesText.cleanUp();
    attemptsText.cleanUp();
    cluesText.cleanUp();
    levelText.cleanUp();
    scoreText.cleanUp();
    wordText.cleanUp();
    letterButtons.clear();
    hiddenButtons.clear();
};

void WG_Game_Page::createKeyButtons(int tinr,int vypos, int cgap,int rgap, int bw, int bh)
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
        letterButtons.push_back(new Button);
        letterButtons.back()->Init( screenRenderer, bh, bw);
        letterButtons.back()->setPosition(virtualXPos + (bw * xitr) + (cgap * xitr), virtualYPos);
        letterButtons.back()->addText(letters[i], assertsPath + "future.ttf", color, 20);
        letterButtons.back()->addBackground(assertsPath + "blue_button12.png", 49, 45);
        letterButtons.back()->addBackground(assertsPath + "green_button12.png", 49, 45);
        letterButtons.back()->addBackground(assertsPath + "red_button09.png", 49, 45);
        letterButtons.back()->setButtonID(i);
    }
}

void WG_Game_Page::loadOnActive()
{
    if(isActive) return;

    WG_Data data = gameData->getData()[*activePlayerID];
    playerName = data.playerName;
    score = data.score;
    attempts = data.attempts;
    wordCount = data.wordCount;
    lives = data.lives;
    level = data.level;

    isClueChanged = true;
    isLevelChanged = true;
    isWordCountChanged = true;
    isAttemptsChanged = true;
    isLivesChanged = true;
    isScoreChanged = true;

    // // generate word if its a new player
    // if(data.hiddenWord.length() == 0){
    //     createGameWord();
    //     return;
    // }

    // //if is a coming back player
    // hiddenWord = data.hiddenWord;
    // choosenLetters = data.choosenLetters;
    // wrongLetters = data.wrongLetters;
    // correctLetters = data.correctLetters;

    // // generate the buttons for the hidden word
    // createHiddenButton(460, 5, 45, 49);

    // //for all the indexes in correct words unhide the text;
    // // since the correctWord contain the letters indexes
    // // of all the choosen words;
    // // so the eg. correctWord = "03214"
    // for(auto i : correctLetters)
    // {
    //     // must convert i to a string first
    //     hiddenButtons[i]->upDateText(letters[i]);

    //     // set buttonState to 1 which -> active but green
    //     buttonState = 1;

    //     // foreach of the butons switch the button bg to buttonState
    //     letterButtons[i]->switchBgIndex(buttonState);
    // }

    // for(auto i : wrongLetters)
    // {
    //     buttonState = 2;
    //     letterButtons[i]->switchBgIndex(buttonState);
    // }

    loadPlayerName();

    isActive = true;
}

void WG_Game_Page::createHiddenButton(int ypos ,int gap ,int bh, int bw)
{
    int virtualWidth = (bw * hiddenWord.length()) + (gap * (hiddenWord.length() - 1));
    int virtualXPos = ((refWidth - 0) - virtualWidth) / 2;
    for(int i = 0 ;i < hiddenWord.length(); i++)
    {
        hiddenButtons.push_back(new Button);
        hiddenButtons.back()->Init( screenRenderer, bh, bw);
        hiddenButtons.back()->setPosition(virtualXPos + (bw * i) + (gap * i), ypos);
        hiddenButtons.back()->addText(" ", assertsPath + "future.ttf", {233, 156, 132, 255}, 16);
        hiddenButtons.back()->addBackground(assertsPath + "grey_button13.png", bw, bh);
        hiddenButtons.back()->setButtonID(i);
    }
}

void WG_Game_Page::executeGame()
{
    
}

void WG_Game_Page::createGameWord()
{
    int offsetIndex = 0;
    if(level == "easy") offsetIndex = 0;
    if(level == "medium") offsetIndex = 100;
    if(level == "hard") offsetIndex = 200;

    // genrate random number between 0 and 99
    int index = 0 + (rand() % (int)(99 - 0 + 1));
    // add offset index to it
    index = index + offsetIndex;
    // get the word from the wordstore with the generated index
    // hiddenWord = wordData->getData()[index];
    isHWordChanged = true;
}

void WG_Game_Page::loadPlayerName()
{
    playerNameText.Init( screenRenderer, playerName, assertsPath + "future.ttf", 24, {233, 156, 132, 255});
    playerNameText.setReference(0, 0, refWidth, refHeight);
    playerNameText.setCenterX(15);
}

void WG_Game_Page::loadScore()
{
    if(!isScoreChanged) return;
    scoreValue.Init( screenRenderer, to_string(score), assertsPath + "future.ttf", 24, {233, 156, 132, 255});
    scoreValue.setReference(0, 0, refWidth, refHeight);
    scoreValue.setCenterX(160);
    isScoreChanged = false;
}

void WG_Game_Page::loadLives()
{
    if(!isLivesChanged) return;
    livesValue.Init( screenRenderer, to_string(lives), assertsPath + "future.ttf", 24, {233, 156, 132, 255});
    livesValue.setReference(0, 0, refWidth, refHeight);
    livesValue.setTopLeft(30, 90);
    isLivesChanged = false;
}

void WG_Game_Page::loadAttempts()
{
    if(!isAttemptsChanged) return;
    attemptsValue.Init( screenRenderer, to_string(attempts), assertsPath + "future.ttf", 24, {233, 156, 132, 255});
    attemptsValue.setReference(0, 0, refWidth, refHeight);
    attemptsValue.setCenterX(90);
    isAttemptsChanged = false;
}

void WG_Game_Page::loadClues()
{
    if(!isClueChanged) return;
    cluesValue.Init( screenRenderer, to_string(clues), assertsPath + "future.ttf", 24, {233, 156, 132, 255});
    cluesValue.setReference(0, 0, refWidth, refHeight);
    cluesValue.setTopRight(50, 90);
    isClueChanged = false;
}

void WG_Game_Page::loadLevel()
{
    if(!isLevelChanged) return;
    levelValue.Init( screenRenderer, level, assertsPath + "future.ttf", 24, {233, 156, 132, 255});
    levelValue.setReference(0, 0, refWidth, refHeight);
    levelValue.setTopLeft(30, 160);
    isLevelChanged = false;
}

void WG_Game_Page::loadWordCount()
{
    if(!isWordCountChanged) return;
    wordCountValue.Init( screenRenderer, to_string(wordCount), assertsPath + "future.ttf", 24, {233, 156, 132, 255});
    wordCountValue.setReference(0, 0, refWidth, refHeight);
    wordCountValue.setTopRight(50, 160);
    isWordCountChanged = false;
}

