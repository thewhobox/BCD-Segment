#include "Segment.h"

Segment::Segment() 
{
	_digitsCount = 4;;
}

Segment::Segment(uint8_t digits)
{
	_digitsCount = digits;
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

void Segment::setDigitCount(uint8_t count)
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

void Segment::setDigit(int8_t number, uint8_t position)
{
	_digits[position] = number;
}

void Segment::setSerial(SendOnlySoftwareSerial *ser)
{
	serial = ser;
}

void Segment::loop()
{
	//if(_lastDigit + 5 < millis())
	//{
		for(int i = 0; i < _digitsCount; i++)
		{
			digitalWrite(_pinsDigit[i], i == _currentDigit);
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

		delay(5);
		//_lastDigit = millis();
	//} else {
	//	serial->print(_lastDigit);
	//	serial->print(" ");
	//	serial->println(millis());
	//}
}