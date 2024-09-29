// COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
//
// rational.h: Definition of rational class and its interace.

#ifndef RATIONAL_H
#define RATIONAL_H

#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <stdlib.h>


// Mathematical helper functions.
//
// NOTE: These are defined in rational.cpp.
int gcd(int, int);
int lcm(int, int);


// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
class Rational
{
  // TODO: Define the following:
  // 1. A default constructor
  // 2. A constructor that takes an integer value
  // 3. A constructor that takes a pair of values

  public:
      // Returns the numerator.
      int num() const { /* TODO: Implement me. */ }

      // Returns the denominator
      int den() const { /* TODO: Implement me. */ }

};


// TODO: Implement support for
// 1. Comparing two rational numbers for equality:
//    - r1 == t2
//    - r1 != r2
// 2. Ordering rational numbers
//    - r1 < r2
//    - r1 > r2
//    - r1 <= r2
//    - r1 >= r2
// 3. The standard arithmetic operators
//    - r1 + r2
//    - r1 - r2
//    - r1 * r2
//    - r1 / r2

// These are provided for you.
//
// NOTE: They are defined in rational.cpp.
std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif
