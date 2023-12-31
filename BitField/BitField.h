#pragma once
#include <iostream>
#include <math.h>

class BitField
{
	int unsigned* bitarray;
	int unsigned reserved_ints;
	int unsigned used_bits;

	unsigned int BitMask(unsigned int task, unsigned int location);

	void TurnOn(unsigned int index);
	void TurnOff(unsigned int index);
	bool CheckState(unsigned int index);

	BitField operator =(BitField& obj2);
	bool operator ==(BitField& obj2);

	BitField operator &(BitField& obj2);
	BitField operator |(BitField& obj2);

	BitField(); //Make a constant
	BitField(unsigned int& n);
	BitField(BitField& obj2);
	~BitField();
};