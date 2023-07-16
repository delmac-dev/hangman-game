#if !defined(WG_AUDIO_H)
#define WG_AUDIO_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <vector>

using std::string;
using std::vector;

class Audio
{
    private:
        vector<Mix_Music*> soundEffects;

    public:
        int Init();
        int addSoundEffect(string path);
        int playSound(int i, int loop);
        ~Audio();
};

#endif // WG_AUDIO_H
