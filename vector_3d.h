#pragma once
#include <iostream>
class Vector {
private:
	double _x, _y, _z;
public:
	double get_x() const;
	double get_y() const;
	double get_z() const;
	Vector();
	Vector(double x, double y, double z);
	Vector Vector_multiply(Vector& other) const;
	double operator*(Vector& other) const;
	bool operator==(Vector& other) const;
	bool operator!=(Vector& other) const;
};
std::ostream& operator<<(std::ostream& os, Vector& other);
