#include "utils.h"
#include <cassert>
#include <iostream>

int main()
{
	std::cout << MathX::absVal(-5) << std::endl;
	std::cout << MathX::power(2, 2) << std::endl;
	std::cout << MathX::min(-5, 5) << std::endl;

	int a = 0, b = 0;

	while (a < 50)
	{
		a = MathX::moveTowards(a, 51, 1);
		std::cout << a << std::endl;
	}

	while (b < 18)
	{
		b = MathX::moveTowards(b, 19, 3);
		std::cout << b << std::endl;
	}

	assert(MathX::absVal(-5) == 5);       // the abs value of -5 is 5
	assert(MathX::power(2, 2) == 4);      // 2 to the power of 2 is 4
	assert(MathX::min(-5, 5) == -5);   // the lesser of these two values is -5

	return 0;
}