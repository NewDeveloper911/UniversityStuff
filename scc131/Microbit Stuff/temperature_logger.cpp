#include "MicroBit.h"
#include "MicroBitLog.h"

MicroBit uBit;

void onTempUpdate(MicroBitEvent e)
{
uBit.display.scroll(uBit.thermometer.getTemperature());
}

int main()
{
    //Synchronous method of reading temperature
    /*
        int readTemp;
        int ambientTemp = 20;
        uBit.init();

        //Calibrate the temperature readings
        readTemp = uBit.thermometer.getTemperature();
        uBit.thermometer.setCalibration(readTemp - ambientTemp);

        while(1) {
            readTemp = uBit.thermometer.getTemperature();
            uBit.display.scroll(readTemp);
            uBit.sleep(3000);
        }
    */

    uBit.init();
    uBit.log.setTimeStamp(TimeStampFormat::Seconds); //Allows us to plot values
    uBit.log.setVisibility(true);
    
    uBit.thermometer.setCalibration(uBit.thermometer.getTemperature() - 20);
    uBit.thermometer.setPeriod(3000);
    uBit.messageBus.listen(MICROBIT_ID_THERMOMETER, MICROBIT_THERMOMETER_EVT_UPDATE, onTempUpdate);

    //Doing the actual logging of temperatures
    uBit.log.beginRow();
    uBit.log.logData("temperature", uBit.thermometer.getTemperature());
    uBit.log.endRow();

    release_fiber();
}
