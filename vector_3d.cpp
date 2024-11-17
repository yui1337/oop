#include "vector_3d.h"
#include <iostream>
#include <stdexcept>

using namespace vector_3d;
using namespace std;

vector::vector(): _x(),_y(),_z() {}
vector::vector(double x, double y, double z) : _x(x), _y(y), _z(z) {}
double vector::get_x() const { return _x; }
double vector::get_y() const { return _y; }
double vector::get_z() const { return _z; }
vector vector::vector_multiply(vector& other) const {
	vector res;
	res._x = _y * other._z - _z * other._y;
	res._y = _z * other._x - _x * other._z;
	res._z = _x * other._y - _y * other._x;
	return res;
}
double vector::operator*(vector& other) const {
	return _x * other._x + _y * other._y + _z * other._z;
}
bool vector::operator==(vector& other) const {
	return this->_x == other.get_x() && this->_y == other.get_y() && this->_z == other.get_z();
}
bool vector::operator!=(vector& other) const {
	return (!(*this == other));
}
ostream& vector_3d::operator<<(ostream& os, vector& other) {
	os << "(" << other.get_x() << ", " << other.get_y() << ", " << other.get_z() << ")";
	return os;
}
