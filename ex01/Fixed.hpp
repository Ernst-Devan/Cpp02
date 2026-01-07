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
        Fixed &operator=(const Fixed& f);
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
