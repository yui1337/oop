#pragma once
#include <iostream>
using namespace std;

namespace vector_container {
	class VectorContainer {
		vector* _vector;
		size_t _size;
		size_t _capacity;
		void shrink_to_fit();
	public:
		VectorContainer();
		VectorContainer(size_t capacity);
		VectorContainer(const VectorContainer& other);
		size_t size() const;
		size_t capacity() const;
		vector& operator[](size_t index) const;
		void print() const;
		void insert(size_t index, vector inserted);
		void erase(size_t index);
		void swap(VectorContainer& other) noexcept;
		~VectorContainer();
		VectorContainer& operator=(VectorContainer other);
	};
	ostream& operator<<(ostream& os, const VectorContainer& other);
	int is_collinear(const VectorContainer& list, vector vector_, float epsilon);
}
