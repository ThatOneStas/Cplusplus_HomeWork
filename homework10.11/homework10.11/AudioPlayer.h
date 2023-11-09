#pragma once
#include <iostream>
#include "MediaPlayer.h"
using namespace std;

class AudioPlayer :
    public MediaPlayer
{
private:
    int sound;
public:
    AudioPlayer() {
        sound = 0;
    }
    void regulate(string change_volume) {
        if (change_volume == "+") {
            sound += 2;
        }
        else if (change_volume == "-") {
            sound -= 2;
        }
    }

    int getSound() {
        return sound;
    }
};
