#include "MicroBit.h"

MicroBit uBit;

int main()
{
    MicroBitImage largeHeart("0,255,0,255,0\n255,255,255,255,255\n255,255,255,255,255\n0,255,255,255,0\n,0,0,255,0,0\n");
    MicroBitImage smallHeart("0,0,0,0,0\n0,255,0,255,0\n0,255,255,255,0\n0,0,255,0,0\n,0,0,0,0,0\n");

    uBit.init();

    while(1){
        uBit.display.print(largeHeart);
        uBit.sleep(500);
        uBit.display.print(smallHeart);
        uBit.sleep(500);

    }
}

