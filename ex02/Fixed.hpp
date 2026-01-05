#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &f);
        Fixed(int val);
        Fixed(float val);

        bool operator>(const Fixed &f) const;
        bool operator<(const Fixed &f) const;
        bool operator>=(const Fixed &f) const;
        bool operator<=(const Fixed &f) const;
        bool operator==(const Fixed &f) const;
        bool operator!=(const Fixed &f) const;
        Fixed &operator+(const Fixed &f);
        Fixed &operator-(const Fixed &f);
        Fixed &operator*(const Fixed &f);
        Fixed &operator/(const Fixed &f);
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
        Fixed &operator=(const Fixed& f);

        const static Fixed& min(const Fixed& f1, const Fixed& f2);
        static Fixed& min(Fixed& f1, Fixed& f2);
        const static Fixed& max(const Fixed& f1, const Fixed& f2);
        static Fixed& max(Fixed& f1, Fixed& f2);

        int     toInt(void) const;
        float   toFloat(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    private:
        int                 _fixed_point;
        static const int    _fractional;
};

std::ostream &operator<<(std::ostream& os, const Fixed& fx);
#endif
