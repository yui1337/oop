#include "vector_3d.h"
#include <iostream>
using namespace vector_3d;
using namespace std;

class VectorContainer {
	vector* _vector;
	size_t _size;
public:
	VectorContainer(){
		_vector = new vector;
	}
	VectorContainer(size_t size) : _size(size) {
		_vector = new vector[size];
	}
	size_t size() { return _size; }
	vector* get_vector() { return _vector; }
	ostream& operator[](size_t index) { return _vector + index; }

};