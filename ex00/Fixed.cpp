#include "Fixed.hpp"

Fixed::Fixed (void) {
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(int fixed_point) {
    std::cout << "Assinging constructer created" << std::endl;
    this->fixed_point = fixed_point;
}

Fixed::Fixed(const Fixed& content) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point = content.fixed_point;
}

Fixed& Fixed::operator=(const Fixed& context) {
    if (this != &context)
        this->fixed_point = context.fixed_point;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed () {
    std::cout << "Destroy constructer called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point;
}

void Fixed::setRawBits(int const raw) {
    this->fixed_point = raw;
}