#include "Segment.h"

Segment::Segment(bool useBCD) 
{
	_useBCD = useBCD;
}

Segment::Segment(uint digits, bool useBCD)
{
	_digitsCount = digits;
	_useBCD = useBCD;
}

void Segment::setInputPins(uint8_t *a)
{
	for(int i = 0; i < 4; i++)
	{
		pinMode(a[i], OUTPUT);
	}

	_pinsInput = a;
}

void Segment::setDigitPins(uint8_t *d)
{
	for(int i = 0; i < _digitsCount; i++)
		pinMode(d[i], OUTPUT);

	_pinsDigit = d;
}

void Segment::setDigitCount(uint count)
{
	_digitsCount = count;
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
			if(_digits[i] == 0 && !showZero && i != 0)
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

void Segment::setDigit(int8_t number, uint position)
{
	_digits[position] = number;
}

void Segment::loop()
{
	if(_lastDigit + 5 < millis())
	{
		if(_useBCD)
		{
			for(int i = 0; i < 2; i++)
			{
				digitalWrite(_pinsDigit[i], _currentDigit & (0b1 << i));
			}
		} else {
			for(int i = 0; i < _digitsCount; i++)
			{
				digitalWrite(_pinsDigit[i], i == _currentDigit);
			}
		}


		int8_t digit = _digits[_currentDigit];
		if(digit < 0)
		{
			digit = 16 - digit;
		}

		for(int i = 0; i < 4; i++)
		{
			digitalWrite(_pinsInput[i], _digits[_currentDigit] & (0b1 << i));
		}

		
		_currentDigit++;
		_currentDigit = _currentDigit % _digitsCount;

		if(digit == 15)
			return;

		_lastDigit = millis();
	}
}