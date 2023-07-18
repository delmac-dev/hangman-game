#if !defined(_MODEL_H_)
#define _MODEL_H_

#include <iostream>

typedef struct WG_Word
{
    char word[30];
    char level[20];
} WG_Word;

struct WG_Data
{
    int index;
    char playerName[20];
    int buttonID;
    int score;
    char level[20];
    int attempts;
    int wordCount;
    int lives;
    char choosenWords[30]; 
    char hiddenWord[30];
    char wrongWords[30];
    char correctWords[30];
};

struct WG_Players
{
    char playerName[30];
    int score;
    char level[30];
    int wordCount;
};

#endif // _MODEL_H_
