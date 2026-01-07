#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed 
{
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &f);
        Fixed &operator=(const Fixed& f);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:
        int                 _fixed_point;
        static const int    _fractional;
};

#endif
