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
    int index;
    string playerName;
    int buttonID;
    int score;
    string level;
    int attempts;
    int wordCount;
    int gamesPlayed;

    // paused game metadata
    string choosenWords; 
    string hiddenWord;
    string wrongWords;
    string correctWords;
};

struct Model_Players
{
    string playerName;
    int score;
    string level;
    int wordCount;
};

#endif // _MODEL_H_
