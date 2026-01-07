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
    std::cout << "Int constructor called" << std::endl;
    this->_fixed_point = val << _fractional;
}

int Fixed::toInt(void) const
{
    return (this->_fixed_point / (1 << _fractional));
}

Fixed::Fixed(float val)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixed_point = roundf(val * (1 << _fractional));
}

float Fixed::toFloat(void) const
{
    return (this->_fixed_point / static_cast<float>(1 << _fractional));
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixed_point = f._fixed_point;
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

