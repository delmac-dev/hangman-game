#if !defined(_MODEL_H_)
#define _MODEL_H_

#include <iostream>

using std::string;

struct Model_Word
{
    string word;
    string level;
};

struct Model_Game_Data
{
    string playerName;
    int buttonID; // the button in which the name should render
    bool pausedGame; // true or false depending on whether a game not finished
    int score;
    string level;
    int attempts;
    int wordCount;
    int gamesPlayed; // the number of games this player has played

    // paused game metadata
    string choosenWords; 
    string hiddenWord;
    string wrongWords;
    string correctWords;
};

struct Model_Settings
{
    int vfxVolume;
};

struct Model_Players
{
    string playerName;
    int score;
    string level;
    int wordCount;
};

#endif // _MODEL_H_
