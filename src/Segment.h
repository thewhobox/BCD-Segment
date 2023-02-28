#include <Arduino.h>
#include "SendOnlySoftwareSerial.h"


class Segment 
{
    public:
        Segment();
        Segment(uint8_t digits);
        void setInputPins(uint8_t a[]);
        void setDigitPins(uint8_t d[]);
        void setDigitCount(uint8_t count);

        void setNumber(int number, bool showZero = true);
        void setDigits(int8_t d0, int8_t d1 = 15, int8_t d2 = 15, int8_t d3 = 15);
        void setDigit(int8_t number, uint8_t position);
        void setSerial(SendOnlySoftwareSerial *ser);

        void loop();
        
    private:
        uint8_t _digitsCount;
        int8_t _digits[4];
        
        int _currentDigit = 0;
        int _lastDigit = 0;
        uint8_t *_pinsInput;
        uint8_t *_pinsDigit;
        SendOnlySoftwareSerial *serial;
};