#include <iostream>
#include <string>
#include "print.h"
#include "calculator.hpp"

int main() {
    std::string message = "Hello, World! This is a demo for C++17.";
    printMessage(message);

    int a = 10;
    int b = 5; 
    std::cout << "Addition: " << add(a, b) << std::endl;
    std::cout << "Subtraction: " << subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << multiply(a, b) << std::endl;
    std::cout << "Division: " << divide(a, b) << std::endl;

    return 0;
}