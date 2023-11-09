#pragma once
#include <iostream>
#include "MediaPlayer.h"
using namespace std;

class VideoPlayer :
    public MediaPlayer
{
public:
    void skip() {
        cout << "skipped" << endl;
    }
};
