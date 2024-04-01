#include "PmergeMe.hpp"
#include <sys/time.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <data>" << std::endl;
		return 1;
	}
	PmergeMe pmerge;

	std::vector<int> v;
	std::list<int> l;

	pmerge.readData(v, argv);
	pmerge.readData(l, argv);

	// Print the data
	std::cout << "-------------------------------------------------------------\n|";
	std::cout << " Before:   ";
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	timeval start, end;
	gettimeofday(&start, NULL);
	pmerge.mergeInsertionSortWithVector(v, 0, v.size() - 1, 2);
	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	double elapsed = seconds * 1e6 + microseconds; // convert to microseconds
	// pmerge.writeData(v);

	std::cout << "| After:    ";
	pmerge.writeData(v);
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "| Time to process a range of " << v.size() << " elements with std::vector : " << microseconds << " microseconds" << std::endl;

	gettimeofday(&start, NULL);
	pmerge.mergeInsertionSortWithList(l, 0, l.size() - 1, 2);
	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	elapsed = seconds * 1e6 + microseconds; // convert to microseconds
	std::cout << "| Time to process a range of " << l.size() << " elements with std::list : " << microseconds << " microseconds" << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;

	return 0;
}

