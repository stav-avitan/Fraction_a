#include "sources/Fraction.hpp"
#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <stdbool.h>
#include <string>
using namespace std;
using namespace ariel;

TEST_CASE("test 1 - check two fractions with different opperators")
{
    Fraction a(3, 4);
    Fraction b(1, 2);

    CHECK(a < b);
    CHECK(a > b);
    CHECK(a >= b);
    CHECK(a <= b);
    CHECK(a == b);
    CHECK(a != b);
    CHECK((a++) == (b++));
}

TEST_CASE("test 2 - check two fractions with different opperators")
{
    Fraction a(6);
    Fraction b(6, 1);
    CHECK(a < b);
    CHECK(a > b);
    CHECK(a >= b);
    CHECK(a <= b);
    CHECK(a == b);
    CHECK(a != b);
    CHECK((a++) == (b++));
}

TEST_CASE("test 3 - represention")
{
    CHECK((Fraction(1,8))==0.125);
    CHECK((Fraction(1,4))==0.25);
    CHECK((Fraction(1,2))==0.5);
    CHECK((Fraction(253,1000))==0.253);
    CHECK((Fraction(3,4))==0.750);
    CHECK((Fraction(321,500))==0.642);
    CHECK((Fraction(421,500))==0.842);
    CHECK((Fraction(27,50))==0.54);
    CHECK((Fraction(1,10))==0.1);
    CHECK((Fraction(1,100))==0.01);
    CHECK((Fraction(1,1000))==0.001);
    CHECK((Fraction(2,8))==0.25);
}

TEST_CASE("test 4 -the denominator is zero") {
    CHECK_THROWS(Fraction(6, 0));
    CHECK_THROWS(Fraction(-6, 0));
    CHECK_THROWS(Fraction(0, 0));
}

TEST_CASE("Test 5: the numerator is zero")
{
    Fraction a (0, 6); 
    Fraction b (0, -6);

    CHECK(a == 0);
    CHECK(b == 0);
}

TEST_CASE("test 6: different operations on one fraction")
{
    Fraction a (1, 2);

     a /= 2;
    CHECK(a == Fraction(1, 2));

      a *= 2;
    CHECK(a == Fraction(1, 1));

    a += 1;
    CHECK(a == Fraction(3, 2));


     a -= 1;
    CHECK(a == Fraction(1, 2));
}


TEST_CASE("Test 7: different operations on two fractions") {
  Fraction a(2, 5);
  Fraction b(1, 4);

 a *= b;
  CHECK(a == Fraction(1, 10));

  a /= b;
  CHECK(a == Fraction(2, 5));

  a -= b;
  CHECK(a == Fraction(2, 5));

  a += b;
  CHECK(a == Fraction(13, 20));
  
  CHECK(++a == Fraction(7, 5));
  
  CHECK(--b == Fraction(-3, 4));
}
