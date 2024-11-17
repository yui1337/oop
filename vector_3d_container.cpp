#include "vector_3d.h"
#include "vector_3d_container.h"
#include <iostream>
#include <algorithm>
using namespace vector_container;
using namespace std;


VectorContainer::VectorContainer() : _size(0), _capacity(0) {
	_vector = nullptr;
}
VectorContainer::VectorContainer(size_t capacity) : _capacity(capacity), _size(0) {
	_vector = new vector[capacity];
}
VectorContainer::VectorContainer(const VectorContainer& other) :
	_vector(new vector[other._capacity]),
	_size(other._size),
	_capacity(other._capacity) {
	for (size_t i = 0; i < _size; ++i) {
		_vector[i] = other._vector[i];
	}
}

size_t VectorContainer::size() const { return _size; }
size_t VectorContainer::capacity() const { return _capacity; }
vector& VectorContainer::operator[](size_t index) const {
	if (_size <= index) {
		throw out_of_range("Index is out of range.");
	}
	return *(_vector + index);
}
void VectorContainer::print() const {
	for (size_t i = 0; i < _size; ++i) {
		cout << *(_vector + i) << endl;
	}
	cout << endl;
}
void VectorContainer::insert(size_t index, vector inserted) {
	if (index > _size) {
		throw out_of_range("Index is out of range.");
	}
	if (_size == _capacity) {
		_capacity *= 2;
	}
	vector* newarray = new vector[_capacity];
	for (size_t i = 0; i < index; ++i) {
		newarray[i] = _vector[i];
	}
	newarray[index] = inserted;
	for (size_t i = index; i < _size; ++i) {
		newarray[i + 1] = _vector[i];
	}
	delete[] _vector;
	_vector = newarray;
	_size += 1;
}
void VectorContainer::erase(size_t index) {
	if (index > _size - 1) {
		throw out_of_range("Index is out of range.");
	}
	for (size_t i = index; i < _capacity - 1; ++i) {
		std::swap(_vector[i], _vector[i + 1]);
	}
	_size--;
	if (_capacity > _size + 5) { shrink_to_fit(); }
}
void VectorContainer::swap(VectorContainer& other) noexcept {
	std::swap(_vector, other._vector);
	std::swap(_size, other._size);
	std::swap(_capacity, other._capacity);
}
VectorContainer::~VectorContainer() {
	delete[] _vector;
	_vector = nullptr;
}
VectorContainer& VectorContainer::operator=(VectorContainer other) {
	swap(other);
	return *this;
}
void VectorContainer::shrink_to_fit() {
	if (_capacity > _size) {
		vector* newvector = new vector[_size];
		for (size_t i = 0; i < _size; ++i) {
			newvector[i] = _vector[i];
		}
		delete[] _vector;
		_vector = newvector;
		_capacity = _size;
	}
}

ostream& vector_container::operator<<(ostream& os, const VectorContainer& other) {
	for (size_t i = 0; i < other.size(); ++i) {
		os << other[i] << endl;
	}
	return os;
}

int vector_container::is_collinear(const VectorContainer& list, vector vector_, float epsilon) {
	for (size_t i = 0; i < list.size(); ++i) {
		float ratio_x = list[i].get_x() / vector_.get_x();
		float ratio_y = list[i].get_y() / vector_.get_y();
		float ratio_z = list[i].get_z() / vector_.get_z();
		if ((ratio_x - ratio_y < epsilon) && (ratio_x - ratio_z < epsilon) && (ratio_y - ratio_z < epsilon)) {
			return i;
		}
	}
	return -1;
}
