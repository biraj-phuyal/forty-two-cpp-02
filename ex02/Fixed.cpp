#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed (void) {
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::Fixed(const int fixed_point) {
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point = fixed_point * (1 << bits);
}

Fixed::Fixed(const float fixed_point)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point = roundf(fixed_point * (1 << bits));
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

bool Fixed::operator>(const Fixed& other) const {
    return this->fixed_point > other.fixed_point;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->fixed_point < other.fixed_point;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->fixed_point >= other.fixed_point;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->fixed_point <= other.fixed_point;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->fixed_point == other.fixed_point;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->fixed_point != other.fixed_point;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.fixed_point = this->fixed_point + other.fixed_point;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.fixed_point = this->fixed_point - other.fixed_point;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    double raw = static_cast<double>(this->fixed_point) * other.fixed_point / (1 << bits);
    result.fixed_point = static_cast<int>(raw + (raw >= 0 ? 0.5 : -0.5));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    double raw = static_cast<double>(this->fixed_point) * (1 << bits) / other.fixed_point;
    result.fixed_point = static_cast<int>(raw + (raw >= 0 ? 0.5 : -0.5));
    return result;
}

Fixed& Fixed::operator++() {
    ++this->fixed_point;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old(*this);

    ++this->fixed_point;
    return old;
}

Fixed& Fixed::operator--() {
    --this->fixed_point;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old(*this);

    --this->fixed_point;
    return old;
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    if (first < second)
        return first;
    return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    if (first < second)
        return first;
    return second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
    if (first > second)
        return first;
    return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    if (first > second)
        return first;
    return second;
}

int Fixed::toInt(void) const {
    return (this->fixed_point / (1 << bits));
}

float Fixed::toFloat(void) const {
   return static_cast<float>(this->fixed_point) / (1 << bits);
}

std::ostream& operator<<(std::ostream& output, const Fixed& src)
{
    output << src.toFloat();
    return output;
}

Fixed::~Fixed () {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point;
}

void Fixed::setRawBits(int const raw) {
    this->fixed_point = raw;
}
