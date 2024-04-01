#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <database_file>" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	exchange.loadBitcoinData();
	exchange.readDatabase(argv[1]);

	return 0;
}