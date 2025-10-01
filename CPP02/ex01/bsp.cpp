#include "Point.hpp"

// Utilidad para el cálculo del área con el método de la "cross product"
static float area(Point const& a, Point const& b, Point const& c) {
	return ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
		  + (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
		  + (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2.0f;
}

// Devuelve true si P está dentro del triángulo ABC, false si es vértice o borde
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float total = area(a, b, c);
	float a1 = area(point, b, c);
	float a2 = area(a, point, c);
	float a3 = area(a, b, point);

	// Comprobar que el punto no está en un vértice ni borde (áreas > 0)
	if (a1 == 0 || a2 == 0 || a3 == 0)
		return false;
	float sum = a1 + a2 + a3;
	return (sum > 0 ? (std::abs(total - sum) < 1e-6f) : false);
}