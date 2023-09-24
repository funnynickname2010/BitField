#pragma once
#include <iostream>
#include <math.h>

class BitField
{
	int unsigned* bitarray;
	int unsigned reserved_ints;
	int unsigned used_bits;

	unsigned int BitMask(unsigned int& task, unsigned int& location);
	unsigned int BitMask(unsigned int& task);
	int ElementIndex();

	void TurnOn(unsigned int& index);
	void TurnOff(unsigned int& index);

	BitField operator =(BitField& obj2);

	BitField(); //Make a constant
	BitField(unsigned int& n);
	BitField(BitField& obj2);
	~BitField();
};