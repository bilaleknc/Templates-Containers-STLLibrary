#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <list>

class PmergeMe {
public:
	/**
	 * @brief Default constructor for PmergeMe.
	 */
	PmergeMe();

	/**
	 * @brief Copy constructor for PmergeMe.
	 * @param other The PmergeMe object to be copied.
	 */
	PmergeMe(const PmergeMe &other);

	/**
	 * @brief Destructor for PmergeMe.
	 */
	~PmergeMe();

	/**
	 * @brief Assignment operator for PmergeMe.
	 * @param other The PmergeMe object to be assigned.
	 * @return Reference to the assigned PmergeMe object.
	 */
	PmergeMe &operator=(const PmergeMe &other);

	/**
	 * @brief Sorts a vector using merge sort algorithm with insertion sort optimization.
	 * @param v The vector to be sorted.
	 * @param p The starting index of the range to be sorted.
	 * @param r The ending index of the range to be sorted.
	 * @param k The threshold value for switching to insertion sort.
	 */
	void mergeInsertionSortWithVector(std::vector<int> &v, int p, int r, int k);

	/**
	 * @brief Sorts a list using merge sort algorithm with insertion sort optimization.
	 * @param v The list to be sorted.
	 * @param p The starting index of the range to be sorted.
	 * @param r The ending index of the range to be sorted.
	 * @param k The threshold value for switching to insertion sort.
	 */
	void mergeInsertionSortWithList(std::list<int> &v, int p, int r, int k);

	/**
	 * @brief Reads data from a string and stores it in a vector.
	 * @param v The vector to store the data.
	 * @param argv The string containing the data.
	 */
	void readData(std::vector<int> &v, char **argv);

	/**
	 * @brief Reads data from a string and stores it in a list.
	 * @param v The list to store the data.
	 * @param argv The string containing the data.
	 */
	void readData(std::list<int> &v, char **argv);

	/**
	 * @brief Writes data from a vector to the console.
	 * @param v The vector containing the data.
	 */
	void writeData(const std::vector<int> &v) const;

	/**
	 * @brief Writes data from a list to the console.
	 * @param v The list containing the data.
	 */
	void writeData(const std::list<int> &v) const;
};

#endif // PMERGEME_HPP
