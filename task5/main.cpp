#include <iostream>
#include "funcs.h"

int main()
{
	int num1, num2;
	std::cout << "Num1: ";
	std::cin >> num1;
	std::cout << "Num2: ";
	std::cin >> num2;

	std::cout << "Result = " << simple::add(num1, num2) << "\n";
	std::cout << "Result (modified func) = " << modified::add(num1, num2) << "\n";

	return 0;
}