#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int fixed_point;
        static const int bits;
    public:
        Fixed( void );
        Fixed(int fixed_point);
        Fixed(const Fixed& context);
        ~Fixed();

        Fixed&  operator=(const Fixed& context);
        int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif