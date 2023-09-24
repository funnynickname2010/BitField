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

bool BitField::operator ==(BitField& obj2)
{
	bool result = 1;

	if (reserved_ints != obj2.reserved_ints || used_bits != obj2.used_bits)
	{
		result = 0;
	}
	else
	{
		for (int i = 0; i < reserved_ints; i++)
		{
			if (bitarray[i] != obj2.bitarray[i])
			{
				result = 0;
				break;
			}
		}
	}

	return result;
}

BitField BitField::operator =(BitField& obj2)
{
	if (this != &obj2)
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

	return *this;
}

BitField BitField::operator &(BitField& obj2)
{
	unsigned int result_bitfield_size;
	int smaller_bitfield_size;

	if (reserved_ints >= obj2.reserved_ints)
	{
		result_bitfield_size = reserved_ints;
		smaller_bitfield_size = obj2.reserved_ints;
	}
	else
	{
		result_bitfield_size = obj2.reserved_ints;
		smaller_bitfield_size = reserved_ints;
	}

	BitField result(result_bitfield_size);
	result.used_bits = result_bitfield_size;

	for (int i = 0; i < smaller_bitfield_size; i++)
	{
		result.bitarray[i] = (bitarray[i] & obj2.bitarray[i]);
	}

	return result;
}

BitField BitField::operator |(BitField& obj2)
{
	unsigned int result_bitfield_size;
	int smaller_bitfield_size;

	if (reserved_ints >= obj2.reserved_ints)
	{
		result_bitfield_size = reserved_ints;
		smaller_bitfield_size = obj2.reserved_ints;
	}
	else
	{
		result_bitfield_size = obj2.reserved_ints;
		smaller_bitfield_size = reserved_ints;
	}

	BitField result(result_bitfield_size);
	result.used_bits = result_bitfield_size;

	for (int i = 0; i < smaller_bitfield_size; i++)
	{
		result.bitarray[i] = (bitarray[i] | obj2.bitarray[i]);
	}

	if (smaller_bitfield_size == reserved_ints)
	{
		for (int i = 0; i < obj2.reserved_ints; i++)
		{
			result.bitarray[i] = obj2.bitarray[i];
		}
	}
	else if (smaller_bitfield_size == obj2.reserved_ints)
	{
		for (int i = 0; i < reserved_ints; i++)
		{
			result.bitarray[i] = bitarray[i];
		}
	}
	
	return result;
}