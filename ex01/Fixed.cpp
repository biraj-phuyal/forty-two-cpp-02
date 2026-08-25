#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed (void) {
    std::cout << "Default constructor called" << std::endl;
    this->tiny_pieces = 0;
}

Fixed::Fixed(const int tiny_pieces) {
    std::cout << "Assinging constructer created" << std::endl;
    this->tiny_pieces = tiny_pieces * 256;
}

Fixed::Fixed(const float tiny_pieces)
{
    std::cout << "Float constructor called" << std::endl;
    this->tiny_pieces = roundf(tiny_pieces * 256);
}

Fixed::Fixed(const Fixed& content) {
    std::cout << "Copy constructor called" << std::endl;
    this->tiny_pieces = content.tiny_pieces;
}


Fixed& Fixed::operator=(const Fixed& context) {
    if (this != &context)
        this->tiny_pieces = context.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

int Fixed::toInt(void) const {
    return (this->tiny_pieces / 256);
}

float Fixed::toFloat(void) const {
   return static_cast<float>(this->tiny_pieces) / 256;
}

std::ostream& operator<<(std::ostream& output, const Fixed& src)
{
    output << src.toFloat();
    return output;
}

Fixed::~Fixed () {
    std::cout << "Destroy constructer called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->tiny_pieces;
}

void Fixed::setRawBits(int const raw) {
    this->tiny_pieces = raw;
}