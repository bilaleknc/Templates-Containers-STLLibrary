#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: [RPN expression]" << std::endl;
        return 1;
    }
    std::string expression(argv[1]);
    RPNCalculator::check_error(expression);
    std::cout << RPNCalculator::evaluate(expression) << std::endl;
    return 0;
}
