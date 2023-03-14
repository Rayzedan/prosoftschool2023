#include <iostream>
#include "first_task.h"

int main() 
{
	NewA test(1, 4);
	NewA test1(2, 1);
	NewB testStr("abc");
	NewB testStr1("cba");

	//Сравнение между NewA
	std::cout << (test <= test1) << (test >= test1) << (test == test1) << (test != test1) << '\n';

	//Сравнение с int
	std::cout << (test <= 1) << (test >= 1) << (test == 1) << (test != 2) << '\n';

	//Сравнение с float
	std::cout << (test <= 1.0f) << (test >= 1.0f) << (test == 1.0f) << (test != 2.0f) << '\n';

	//Сравнение с double
	std::cout << (test <= 1.0) << (test >= 1.0) << (test == 1.0) << (test != 2.0) << '\n';

	//Сравнение с char
	std::cout << (test <= '1') << (test >= '3') << (test == '2') << (test != '3') << '\n';

	//Сравнение между NewB
	std::cout << (testStr <= testStr1) << (testStr >= testStr1) << (testStr == testStr1) << (testStr != testStr1) << '\n';

	std::cout << "All tests passed successfully!" << '\n';
	return 0;
}