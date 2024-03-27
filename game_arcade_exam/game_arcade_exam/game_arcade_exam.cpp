#include "casino.h"
//#include "guestClass.h"
//#include "additional.h"

#include "fortuneWheel.h"
#include "slots.h"
#include "guessTheNum.h"
#include "shop.h"


using namespace std;



int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Guest josh{ "Josh" };
    Casino No1;
    No1.startCasino();


    /*No1.addNewGuest();
    No1.getGuestsList();
    No1.delGuest();
    josh.convertCash();
    No1.updateGuest(josh);
    No1.getGuestsList();*/
    /*FortuneWheel fr;
    fr.gameInfo();
    fr.spinWheel(josh);*/
    /*Slots slots;
    slots.gameInfo();
    slots.spinSlots(josh);*/
    /*GuessTheNum guessnum;
    guessnum.gameInfo();
    guessnum.startGame(josh);
    No1.updateGuest(josh);
    No1.getGuestsList();
    cout << "Ee" << endl;*/
    /*Shop shop;
    shop.shopInfo();
    shop.buyX2(josh);
    josh.getGuestData();
    shop.buyX2(josh);
    shop.buyX4(josh);*/
}