#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	// Comparison operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Increment/decrement operators
	Fixed& operator++();    // Pre-increment
	Fixed operator++(int);  // Post-increment
	Fixed& operator--();    // Pre-decrement
	Fixed operator--(int);  // Post-decrement

	// Min/max
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif