#pragma once
#include <iostream>
using namespace std;

namespace vector_3d {
	class vector {
	private:
		double _x, _y, _z;
	public:
		double get_x() const;
		double get_y() const;
		double get_z() const;
		vector();
		vector(double x, double y, double z);
		vector vector_multiply(vector& other) const;
		double operator*(vector& other) const;
		bool operator==(vector& other) const;
		bool operator!=(vector& other) const;
	};
	std::ostream& operator<<(std::ostream& os, vector& other);
}