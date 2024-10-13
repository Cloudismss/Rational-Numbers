// COPYRIGHT (C) 2024 Kollin Brown & Drew Corliss (ksb91/dmc191) All rights reserved.
// rational.h: Definition of rational class and its interace.

#include "rational.h"

#include <iostream>

// -------------------------------------------------------------------------- //
// Helper functions
// Compute the GCD (greatest common divider) of two integer values using Euclid's algorithm.
int gcd(int a, int b)
{
  a = abs(a);   // make them to be positive numbers
  b = abs(b);
  if(a==0 || b==0)
  { //if one number is 0, always return 1
    return 1;
  }
  while (b != 0) 
  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

// Compute the LCM (Least Common Multiple) of two integer values.
int lcm(int a, int b)
{
  a = abs(a); //make them positive
  b = abs(b);
  if(a == 0 || b == 0)
  {
    throw "Integers can not be zero in calculating Least Common Multiple";
  }
  return (abs(a) / gcd(a, b)) * abs(b);
}
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Rational Constructor
Rational::Rational(int num, int den)
{
    int divisor = gcd(num, den);    // computes greatest common divisor
    if (den < 0)
      numerator = -num / divisor;   // moves negative sign to numerator, if there is one
    else
      numerator = num / divisor;

    denominator = abs(den) / divisor;    // makes sure denominator is positive
}
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Rational Arithmetic Functions
Rational Rational::add(const Rational& rhsRational) const
{    //multiplies both fractions to have like-denominators and then adds them together. returns new object
  int num = (numerator * rhsRational.getDen()) + (rhsRational.getNum() * denominator);
  int den = denominator * rhsRational.getDen();

  return Rational(num, den);
}

Rational Rational::subtract(const Rational& rhsRational) const
{      //multiplies both fractions to have like-denominators and then subtracts them. returns new object
  int num = (numerator * rhsRational.getDen()) - (rhsRational.getNum() * denominator);
  int den = denominator * rhsRational.getDen();

  return Rational(num, den);
}

Rational Rational::multiply(const Rational& rhsRational) const
{     //multiplies numerators and denominators
  int num = numerator * rhsRational.getNum();
  int den = denominator * rhsRational.getDen();

  return Rational(num, den);
}

Rational Rational::divide(const Rational& rhsRational) const
{     //multiples first rational number by the reciprocal of the second rational number
  int num = numerator * rhsRational.getDen();
  int den = denominator * rhsRational.getNum();

  return Rational(num, den);
}
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Operator Definitions for Arithmetic Overloads
Rational operator+(const Rational& lhs, const Rational& rhs)
{
  return lhs.add(rhs);
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
  return lhs.subtract(rhs);
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
  return lhs.multiply(rhs);
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
  return lhs.divide(rhs);
}
// -------------------------------------------------------------------------- //


// Helper function to reduce rational to decimal
double Rational::decimal() const
{
  return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
}

// -------------------------------------------------------------------------- //
// Equality overloads
bool Rational::operator==(const Rational &rhs) const
{
  if (this->decimal() == rhs.decimal())
    return true;
  return false;
}
bool Rational::operator==(const int &&rhs) const
{
  if (this->decimal() == rhs)
    return true;
  return false;
}

bool Rational::operator!=(const Rational &rhs) const
{
  if (this->decimal() != rhs.decimal())
    return true;
  return false;
}
bool Rational::operator!=(const int &&rhs) const
{
  if (this->decimal() != rhs)
    return true;
  return false;
}
// -------------------------------------------------------------------------- //

// -------------------------------------------------------------------------- //
// Comparison overloads
bool Rational::operator<(const Rational &rhs) const
{
  if (this->decimal() < rhs.decimal())
    return true;
  return false;
}
bool Rational::operator<(const int &&rhs) const
{
  if (this->decimal() < rhs)
    return true;
  return false;
}

bool Rational::operator<=(const Rational &rhs) const
{
  if (this->decimal() <= rhs.decimal())
    return true;
  return false;
}
bool Rational::operator<=(const int &&rhs) const
{
  if (this->decimal() <= rhs)
    return true;
  return false;
}

bool Rational::operator>(const Rational &rhs) const
{
  if (this->decimal() > rhs.decimal())
    return true;
  return false;
}
bool Rational::operator>(const int &&rhs) const
{
  if (this->decimal() > rhs)
    return true;
  return false;
}

bool Rational::operator>=(const Rational &rhs) const
{
  if (this->decimal() >= rhs.decimal())
    return true;
  return false;
}
bool Rational::operator>=(const int &&rhs) const
{
  if (this->decimal() >= rhs)
    return true;
  return false;
}
// -------------------------------------------------------------------------- //

// Ostream overload
std::ostream& operator<<(std::ostream& os, Rational r)
{
  if (r.getDen() != 1)
    return os << r.getNum() << '/' << r.getDen();
  else
    return os << r.getNum();
}

// DO NOT CHANGE operators >> overloading function
std::istream& operator>>(std::istream& is, Rational& r)
{
  // Read the first integer, return on error.
  int p;
  is >> p;
  if (!is)
    return is;

  // Check for the divider. Assuming no spaces.
  if (is.peek() != '/') 
  {
    r = Rational(p);
    return is;
  }
  is.get();

  int q;
  is >> q;
  if (!is)
    return is;
  if (q == 0) 
  {
    is.setstate(std::ios::failbit);
    return is;
  }
  r = Rational(p, q);
  return is;
#if 0
  int p, q;
  char c;
  is >> p >> c >> q;
  if (!is)
    return is;
  // Require that the divider to be a '/'.
  if (c != '/') 
  {
    is.setstate(std::ios::failbit);
    return is;
  }
  // Make sure that we didn't read p/0.
  r = Rational(p, q);
  return is;
#endif
}
