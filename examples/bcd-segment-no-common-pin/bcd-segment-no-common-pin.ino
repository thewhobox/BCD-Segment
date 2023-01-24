#include <Arduino.h>

//Just use the BCD Inputs
//Common Anode/Cathode have no switch
#define NO_DIGIT_PINS
#include "Segment.h"

Segment seg(1);

void setup()
{
    seg.setInputPins(D0, D1, D2, D3);
    //Output 2
    seg.setNumber(3);
}

void loop()
{
    //Needed for multiplexing
    seg.loop();
}