#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractional = 8;

Fixed::Fixed()
{
    this->_fixed_point = 0;
}

Fixed::Fixed(int val)
{
    this->_fixed_point = val << _fractional;
}

int Fixed::toInt(void) const
{
    return (this->_fixed_point / (1 << _fractional));
}

Fixed::Fixed(float val)
{
    this->_fixed_point = roundf(val * (1 << _fractional));
}

float Fixed::toFloat(void) const
{
    return (this->_fixed_point / static_cast<float>(1 << _fractional));
}

Fixed::Fixed(const Fixed &f)
{
    this->_fixed_point = f._fixed_point;
}



std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
    os << fx.toFloat();
    return os;
}

Fixed::~Fixed(){};

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed_point = raw;
}



Fixed &Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &f)
    {
        return (*this);
    }
    this->_fixed_point = f._fixed_point;
    return (*this);
}

Fixed Fixed::operator+(const Fixed& f)
{
    Fixed tmp = *this;

    tmp._fixed_point += f._fixed_point;
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& f)
{
    Fixed tmp = *this;

    tmp._fixed_point -= f._fixed_point;
    return (tmp);
}

Fixed Fixed::operator*(const Fixed& f)
{
    Fixed tmp = *this;
    int res;

    res = tmp._fixed_point * f._fixed_point;
    tmp._fixed_point = res / (1 << _fractional);
    return (tmp);
}

Fixed Fixed::operator/(const Fixed& f)
{
    Fixed tmp = *this;
    float res;

    res = static_cast<float>(tmp._fixed_point) / f._fixed_point;
    tmp._fixed_point = roundf(res * (1 << _fractional));
    return (tmp);
}

bool Fixed::operator>(const Fixed& f) const
{
    if (this->_fixed_point > f._fixed_point)
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& f) const
{
    if (this->_fixed_point < f._fixed_point)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& f) const
{
    if (this->_fixed_point >= f._fixed_point)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& f) const
{
    if (this->_fixed_point <= f._fixed_point)
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& f) const
{
    if (this->_fixed_point == f._fixed_point)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& f) const
{
    if (this->_fixed_point != f._fixed_point)
        return (true);
    return (false);
}

Fixed &Fixed::operator++()
{
    this->_fixed_point++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_fixed_point++;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    this->setRawBits(this->_fixed_point - 1);
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->setRawBits(this->_fixed_point - 1);
    return (tmp);
}

Fixed &Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}

const Fixed &Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed& f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}

const Fixed &Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}



