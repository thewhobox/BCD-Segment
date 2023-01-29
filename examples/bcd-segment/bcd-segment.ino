#include "Segment.h"

Segment seg(4); //Digit Count

void setup()
{
    //BCD Inputs A B C D
    seg.setInputPins(D1, D2, D3, D4); 
    //Pins for Common Anode/Cathode Switch
    seg.setDigitPins(D5, D6, D7, D8); 
}

void loop()
{
    //Needed for multiplexing
    seg.loop();
    
    //Output 0034
    seg.setNumber(34);

    //Output 34
    seg.setNumber(34);

    //Output 1234
    seg.setDigits(4, 3, 2, 1);

    //Ouput 3 56
    //Depends on BCD
    //negative numbers are handled like 16 - number
    seg.setDigits(6, 5, -1, 3);
}