#include <iostream>
#include <conio.h>
#include "Menu.cpp"
#include "Progressions.cpp"

using namespace std;
using namespace Progress;
int main() {
	vector <shared_ptr <Progression>> massiv1;
	massiv1.resize(100);
	menu(massiv1);
}
