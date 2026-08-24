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

        int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};