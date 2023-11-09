#pragma once
#include <iostream>
using namespace std;

class MediaPlayer
{
public:
	void pause() {
		cout << "paused" << endl;
	}
	void stopMultimedia() {
		cout << "Multimedia stopped" << endl;
	}
	void reproduce() {
		cout << "reproduced" << endl;
	}
};
