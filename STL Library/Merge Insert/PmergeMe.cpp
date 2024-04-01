#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
    return *this;
}

void PmergeMe::mergeInsertionSortWithVector(std::vector<int>& v, int p, int r, int k) {
    if (r - p + 1 <= k) {
        std::sort(v.begin() + p, v.begin() + r + 1);
    } else {
        int q = (p + r) / 2;
		mergeInsertionSortWithVector(v, p, q, k);
		mergeInsertionSortWithVector(v, q + 1, r, k);
		std::inplace_merge(v.begin() + p, v.begin() + q + 1, v.begin() + r + 1);
    }
}

void PmergeMe::mergeInsertionSortWithList(std::list<int> &l, int p, int r, int k)
{
	if (r - p + 1 <= k) {
		l.sort();
	}
	else {
		int q = (p + r) / 2;
		std::list<int> left(l.begin(), std::next(l.begin(), q - p + 1));
		std::list<int> right(std::next(l.begin(), q - p + 1), l.end());
		mergeInsertionSortWithList(left, p, q, k);
		mergeInsertionSortWithList(right, q + 1, r, k);
		l.clear();
		l.merge(left);
		l.merge(right);
	}
}

void PmergeMe::readData(std::vector<int>& v, char** argv) {
    while (*argv) {
        std::istringstream iss(*argv);
        int data;
        while (iss >> data) {
            v.push_back(data);
        }
        ++argv;
    }
}

void PmergeMe::writeData(const std::vector<int>& v) const {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
	std::cout << std::endl;
}

void PmergeMe::readData(std::list<int>& l, char** argv) {
	while (*argv) {
		std::string str = *argv;
		std::istringstream iss(str);
		int data;
		while (iss >> data) {
			l.push_back(data);
		}
		++argv;
	}
}

void PmergeMe::writeData(const std::list<int>& l) const {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}