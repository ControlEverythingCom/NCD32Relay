/* Includes ------------------------------------------------------------------*/
#include "NCD32Relay/NCD32Relay.h"

SYSTEM_MODE(AUTOMATIC);

NCD32Relay relayController;

/* This function is called once at start up ----------------------------------*/
void setup()
{
	Serial.begin(115200);
	relayController.setAddress(0, 0);
}

/* This function loops forever --------------------------------------------*/
void loop()
{
    //Turn all 32 relays on in sequence
    for(int i = 0; i < 33; i++){
        relayController.turnOnRelay(i);
        delay(20);
    }
    //Turn all 32 relays off in sequence
    for(int i = 32; i > 0; i--){
        relayController.turnOffRelay(i);
        delay(20);
    }
    //Turn on all relays in banks 1-4 in sequence
    for(int i = 0; i < 5; i++){
        relayController.turnOnAllRelays(i);
        delay(100);
    }
    //Turn off all relays in banks 1-4 in sequence
    for(int i = 4; i > 0; i--){
        relayController.turnOffAllRelays(i);
        delay(100);
    }
    //Turn all relays on and off twice.
    for(int i = 0; i < 3; i++){
        relayController.turnOnAllRelays();
        delay(100);
        relayController.turnOffAllRelays();
        delay(100);
    }
    //Toggle all relays(should turn on then off in sequnce)
    for(int i = 0; i < 33; i++){
        relayController.toggleRelay(i);
        delay(20);
        relayController.toggleRelay(i);
        delay(20);
    }
}
