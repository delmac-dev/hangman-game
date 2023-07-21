#if !defined(_MODEL_H_)
#define _MODEL_H_

#include <iostream>

using std::string;

typedef struct WG_Word
{
    string word;
    string level;
} WG_Word;

struct WG_Data
{
    string playerName;
    int buttonID;
    int score;
    string level;
    int attempts;
    int wordCount;
    int lives;
    string hiddenWord;
    string choosenLetters;
    string wrongLetters;
    string correctLetters;
};

struct WG_Players
{
    string playerName;
    int score;
    string level;
    int wordCount;
};

#endif // _MODEL_H_
