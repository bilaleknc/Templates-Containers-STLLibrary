#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

/**
 * @brief The RPNCalculator class represents a Reverse Polish Notation calculator.
 * 
 * This class provides functionality to evaluate mathematical expressions in Reverse Polish Notation.
 */
class RPNCalculator
{
public:
	/**
	 * @brief Default constructor for RPNCalculator.
	 */
	RPNCalculator();

	/**
	 * @brief Copy constructor for RPNCalculator.
	 * 
	 * @param other The RPNCalculator object to be copied.
	 */
	RPNCalculator(const RPNCalculator &other);

	/**
	 * @brief Destructor for RPNCalculator.
	 */
	~RPNCalculator();

	/**
	 * @brief Assignment operator for RPNCalculator.
	 * 
	 * @param other The RPNCalculator object to be assigned.
	 * @return Reference to the assigned RPNCalculator object.
	 */
	RPNCalculator &operator=(const RPNCalculator &other);

	/**
	 * @brief Checks if the given string contains any error.
	 * 
	 * @param s The string to be checked.
	 */
	static void check_error(const std::string &s);

	/**
	 * @brief Evaluates the given string expression in Reverse Polish Notation.
	 * 
	 * @param s The string expression to be evaluated.
	 * @return The result of the evaluation.
	 */
	static int evaluate(const std::string &s);
};

#endif // RPN_HPP