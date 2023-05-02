
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>

namespace ariel
{
    class Fraction
    {
        private:
            
            int _numerator;
            
            
            int _denominator;

           
            void __reduce() {
                int gcd = __gcd(abs(_numerator), abs(_denominator));
                _numerator /= gcd;
                _denominator /= gcd;
            }

            
            static void __reduce(int& numerator, int& denominator) {
                int gcd = __gcd(abs(numerator), abs(denominator));
                numerator /= gcd;
                denominator /= gcd;
            }

            
            static int __gcd(int a, int b) {
                return (b == 0) ? a:__gcd(b, a % b);
            }

        public:
           
            Fraction();

            
            Fraction(float number);

            
            Fraction(int numerator, int denominator);

           
            Fraction(const Fraction& other);

            Fraction(Fraction&& other) noexcept;

        
            ~Fraction() = default;


            Fraction& operator=(const Fraction& other);

           
            Fraction& operator=(Fraction&& other) noexcept;

            friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);

           
            friend std::istream& operator>>(std::istream& is, Fraction& fraction);


            const Fraction operator+(const Fraction& other) const;

           
            const Fraction operator+(const float& num) const;

    
            friend const Fraction operator+(const float& num, const Fraction& other);

            const Fraction operator-(const Fraction& other) const;

    
            const Fraction operator-(const float& num) const;

            friend const Fraction operator-(const float& num, const Fraction& other);

            const Fraction operator*(const Fraction& other) const;

            const Fraction operator*(const float& num) const;

            friend const Fraction operator*(const float& num, const Fraction& other);

            const Fraction operator/(const Fraction& other) const;

            const Fraction operator/(const float& num) const;

            friend const Fraction operator/(const float& num, const Fraction& other);

            const Fraction operator+() const;

            const Fraction operator-() const;

           
            friend Fraction& operator+=(Fraction& fraction, const Fraction& other);

            friend Fraction& operator+=(Fraction& fraction, const float& num);

            friend Fraction& operator-=(Fraction& fraction, const Fraction& other);

            friend Fraction& operator-=(Fraction& fraction, const float& num);

            friend Fraction& operator*=(Fraction& fraction, const Fraction& other);

            friend Fraction& operator*=(Fraction& fraction, const float& num);

            friend Fraction& operator/=(Fraction& fraction, const Fraction& other);

            friend Fraction& operator/=(Fraction& fraction, const float& num);

            Fraction& operator++();

            Fraction& operator--();

            Fraction operator++(int);

            Fraction operator--(int);

            bool operator==(const Fraction& other) const;

            bool operator==(const float& other) const;

            friend bool operator==(const float& num, const Fraction& other);

            bool operator!=(const Fraction& other) const;

           
            bool operator!=(const float& other) const;

            friend bool operator!=(const float& num, const Fraction& other);

            bool operator>(const Fraction& other) const;

            bool operator>(const float& other) const;

            friend bool operator>(const float& num, const Fraction& other);

            bool operator<(const Fraction& other) const;

            
            bool operator<(const float& other) const;

          
            friend bool operator<(const float& num, const Fraction& other);

            bool operator>=(const Fraction& other) const;

            bool operator>=(const float& other) const;

           
            friend bool operator>=(const float& num, const Fraction& other);

            
            bool operator<=(const Fraction& other) const;

            
            bool operator<=(const float& other) const;

            
            friend bool operator<=(const float& num, const Fraction& other);
    };

}