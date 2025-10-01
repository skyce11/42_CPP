#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(2, 2);
	Point edge(0, 0);
	Point outside(11, 11);

	std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Point on edge: " << bsp(a, b, c, edge) << std::endl;
	std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl;

	return 0;
}