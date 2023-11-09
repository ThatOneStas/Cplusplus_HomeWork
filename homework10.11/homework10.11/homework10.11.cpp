
#include <iostream>
#include <vector>

// task 1 classes
#include "MediaPlayer.h"
#include "AudioPlayer.h"
#include "VideoPlayer.h"
// task 2 classes
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;

int main()
{
    VideoPlayer video;
    MediaPlayer media;
    AudioPlayer audio;

    Vehicle vehicle;
    Car car;
    Motorcycle bike;
    while (true) {
        cout << "Choose task 1 or 2:" << endl << "Use any key to stop." << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            // task 1
            while (true) {
                string change_volume;
                cout << "+ / -" << endl;
                cin >> change_volume;
                if (change_volume == "+") {
                    if (audio.getSound() == 10) {
                        cout << "The sound is 10 (max)." << endl;
                    }
                    else {
                        audio.regulate(change_volume);
                        cout << audio.getSound() << endl;
                    }
                }
                else if (change_volume == "-") {
                    if (audio.getSound() == 0) {
                        cout << "The sound is 0 (min)." << endl;
                    }
                    else {
                        audio.regulate(change_volume);
                        cout << audio.getSound() << endl;
                    }
                }
                else 
                {
                    break;
                }
            }
        }
        else if (choice == 2) {
            // task 2
            int chooce_vehicle;
            cout << "Choose vehicle:" << endl << "1.Vehicle; 2. Car; 3. Motorcycle." << endl;
            cin >> chooce_vehicle;
            if(chooce_vehicle==1)
                while (true) {
                    int choose_action;
                    cout << endl << "1. Start / 2. Stop" << endl << "Use any key to stop" << endl;
                    cin >> choose_action;
                    if (choose_action == 1) {
                       vehicle.startEngine();
                    }
                    else if (choose_action == 2) {
                        vehicle.stopEngine();
                    }
                    else 
                    {
                        break;
                    }
            }
            if (chooce_vehicle == 2)
                while (true) {
                    int choose_action;
                    cout << endl << "1. Start / 2. Stop" << endl << "Use any key to stop" << endl;
                    cin >> choose_action;
                    if (choose_action == 1) {
                        car.startEngine();
                    }
                    else if (choose_action == 2) {
                        car.stopEngine();
                    }
                    else 
                    {
                        break;
                    }
                }
            if (chooce_vehicle == 3){
                while (true) {
                    int choose_action;
                    cout << endl << "1. Start / 2. Stop / 3. Show points" << endl << "Use any key to stop" << endl;
                    cin >> choose_action;
                    if (choose_action == 1) {
                        bike.startEngine();
                    }
                    else if (choose_action == 2) {
                        bike.stopEngine();
                    }
                    else if (choose_action == 3) {
                        bike.getPoints();
                    }
                    else 
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
}
