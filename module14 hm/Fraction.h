#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce();

public:
    Fraction(int num = 0, int denom = 1);

    void input();
    void print();

    Fraction add(const Fraction& other);
    Fraction subtract(const Fraction& other);
    Fraction multiply(const Fraction& other);
    Fraction divide(const Fraction& other);
};

#endif
