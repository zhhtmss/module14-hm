#include <iostream>
#include "Fraction.h"

int greatestDivisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a < 0 ? -a : a;
}

Fraction::Fraction(int num, int denom) {
    numerator = num;
    denominator = (denom == 0) ? 1 : denom;
    reduce();
}

void Fraction::reduce() {
    int divisor = greatestDivisor(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

void Fraction::input() {
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;

    if (denominator == 0) {
        std::cout << "Error: Denominator cannot be zero. Setting to 1.\n";
        denominator = 1;
    }

    reduce();
}

void Fraction::print(){
    std::cout << numerator << "/" << denominator << std::endl;
}

Fraction Fraction::add(const Fraction& other){
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
}

Fraction Fraction::subtract(const Fraction& other){
    int num = numerator * other.denominator - other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
}

Fraction Fraction::multiply(const Fraction& other){
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::divide(const Fraction& other){
    if (other.numerator == 0) {
        std::cerr << "Error: Division by zero fraction.\n";
        return Fraction(0, 1);
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}
