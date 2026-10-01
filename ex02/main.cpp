#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    Fixed two(2);
    Fixed three(3);
    Fixed equal(3);

    std::cout << std::boolalpha;
    std::cout << "3 > 2: " << (three > two) << std::endl;
    std::cout << "2 < 3: " << (two < three) << std::endl;
    std::cout << "3 >= 2: " << (three >= two) << std::endl;
    std::cout << "3 <= 3: " << (three <= equal) << std::endl;
    std::cout << "3 == 3: " << (three == equal) << std::endl;
    std::cout << "3 != 2: " << (three != two) << std::endl;

    Fixed sum = three + two;
    Fixed difference = three - two;
    Fixed product = three * two;
    Fixed quotient = three / two;
    std::cout << "3 + 2 = " << sum << std::endl;
    std::cout << "3 - 2 = " << difference << std::endl;
    std::cout << "3 * 2 = " << product << std::endl;
    std::cout << "3 / 2 = " << quotient << std::endl;

    return 0;
}
