#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fixed_point;
        static const int bits;
    public:
        Fixed( void );
        Fixed(const int fixed_point);
        Fixed(const float fixed_point);
        Fixed(const Fixed& src);
        ~Fixed();

        Fixed&  operator=(const Fixed& src);
        int		getRawBits( void ) const;
		void	setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream& operator<<(std::ostream& output, const Fixed& src);

#endif