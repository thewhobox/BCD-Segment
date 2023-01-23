#include <Arduino.h>
#include "Segment.h"

Segment::Segment(int digits)
{
	_digitsCount = digits;
}

void Segment::setInputPins(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
	pinMode(a, OUTPUT);
	pinMode(b, OUTPUT);
	pinMode(c, OUTPUT);
	pinMode(d, OUTPUT);

	_pinA = a;
	_pinB = b;
	_pinC = c;
	_pinD = d;
}

void Segment::setDigitPins(uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
	pinMode(d0, OUTPUT);
	pinMode(d1, OUTPUT);
	pinMode(d2, OUTPUT);
	pinMode(d3, OUTPUT);

	_digit0 = d0;
	_digit1 = d1;
	_digit2 = d2;
	_digit3 = d3;
}

void Segment::setNumber(int number, bool showZero)
{
	if(number < 0)
		for(int i = 0; i < 4; i++)
			_digits[i] = -1;
	else {
		for(int i = 0; i < _digitsCount; i++)
		{
			double refe = number / pow(10,i);
			int digit = (int)refe;
			_digits[i] = digit % 10;
			if(_digits[i] == 0 && !showZero)
				_digits[i] = -1;
		}
	}
}

void Segment::setDigits(int8_t d0, int8_t d1, int8_t d2, int8_t d3)
{
	_digits[0] = d0;
	_digits[1] = d1;
	_digits[2] = d2;
	_digits[3] = d3;
}

void Segment::loop()
{
	if(_lastDigit + 5 < millis())
	{
		digitalWrite(_digit3, _currentDigit == 3);
		digitalWrite(_digit2, _currentDigit == 2);
		digitalWrite(_digit1, _currentDigit == 1);
		digitalWrite(_digit0, _currentDigit == 0);

		int8_t digit = _digits[_currentDigit];
		if(digit < 0)
		{
			digit = 16 - digit;
		}

		digitalWrite(_pinA, _digits[_currentDigit] & 0b0001);
		digitalWrite(_pinB, _digits[_currentDigit] & 0b0010);
		digitalWrite(_pinC, _digits[_currentDigit] & 0b0100);
		digitalWrite(_pinD, _digits[_currentDigit] & 0b1000);
		
		_currentDigit++;
		_currentDigit = _currentDigit % 4;

		if(digit == 15)
			return;

		_lastDigit = millis();
	}
}