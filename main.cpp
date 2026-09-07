#include <iostream>
#include <string>
#include <print>
#include <format>
#include <sstream>
# include "tinyexpr.h"

// Code for COSC 3010

int calculate_prefix(const std::string& input, int& position) {
    // Skip spaces between prefix-expression tokens.
    while (input[position] == ' ') {
        ++position;
    }

    // Read a complete positive number, including multi-digit numbers.
    if (std::isdigit(static_cast<unsigned char>(input[position]))) {
        int number = 0;
        while (std::isdigit(static_cast<unsigned char>(input[position]))) {
            number = number * 10 + input[position++] - '0';
        }
        return number;
    }

    // Read the operator and recursively evaluate both operands.
    char oper = input[position++];
    int num1 = calculate_prefix(input, position);
    int num2 = calculate_prefix(input, position);

    // Convert the parsed operands into an expression for tinyexpr.
    std::string expression = std::to_string(num1) + oper + std::to_string(num2);
    int error = 0;
    return static_cast<int>(te_interp(expression.c_str(), &error));
}

int calculate_prefix(const std::string& input) {
    // Start parsing at the first character of the expression.
    int position = 0;
    return calculate_prefix(input, position);
}

// stuff to read from stdin placeholder
int main() {
    std::string prefixInput;
    // taking in input from the user for a prefix 
    std::cout << "Enter in a prefix: ";
    std::getline(std::cin, prefixInput);
    int position = 0;
    std::cout << "Result: " << calculate_prefix(prefixInput, position);

    // Manual checks
    //====TEST 1====//
    int firstTestExpected = 5;
    std::string firstTestInput = "+ 2 3";

    // Printing results.
    int firstTestActual = calculate_prefix(firstTestInput);
    std::cout << "Test 1 - expected: " << firstTestExpected
              << ", actual: " << firstTestActual << '\n';
    //===TEST 2=======//
    int secondTestExpected = 14;
    std::string secondTestInput = "* 2 + 3 4";
    
    // Printing results.
    int secondTestActual = calculate_prefix(secondTestInput);
    std::cout << "Test 2 - expected: " << secondTestExpected
              << ", actual: " << secondTestActual << '\n';
    //====TEST 3===//
    int thirdTestExpected = 2000;
    std::string thirdTestInput = "* + 20 30 40";

    int thirdTestActual = calculate_prefix(thirdTestInput);
    std::cout << "Test 3 - expected: " << thirdTestExpected
              << ", actual: " << thirdTestActual << '\n';

    //====TEST 4====//
    int fourthTestExpected = -1;
    std::string fourthTestInput = "- 2 + 3 / 4 16";

    int fourthTestActual = calculate_prefix(fourthTestInput);
    std::cout << "Test 4 - expected: " << fourthTestExpected
              << ", actual: " << fourthTestActual << '\n';

    return 0;
}

int main();