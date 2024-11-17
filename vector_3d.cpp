#include "Vector_3d.h"
#include <iostream>

using namespace std;

Vector::Vector(): _x(0),_y(0),_z(0) {}
Vector::Vector(double x, double y, double z) : _x(x), _y(y), _z(z) {}
double Vector::get_x() const { return _x; }
double Vector::get_y() const { return _y; }
double Vector::get_z() const { return _z; }
Vector Vector::Vector_multiply(Vector& other) const {
	Vector res;
	res._x = _y * other._z - _z * other._y;
	res._y = _z * other._x - _x * other._z;
	res._z = _x * other._y - _y * other._x;
	return res;
}
double Vector::operator*(Vector& other) const {
	return _x * other._x + _y * other._y + _z * other._z;
}
bool Vector::operator==(Vector& other) const {
	return this->_x == other.get_x() && this->_y == other.get_y() && this->_z == other.get_z();
}
bool Vector::operator!=(Vector& other) const {
	return (!(*this == other));
}
ostream& operator<<(ostream& os, Vector& other) {
	os << "(" << other.get_x() << ", " << other.get_y() << ", " << other.get_z() << ")";
	return os;
}
