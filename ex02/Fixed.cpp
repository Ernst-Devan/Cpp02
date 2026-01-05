#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractional = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixed_point = 0;
}

Fixed::Fixed(int val)
{
    this->_fixed_point = val * std::pow(Fixed::_fractional, 2);
}

int Fixed::toInt(void) const
{
    return (this->_fixed_point / std::pow(Fixed::_fractional, 2));
}

Fixed::Fixed(float val)
{
    this->_fixed_point = roundf(val * std::pow(Fixed::_fractional, 2));
}

float Fixed::toFloat(void) const
{
    return (this->_fixed_point / std::pow(Fixed::_fractional, 2));
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixed_point = f.getRawBits();
}



std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
    os << fx.toFloat();
    return os;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

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
    this->_fixed_point = f.getRawBits();
    return (*this);
}

Fixed &Fixed::operator+(const Fixed& f)
{
    this->_fixed_point = this->getRawBits() + f.getRawBits();
    return (*this);
}

Fixed &Fixed::operator-(const Fixed& f)
{
    this->_fixed_point = this->getRawBits() - f.getRawBits();
    return (*this);
}

Fixed &Fixed::operator*(const Fixed& f)
{
    this->_fixed_point = this->getRawBits() * f.getRawBits();
    this->_fixed_point /= std::pow(Fixed::_fractional, 2);
    return (*this);
}

Fixed &Fixed::operator/(const Fixed& f)
{
    this->_fixed_point = this->getRawBits() * f.getRawBits();
    this->_fixed_point *= std::pow(Fixed::_fractional, 2);
    return (*this);
}

bool Fixed::operator>(const Fixed& f) const
{
    if (this->getRawBits() > f.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& f) const
{
    if (this->getRawBits() < f.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& f) const
{
    if (this->getRawBits() >= f.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& f) const
{
    if (this->getRawBits() <= f.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& f) const
{
    if (this->getRawBits() == f.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& f) const
{
    if (this->getRawBits() != f.getRawBits())
        return (true);
    return (false);
}

Fixed &Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return (tmp);
}

Fixed &Fixed::operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->setRawBits(this->getRawBits() - 1);
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



