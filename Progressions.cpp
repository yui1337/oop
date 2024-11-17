#pragma once
#include "Progressions.h"
#include <cmath>
#include <vector>
using namespace Progress;
using namespace std;

double Progression::get_first() const noexcept { return _first; }

double Arithmetic::get_step() const noexcept { return _step; }

double Geometric::get_step() const noexcept { return _denom; }

Progression::Progression(double first): _first(first){}

Arithmetic::Arithmetic(double first, double step) : Progression(first), _step(step) {}

Geometric::Geometric(double first, double denom) : Progression(first), _denom(denom) {}

double Arithmetic::calculate_n_term(size_t n) const {
	return (get_first() + get_step() * (n - 1));
}

double Arithmetic::sum_of_first_n_terms(size_t n) const {
	return(n * (get_first() + calculate_n_term(n))) / 2;
}

double Geometric::calculate_n_term(size_t n) const {
	return (get_first() * pow(get_step(), n - 1));
}

double Geometric::sum_of_first_n_terms(size_t n) const {
	if (get_step() != 1) return (get_first() * (pow(get_step(), n) - 1)) / (get_step() - 1);
	else return n * get_first();
}

std::ostream& operator<<(std::ostream& os, Progression& item) noexcept {	
	os << "first term: " << item.get_first() << ", step (or denominator): " << item.get_step();
	return os;
}

shared_ptr<Progression> max_sum_of_first_n(size_t n, vector<shared_ptr<Progression>> massiv) {
	if (massiv.size() == 0) return nullptr;
	int maxim = massiv[0]->sum_of_first_n_terms(n);
	int index = 0;
	for (int i = 1; i < massiv.size(); ++i) {
		if (massiv[i] != nullptr) {
			int current = massiv[i]->sum_of_first_n_terms(n);
			if (current > maxim) {
				maxim = current;
				index = i;
			}
		}
	}
	return massiv[index];
}
std::ostream& operator<<(std::ostream& os, vector<shared_ptr<Progression>> massiv) {
	int counter = 0;
	for (int i = 0; i < massiv.size(); ++i) {
		if (massiv[i] != nullptr) {
			os << i << ". ";
			string text = typeid(*massiv[i]).name();
			os << text.substr(16, 100) << " ";
			os << *massiv[i] << endl; 
		}
		else ++counter;
	}
	if ((massiv.size() == 0) || (counter == massiv.size())) { os << "Container is empty" << endl; }
	return os;
}
