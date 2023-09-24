#include "BitField.h"
#include <string>
#include <sstream>

const int BITFIELD_SIZE 2;

void CorrectInput(int left_index, int right_index);
void Interface();
void InputRow(BitField& obj);
void OutputRow(BitField& obj);

void main()
{
	int option;
	BitField field1(BITFIELD_SIZE);
	BitField field2(BITFIELD_SIZE);

	Interface();
	std::getline(std::cin, option);

	switch (option)
	{
	case 1:

		InputRow(field1);
		break;

	case 2:

		unsigned int ind, val;
		
		do
		{
			std::cout << "Input index: ";
			std::getline(std::cin, ind);
		} while (ind > field1.reserved_ints || ind < 0);

		do
		{
			std::cout << "Input value: ";
			std::getline(std::cin, val);
		} while (val != 0 && val != 1);

		if (val == 0)
		{
			field1.TurnOff(ind);
		}
		else if (val == 1)
		{
			field1.TurnOn(ind);
		}

		if (field1.used_bits <= ind)
		{
			field1.used_bits = ind + 1;
		}

	case 3:

		unsigned int ind, val;

		do
		{
			std::cout << "Input index: ";
			std::getline(std::cin, ind);
		} while (ind > field1.reserved_ints || ind < 0);

		std::cout << "Bit with an index " << ind << " equals to " << field1.CheckState(ind) << std::endl;
	}


}

void Interface()
{
	std::cout << "1. Input a bitfitfield as a row";
	std::cout << "2. Input a single bit of a bitfield\n";
	std::cout << "3. Check state of a bit\n";
	std::cout << "4. Test | operator\n";
	std::cout << "5. Test & operator\n";
}

void InputRow(BitField& obj)
{
	std::string input;
	std::getline(std::cin, input);

	for (int i = 0; i < input.size; i++)
	{
		if (input[i] == 1)
		{
			obj.TurnOn(i);
		}
		else if (input[i] != 0)
		{
			break;
		}
	}
}

void OutputRow(BitField& obj)
{
	std::string output;
	
	for (int i = 0; i < obj.used_bits; i++)
	{
		output[i] = (obj.CheckState(i));
	}

	std::cout << std::endl << output << std::endl;
}

