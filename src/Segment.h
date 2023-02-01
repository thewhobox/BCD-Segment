#include <Arduino.h>


class Segment 
{
    public:
        Segment(bool useBCD = false);
        Segment(uint8_t digits, bool useBCD = false);
        void setInputPins(uint8_t a[]);
        void setDigitPins(uint8_t d[]);
        void setDigitCount(uint8_t count);

        void setNumber(int number, bool showZero = true);
        void setDigits(int8_t d0, int8_t d1 = 15, int8_t d2 = 15, int8_t d3 = 15);
        void setDigit(int8_t number, uint8_t position);

        void loop();
        
    private:
        uint8_t _digitsCount;
        int8_t _digits[4];
        bool _useBCD = false;
        
        int _currentDigit = 0;
        int _lastDigit = 0;
        uint8_t *_pinsInput;
        uint8_t *_pinsDigit;
};