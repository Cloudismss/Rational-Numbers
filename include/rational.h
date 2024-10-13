// COPYRIGHT (C) 2024 Kollin Brown & Drew Corliss (ksb91/dmc191) All rights reserved.
//
// rational.h: Definition of rational class and its interace.

#ifndef RATIONAL_H
#define RATIONAL_H

#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <stdlib.h>

// Mathematical helper functions.
// NOTE: These are defined in rational.cpp.
int gcd(int, int);
int lcm(int, int);

// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
class Rational
{
  // TODO: Define the following:
  // 1. A default constructor - [Done]
  // 2. A constructor that takes an integer value - [Done]
  // 3. A constructor that takes a pair of values - [Done]
  // 4. Overloads of equality operators - [Done]
  // 5. Overloads of comparison operators - [Done]
  // 6. Overloads of arithmetic operators

private:
    int numerator;
    int denominator;

public:
    // Constructors
    Rational() : numerator(0), denominator(1);              // default - init to 0
    Rational(int num) : numerator(num), denominator(1);     // whole numbers
    Rational(int num, int den);                             // rational

    // Arithmetic function overloads
    Rational add(const Rational& rhsRational) const;
    Rational subtract(const Rational& rhsRational) const;
    Rational multiply(const Rational& rhsRational) const;
    Rational divide(const Rational& rhsRational) const;



    // Accessors
    // Returns the numerator
    int getNum() const {return numerator;}
    // Returns the denominator
    int getDen() const {return denominator;}

    // Helper function - reduce to decimal representation
    double decimal() const;

    // Equality Overloads
    bool operator==(const Rational &rhs) const;
    bool operator!=(const Rational &rhs) const;
    // Comparison Overloads
    bool operator<(const Rational &rhs) const;
    bool operator<=(const Rational &rhs) const;
    bool operator>(const Rational &rhs) const;
    bool operator>=(const Rational &rhs) const;
};

//Non-Member function operator overloads
Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);


// TODO: Implement support for constant literals in operator overloads

// These are provided for you.
// NOTE: They are defined in rational.cpp.
std::ostream& operator<<(std::ostream &os, Rational r);
std::istream& operator>>(std::istream &is, Rational &r);

#endif // RATIONAL_H