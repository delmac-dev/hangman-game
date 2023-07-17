#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "WG_audio.h"

using std::cout;
using std::endl;

int Audio::Init()
{
    if(SDL_Init(SDL_INIT_AUDIO) < 0){
        cout<<" audio class from init " <<SDL_GetError()<<endl;
        return 1;
    }
    Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3);

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cout<<" audio class from init mix " << Mix_GetError;
        return 1;
    }

    return 0;
}

int Audio::addSoundEffect(string path)
{
    soundEffects.push_back(Mix_LoadMUS(SDL_const_cast(char*, path.c_str())));
    if(soundEffects.back() == NULL) return 1;

    return 0;
}

int Audio::playSound(int i, int loop)
{
    if(i > (soundEffects.size()-1)) return 1;
    if(Mix_PlayMusic(soundEffects[i], loop) != 0) return 1;
    return 0;
}

Audio::~Audio()
{
    for(auto i : soundEffects)
        Mix_FreeMusic(i);
    Mix_CloseAudio();
    Mix_Quit();
}

