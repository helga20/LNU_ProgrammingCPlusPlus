#include "eStackPtn.h"
#include <iostream>

void StackDbl::print() const
{
	if (top == 0) std::cout << "Stack of doubles is empty.\n";
	else
	{
		std::cout << "  Stack of doubles:\ntop = " << top << "\nmem: ";
		for (int i = 0; i < top; ++i) std::cout << '\t' << mem[i];
		std::cout << '\n';
	}
}
