#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Represents a date with day, month, and year components.
 */
class Date
{
public:
	int day, month, year;

	/**
	 * @brief Default constructor for Date class.
	 */
	Date();

	/**
	 * @brief Constructor for Date class that takes a string representation of a date.
	 * @param date The string representation of the date in the format "dd/mm/yyyy".
	 */
	Date(std::string date);

	/**
	 * @brief Destructor for Date class.
	 */
	~Date();

	/**
	 * @brief Less than operator for comparing two Date objects.
	 * @param other The other Date object to compare with.
	 * @return True if this Date is less than the other Date, false otherwise.
	 */
	bool operator<(const Date &other) const;

	/**
	 * @brief Subtraction operator for calculating the difference in days between two Date objects.
	 * @param other The other Date object to subtract from this Date.
	 * @return The difference in days between this Date and the other Date.
	 */
	int operator-(const Date &other) const;

	/**
	 * @brief Checks if a given string represents a valid date.
	 * @param date The string representation of the date to check.
	 * @return True if the date is valid, false otherwise.
	 */
	static bool is_valid(std::string date);

	/**
	 * @brief Gets the number of days in a given month of a given year.
	 * @param month The month for which to get the number of days.
	 * @param year The year for which to get the number of days.
	 * @return The number of days in the specified month of the specified year.
	 */
	static int days_in_month(int month, int year);

	/**
	 * @brief Checks if a given year is a leap year.
	 * @param year The year to check.
	 * @return True if the year is a leap year, false otherwise.
	 */
	static int is_leap_year(int year);
};

/**
 * @brief Represents a Bitcoin exchange with functionality to load Bitcoin data, calculate the shortest span, print values, and read from a database.
 */
class BitcoinExchange
{
private:
	std::map<Date, float> bitcoinData;

public:
	/**
	 * @brief Default constructor for BitcoinExchange class.
	 */
	BitcoinExchange();

	/**
	 * @brief Copy constructor for BitcoinExchange class.
	 * @param other The other BitcoinExchange object to copy from.
	 */
	BitcoinExchange(const BitcoinExchange &other);

	/**
	 * @brief Destructor for BitcoinExchange class.
	 */
	~BitcoinExchange();

	/**
	 * @brief Assignment operator for BitcoinExchange class.
	 * @param other The other BitcoinExchange object to assign from.
	 * @return A reference to the assigned BitcoinExchange object.
	 */
	BitcoinExchange &operator=(const BitcoinExchange &other);
	
	/**
	 * @brief Loads Bitcoin data into the BitcoinExchange object.
	 */
	void loadBitcoinData();

	/**
	 * @brief Calculates the shortest span between a given date and the closest available date in the BitcoinExchange object.
	 * @param date The date to calculate the shortest span from.
	 * @return The shortest span between the given date and the closest available date.
	 */
	float shortestSpan(Date date);

	/**
	 * @brief Prints the values in the BitcoinExchange object for a given date, multiplied by a given factor.
	 * @param date The date for which to print the values.
	 * @param katsayi The factor to multiply the values by.
	 */
	void printValues(Date date, float katsayi);

	/**
	 * @brief Reads Bitcoin data from a database file and populates the BitcoinExchange object.
	 * @param file The path to the database file.
	 */
	void readDatabase(std::string file);
};

#endif // BITCOINEXCHANGE_HPP
