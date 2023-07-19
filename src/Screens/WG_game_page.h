#if !defined(_WG_GAME_PAGE_H_)
#define _WG_GAME_PAGE_H_

#include <SDL2/SDL.h>
#include "WG_filezilla.h"
#include "models.h"
#include "WG_screen.h"
#include "WG_text.h"
#include "WG_image.h"
#include "WG_button.h"

class WG_Game_Page: public Screen
{
    private:
        bool dataModified;
        bool notActive;
        bool isClueChanged;
        bool isLevelChanged;
        bool isWordCountChanged;
        bool isAttemptsChanged;
        bool isLivesChanged;
        bool isScoreChanged;
        bool isHWordChanged;

        string gamdWord;
        vector<string> letters;

        int button_state;
        int score;
        int attempts;
        int lives;
        int wordCount;
        int clues;
        int* activePlayerID;
        int refHeight;
        int refWidth;
        string level;
        string playerName;
        string hiddenWord;
        string assertsPath;

        Filezilla<WG_Data>* gameData; 

        Image bgImage;
        Text playerNameText;
        Text livesText;
        Text attemptsText;
        Text cluesText;
        Text levelText;
        Text scoreText;
        Text wordText;
        vector<Button*> letterButtons;
        vector<Button*> hiddenButtons;
        Button pauseButton;
        Button backButton;

        void loadOnActive();
        void generateGameWord();
        void executeGame();
        void setKeyActive();
        void createKeyButtons(int tinr,int vypos, int cgap,int rgap, int bw, int bh);
        void createHiddenButton(int ypos ,int gap ,int bh, int bw);

    public:
        WG_Game_Page();
        void onInit(SDL_Renderer* renderer,Audio* sounds, Filezilla<WG_Data>* gameD, int w, int h, int* ascreen, int*pID);
        void onEvent(SDL_Event event);
        void onLoop(void);
        bool onRender(void);
        void onCleanup(void);


};

#endif // _WG_GAME_PAGE_H_