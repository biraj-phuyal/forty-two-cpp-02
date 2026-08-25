#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed (void) {
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(const int fixed_point) {
    std::cout << "Assinging constructer created" << std::endl;
    this->fixed_point = fixed_point * 256;
}

Fixed::Fixed(const float fixed_point)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point = roundf(fixed_point * 256);
}

Fixed::Fixed(const Fixed& content) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point = content.fixed_point;
}


Fixed& Fixed::operator=(const Fixed& context) {
    if (this != &context)
        this->fixed_point = context.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

int Fixed::toInt(void) const {
    return (this->fixed_point / 256);
}

float Fixed::toFloat(void) const {
   return static_cast<float>(this->fixed_point) / 256;
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
    return this->fixed_point;
}

void Fixed::setRawBits(int const raw) {
    this->fixed_point = raw;
}