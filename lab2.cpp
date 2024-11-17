#include "vector_3d.cpp"
#include <iostream>
#include "vector_3d_container.cpp"
#include <stdexcept>
int main() {
	VectorContainer list(1);
	size_t num = 0;
	cout << "input num of vectors " << endl;
	cin >> num;
	for (size_t i = 0; i < num; ++i) {
		double x = 0; double y = 0;	double z = 0;
		cout << "input vector in x y z format" << endl;
		cin >> x >> y >> z;
		vector input(x, y, z);
		list.insert(i, input);
	}
	cout << list << endl;
	//cout << "input index of element you would like to remove" << endl;
	//size_t index_of_erased = 0;
	//cin >> index_of_erased;
	//list.erase(index_of_erased);
	//list.print();

	list[2] = vector(1, 2, 3);
	cout << list<< endl;

	try {
		list[52] = vector(1, 2, 3);
	}
	catch (const out_of_range& e) {
		cout << e.what() << '\n';
	}
	return 0;
}