#include <iostream>
#include <ctime>
#include "Array.hpp"

int main()
{
	int *a = new int();
	std::cout << *a << std::endl;

	std::cout << "Array n parameter" << std::endl;
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.getSize(); i++)
		arr[i] = i + 1;
	for (unsigned int i = 0; i < arr.getSize(); i++)
		std::cout << arr[i] << std::endl;

	std::cout << "Array copy constructor" << std::endl;
	Array<int> arr2(arr);
	for (unsigned int i = 0; i < arr2.getSize(); i++)
		std::cout << arr2[i] << std::endl;

	std::cout << "Array default constructor" << std::endl;
	Array<float> arr3;
	std::cout << arr3.getSize() << std::endl;

	std::cout << "Array assignment operator" << std::endl;
	Array<int> arr4;
	arr4 = arr;
	for (unsigned int i = 0; i < arr4.getSize(); i++)
		std::cout << arr4[i] << std::endl;

	std::cout << "Array out of bounds" << std::endl;
	try
	{
		Array<float> arr(5);
		for (unsigned int i = 0; i < arr.getSize(); i++)
			arr[i] = i + 1;

		for (unsigned int i = 0; i < arr.getSize(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		std::cout << arr[6] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}