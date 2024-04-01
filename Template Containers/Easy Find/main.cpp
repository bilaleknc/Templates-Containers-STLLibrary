#include "easyfind.hpp"
#include <array>

int main() {
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;
	std::array<int, 10> a;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
		a[i] = i;
	}

	try {
		std::cout << "Found: " << *easyfind(v, 11) << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Found: " << *easyfind(l, 5) << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Found: " << *easyfind(d, 5) << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Found: " << *easyfind(a, 5) << std::endl; 
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}


}