#include <iostream>
#include "Fraction.h"

int main() {
    Fraction number1, number2;

    std::cout << "Enter first fraction:" << std::endl;
    number1.input();

    std::cout << "Enter second fraction:" << std::endl;
    number2.input();

    Fraction sum = number1.add(number2);
    Fraction diff = number1.subtract(number2);
    Fraction prod = number1.multiply(number2);
    Fraction quot = number1.divide(number2);

    std::cout << "\nSum: ";
    sum.print();

    std::cout << "Difference: ";
    diff.print();

    std::cout << "Product: ";
    prod.print();

    std::cout << "Quotient: ";
    quot.print();
}
