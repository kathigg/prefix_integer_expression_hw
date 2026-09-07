#include <iostream>
#include <cstring>

// Code for COSC 3010

// stuff to read from stdin placeholder
int main() {
    char input[] = "* 2 3";
}


int calculate_prefix(char* input){
    int operator = int(input[0]); 

    // is the next character an operator or a number?
    if input[1] == operator {
        calculate(input[1:-1])
        // ex. [ + 20 30 40 ]
    }
    elif input[1] == number {
        int num1 = input[1]
    }
    if input[2] == operator{ 
        ca;ci;ate(input[2:-1]) 
    }
    elif input[2] == number {
        num2 == input[2]
    }
    if num1 == number and num2 == number {
        return int(num1 + operator + num2) 
    }
} 
