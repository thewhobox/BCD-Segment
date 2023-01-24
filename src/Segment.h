#include <Arduino.h>


class Segment 
{
    private:
        uint8_t _pinA;
        uint8_t _pinB;
        uint8_t _pinC;
        uint8_t _pinD;
        uint8_t _digit0;
        uint8_t _digit1;
        uint8_t _digit2;
        uint8_t _digit3;

        uint8_t _digitsCount;
        int8_t _digits[4];
        
        int _currentDigit = 0;
        int _lastDigit = 0;

    public:
        Segment(int digits);
        void setInputPins(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
#ifndef NO_DIGIT_PINS
        void setDigitPins(uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
#endif

        void setNumber(int number, bool showZero = true);
        void setDigits(int8_t d0, int8_t d1 = 15, int8_t d2 = 15, int8_t d3 = 15);

        void loop();
};