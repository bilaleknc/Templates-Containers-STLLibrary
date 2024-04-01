#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

// Date class implementations
Date::Date() : day(0), month(0), year(0) {}

Date::Date(std::string date)
{
	std::istringstream ss_date(date);
	std::string day, month, year;
	std::getline(ss_date, year, '-');
	std::getline(ss_date, month, '-');
	std::getline(ss_date, day, '-');
	this->day = std::atoi(day.c_str());
	this->month = std::atoi(month.c_str());
	this->year = std::atoi(year.c_str());
}

Date::~Date() {}

bool Date::operator<(const Date &other) const
{
	if (year != other.year)
	{
		return year < other.year;
	}
	else if (month != other.month)
	{
		return month < other.month;
	}
	else
	{
		return day < other.day;
	}
}

int Date::operator-(const Date &other) const
{
	int days = 0;
	Date first;
	Date second;
	if (*this < other)
	{
		first = *this;
		second = other;
	}
	else
	{
		first = other;
		second = *this;
	}

	while (first < second)
	{
		first.day++;
		days++;
		if (first.day > days_in_month(month, year))
		{
			first.day = 1;
			first.month++;
			if (first.month > 12)
			{
				first.month = 1;
				first.year++;
			}
		}
	}
	return days;
}

int Date::is_leap_year(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Date::days_in_month(int month, int year)
{
	if (month == 2)
	{
		return is_leap_year(year) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	else
	{
		return 31;
	}
}

bool Date::is_valid(std::string date)
{
	std::istringstream ss_date(date);
	std::string day, month, year;
	std::getline(ss_date, year, '-');
	std::getline(ss_date, month, '-');
	std::getline(ss_date, day, '-');
	int d = std::atoi(day.c_str());
	int m = std::atoi(month.c_str());
	int y = std::atoi(year.c_str());
	return m >= 1 && m <= 12 && d >= 1 && d <= Date::days_in_month(m, y) && y >= 0;
}

// BitcoinExchange class implementations
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->bitcoinData = other.bitcoinData;
	return *this;
}

void BitcoinExchange::loadBitcoinData()
{
	std::ifstream file("data.csv");
	std::string line;

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		std::string value;
		std::getline(ss, date, ',');
		std::getline(ss, value, ',');
		std::istringstream ss_date(date);
		Date d(ss_date.str());
		bitcoinData.insert(std::make_pair(d, std::atof(value.c_str())));
	}
}

float BitcoinExchange::shortestSpan(Date date)
{
	std::map<Date, float>::iterator it;
	float target = bitcoinData.begin()->second;
	int span = date - bitcoinData.begin()->first;
	for (it = bitcoinData.begin(); it != bitcoinData.end(); it++)
	{
		if (it->first - date < span)
		{
			span = date - it->first;
			target = it->second;
		}
	}
	return target;
}

void BitcoinExchange::printValues(Date date, float coefficient)
{
	std::map<Date, float>::iterator it;

	if (coefficient < 0)
		std::cerr << "Error: not a positive number." << std::endl;
	else if (coefficient > 1000)
		std::cerr << "Error: too large a number." << std::endl;
	else if (!Date::is_valid(std::to_string(date.year) + "-" + std::to_string(date.month) + "-" + std::to_string(date.day)))
		std::cerr << "Error: bad input => " << date.year << "-" << date.month << "-" << date.day << std::endl;
	else
		std::cout << date.year << "-" << date.month << "-" << date.day << " => " << coefficient << " = " << coefficient * shortestSpan(date) << std::endl;
}

void BitcoinExchange::readDatabase(std::string file)
{
	std::ifstream inputFile(file);
	std::string line;
	float coefficient;
	while (std::getline(inputFile, line))
	{
		std::istringstream ss(line);
		if (line.find("date") != std::string::npos || (line.find("\n") && line.size() == 1))
			continue;
		std::string date;
		std::string value;
		std::getline(ss, date, '|');
		std::getline(ss, value, '|');
		std::istringstream ss_date(date);
		Date d(ss_date.str());
		coefficient = std::atof(value.c_str());
		printValues(d, coefficient);
	}
}
