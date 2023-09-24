#include "BitField.h"

unsigned int BitField::BitMask(unsigned int& task, unsigned int& location)
{
	unsigned int multiplier_int;
	multiplier_int = std::floor(location);

	switch (task)
	{
	case 1:

	}
}

unsigned int BitField::BitMask(unsigned int& task)
{
	switch (task)
	{
	case 4:

	}
}

BitField::BitField()
{
	bitarray = new unsigned int(1);
	used_bits = 0;
	reserved_ints = 1;

	for (int i = 0; i < reserved_ints; i++)
	{
		bitarray[i] = 0;
	}
}

BitField::BitField(unsigned int& n)
{
	bitarray = new unsigned int(n);
	used_bits = 0;
	reserved_ints = n;

	for (int i = 0; i < reserved_ints; i++)
	{
		bitarray[i] = 0;
	}
}

BitField::BitField(BitField& obj2)
{
	used_bits = obj2.used_bits;
	reserved_ints = obj2.reserved_ints;
	bitarray = new unsigned int(obj2.reserved_ints);

	for (int i = 0; i < reserved_ints; i++)
	{
		bitarray[i] = obj2.bitarray[i];
	}
}

BitField::~BitField()
{
	delete[] bitarray;
}

BitField BitField::operator =(BitField& obj2)
{
	if (reserved_ints != obj2.reserved_ints)
	{
		reserved_ints = obj2.reserved_ints;
		bitarray = new unsigned int(obj2.reserved_ints);
	}

	for (int i = 0; i < reserved_ints; i++)
	{
		bitarray[i] = obj2.bitarray[i];
	}

	used_bits = obj2.used_bits;
}