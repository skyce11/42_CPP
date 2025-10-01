#include "Fixed.hpp"
#include <cmath>

// Orthodox Canonical Form
Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(n * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Getters and Setters
int Fixed::getRawBits(void) const {
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return ((float)_rawBits / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const {
	return (_rawBits >> _fractionalBits);
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const { return this->_rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed& other) const { return this->_rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed& other) const { return this->_rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed& other) const { return this->_rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed& other) const { return this->_rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed& other) const { return this->_rawBits != other._rawBits; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment/decrement operators
Fixed& Fixed::operator++() {
	++_rawBits;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++_rawBits;
	return tmp;
}
Fixed& Fixed::operator--() {
	--_rawBits;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--_rawBits;
	return tmp;
}

// Min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

// Stream operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}