#include <iostream>
#include <string>

// Code for COSC 3010

// stuff to read from stdin placeholder
int main() {
    char input[] = "* 2 3";
}


int calculate_prefix(char input[]){
    char oper = input[0]; // ex. "+", "-", "/", "*"

    // is the next character an operator or a number?
    if (input[1] == '+' | '-' | '/' | '*') {
        calculate_prefix(input[1:-1])
        // ex. [ + 20 30 40 ]
    }
    elif input[1] == number {
        int num1 = input[1]
    }
    if input[2] == oper{ 
        ca;ci;ate(input[2:-1]) 
    }
    elif input[2] == number {
        num2 == input[2]
    }
    if num1 == number and num2 == number {
        return int(num1 + oper + num2) 
    }
} 
