#include "iter.hpp"

template<typename T>
void print(T &i){
	std::cout << i << " ";
}


int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, print);
	std::cout << std::endl;

	std::string strArray[] = {"one", "two", "three", "four", "five"};
	iter(strArray, 5, print);
	std::cout << std::endl;

	return 0;
}