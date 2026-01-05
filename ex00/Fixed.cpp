#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractional = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixed_point = 0;
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixed_point = f.getRawBits();
}

Fixed::Fixed(int val)
{

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
