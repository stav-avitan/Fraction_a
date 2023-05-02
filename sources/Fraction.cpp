#include "Fraction.hpp"

using namespace std;

namespace ariel
{
    Fraction::Fraction(): _numerator(0), _denominator(1) {}

    Fraction::Fraction(float number) {}

    Fraction::Fraction(int numerator, int denominator): _numerator(numerator), _denominator(denominator) {}

    Fraction::Fraction(const Fraction& other): _numerator(other._numerator), _denominator(other._denominator) {}

    Fraction::Fraction(Fraction&& other) noexcept: _numerator(other._numerator), _denominator(other._denominator) {}

    Fraction& Fraction::operator=(const Fraction& other) {
        return *this;
    }

    Fraction& Fraction::operator=(Fraction&& other) noexcept {
        return *this;
    }



    ostream& operator<<(ostream& os, const Fraction& fraction) {
        os << fraction._numerator << "/" << fraction._denominator;
        return os;
    }

    istream& operator>>(istream& is, Fraction& fraction) {
        int numerator, denominator;
        char slash;

        is >> numerator >> slash >> denominator;

        if (slash != '/')
            throw invalid_argument("Invalid input");

        fraction = Fraction(numerator, denominator);

        return is;
    }


    const Fraction Fraction::operator+(const Fraction& other) const {
        int numerator = (_numerator * other._denominator) + (other._numerator * _denominator);
        int denominator = (_denominator * other._denominator);

        __reduce(numerator, denominator);

        return Fraction(numerator, denominator);
    }

    const Fraction Fraction::operator-(const Fraction& other) const {
        int numerator = (_numerator * other._denominator) - (other._numerator * _denominator);
        int denominator = (_denominator * other._denominator);

        __reduce(numerator, denominator);

        return Fraction(numerator, denominator);
    }

    const Fraction Fraction::operator*(const Fraction& other) const {
        int numerator = (_numerator * other._numerator);
        int denominator = (_denominator * other._denominator);

        __reduce(numerator, denominator);

        return Fraction(numerator, denominator);
    }

    const Fraction Fraction::operator/(const Fraction& other) const {
        if (other._numerator == 0)
            throw invalid_argument("Can't divide by zero");

        int numerator = (_numerator * other._denominator);
        int denominator = (_denominator * other._numerator);

        __reduce(numerator, denominator);

        return Fraction(numerator, denominator);
    }

    const Fraction Fraction::operator+() const {
        return Fraction(_numerator, _denominator);
    }

    const Fraction Fraction::operator-() const {
        return Fraction(-_numerator, _denominator);
    }

    Fraction& operator+=(Fraction& fraction, const Fraction& other) {

        return fraction;
    }

    Fraction& operator-=(Fraction& fraction, const Fraction& other) {
    
        return fraction;
    }

    Fraction& operator*=(Fraction& fraction, const Fraction& other) {
       
        return fraction;
    }

    Fraction& operator/=(Fraction& fraction, const Fraction& other) {
      
        return fraction;
    }

    Fraction& Fraction::operator++() {
       
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& Fraction::operator--() {
        
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    bool Fraction::operator==(const Fraction& other) const {
        return (_numerator == other._numerator && _denominator == other._denominator);
    }

    bool Fraction::operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool Fraction::operator<(const Fraction& other) const {
        return (_numerator * other._denominator) < (other._numerator * _denominator);
    }

    bool Fraction::operator>(const Fraction& other) const {
        return (_numerator * other._denominator) > (other._numerator * _denominator);
    }

    bool Fraction::operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool Fraction::operator>=(const Fraction& other) const {
        return !(*this < other);
    }




    const Fraction Fraction::operator+(const float& number) const {
        return *this + Fraction(number);
    }
    
    const Fraction operator+(const float& num, const Fraction& other) {
        return Fraction(num) + other;
    }

    const Fraction Fraction::operator-(const float& number) const {
        return *this - Fraction(number);
    }

    const Fraction operator-(const float& num, const Fraction& other) {
        return Fraction(num) - other;
    }

    const Fraction Fraction::operator*(const float& number) const {
        return *this * Fraction(number);
    }

    const Fraction operator*(const float& num, const Fraction& other) {
        return Fraction(num) * other;
    }

    const Fraction Fraction::operator/(const float& number) const {

        return *this / Fraction(number);
    }

    const Fraction operator/(const float& num, const Fraction& other) {
       
        return Fraction(num) / other;
    }

    Fraction& operator+=(Fraction& fraction, const float& number) {

        return fraction;
    }

    Fraction& operator-=(Fraction& fraction, const float& number) {

        return fraction;
    }

    Fraction& operator*=(Fraction& fraction, const float& number) {
        
        return fraction;
    }

    Fraction& operator/=(Fraction& fraction, const float& number) {
        if (number == 0)
            throw invalid_argument("Can't divide by zero");
            
        Fraction temp = fraction / Fraction(number);
        
        fraction._numerator = temp._numerator;
        fraction._denominator = temp._denominator;

        fraction.__reduce();
        
        return fraction;
    }

    bool Fraction::operator==(const float& number) const {
        return *this == Fraction(number);
    }

    bool operator==(const float& num, const Fraction& other) {
        return Fraction(num) == other;
    }

    bool Fraction::operator!=(const float& number) const {
        return !(*this == Fraction(number));
    }

    bool operator!=(const float& num, const Fraction& other) {
        return !(Fraction(num) == other);
    }

    bool Fraction::operator<(const float& number) const {
        return *this < Fraction(number);
    }

    bool operator<(const float& num, const Fraction& other) {
        return Fraction(num) < other;
    }

    bool Fraction::operator>(const float& number) const {
        return *this > Fraction(number);
    }

    bool operator>(const float& num, const Fraction& other) {
        return Fraction(num) > other;
    }

    bool Fraction::operator<=(const float& number) const {
        return !(*this > Fraction(number));
    }

    bool operator<=(const float& num, const Fraction& other) {
        return !(Fraction(num) > other);
    }

    bool Fraction::operator>=(const float& number) const {
        return !(*this < Fraction(number));
    }

    bool operator>=(const float& num, const Fraction& other) {
        return !(Fraction(num) < other);
    }
}