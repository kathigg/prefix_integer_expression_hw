#include <iostream>
#include <string>
#include <cassert>
#include <print>
#include <format>
#include <sstream>

// Code for COSC 3010



int calculate_prefix(char input[]){
    char oper = input[0]; // ex. "+", "-", "/", "*"

    // because we know we're only handling positive numbers,
    // it's safe to be able to set these two to -1 when not initalized 
    // to an actual num1 or num2 value
    int num1 = -1; 
    int num2 = -1;

    // is the next character an operator or a number?
    if (input[1] == ('+' | '-' | '/' | '*')) {
        calculate_prefix(&input[1]); //passing, C-style, as a pointer
        // ex. [ + 20 30 40 ]
    }
    else if (std::isdigit(input[1])) {
        num1 = input[1];
    }
    if (input[2] == ('+' | '-' | '/' | '*')){ 
        calculate_prefix(&input[2]);
    }
    else if (std::isdigit(input[2])) {
        num2 = input[2]; 
    }
    // are num1 and num2 both numbers? 
    // if (num1 != -1 and num2 != -1) { 
    return int(num1 + oper + num2);
    // }

} 

// stuff to read from stdin placeholder
int main() {
    char input[] = "";
    // taking in input from the user for a prefix 
    // std::cout << "Enter in a prefix: ";
    // std::cin >> input; 

    // manual checks
    //====TEST 1====//
    int expected = 5;
    char testarr[] = {'+', '2', '3'};

    // printing results 
    std::stringstream ss;
    ss << "expected: " << expected << " output:  " << (calculate_prefix(testarr));
    std::string s = ss.str();
    std::cout << s << '\n';
    //===TEST 2=======//

    //====TEST 3===//

    //====TEST 4====//

    return 1;
}

int main();