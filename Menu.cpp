#pragma once
#include <iostream>
#include "Progressions.cpp"
#include "Menu.cpp"
int menu(vector <shared_ptr <Progression>>& massiv1) {
	while (true) {
		system("cls");
		cout << "Choose needed action by entering a number on keyboard:" << endl << endl;
		cout << "1 - Insert new element by index" << endl;
		cout << "2 - Remove element by index" << endl;
		cout << "3 - Find the progression with highest sum of first n terms" << endl;
		cout << "4 - Print container" << endl;
		cout << "5 - Calculate N term of any progression from container by index" << endl;;
		cout << endl << "(Press X on keyboard if you want to close program)" << endl;
		switch (_getch()) {
		case 49: {
			system("cls");
			int current_size = massiv1.size();
			cout << "Enter type of progression ( A - arithmetic, G - geometric)" << endl;
			int progrType = _getch();
			system("cls");
			int first = 0;
			int step = 0;
			cout << "Enter first term and step" << endl;
			cin >> first >> step;
			cout << "Enter index that you want to insert element" << endl;
			size_t index = 0;
			cin >> index;
			shared_ptr<Progression> progr;
			if (progrType == 97 || progrType == 65 || progrType == 228 || progrType == 148) { progr = make_shared <Arithmetic>(first, step); }
			if (progrType == 103 || progrType == 71 || progrType == 175 || progrType == 143) { progr = make_shared <Geometric>(first, step); }
			auto iter1 = massiv1.begin();
			massiv1.insert(iter1 + index, progr);
			int new_size = massiv1.size();
			system("cls");
			if (new_size > current_size) { cout << "Element by index " << index << " has been successfully added!" << endl << endl; }
			if (new_size == current_size){ cout << "An error occured while inserting element, try again." << endl << endl; }
			cout << "Press any key to continue" << endl;
			_getch();
			break;
		}
		case 50: {
			size_t index = 0;
			system("cls");
			cout << "Enter index ( >= 0) of element you want to delete:" << endl;
			cin >> index;
			if (index >= massiv1.size()) {
				cout << "Incorrect index, try again!" << endl;
				break;
			}
			massiv1.erase(massiv1.begin() + index);
			system("cls");
			cout << "Element with index " << index << " has been successfully deleted!" << endl;
			cout << "Press any key to continue" << endl;
			_getch();
			break;
		}
		case 51: {
			system("cls");
			cout << "Enter N - number of steps" << endl;
			size_t n = 0;
			cin >> n;
			shared_ptr <Progression> pointer = max_sum_of_first_n(n, massiv1);
			if (pointer != nullptr) {
				//cout << *max_sum_of_first_n(n, massiv1) << endl;
				string text = typeid(*pointer).name();
				cout << "Required progression is " << *pointer << " , its type is " << text.substr(16, 100) << " " << endl;
				//cout << "Index of term with highest sum of first " << n << " terms is " << index << endl;
			}
			else {
				cout << "Container is empty!" << endl << endl;
			}
			cout << "Press any key to continue" << endl;
			_getch();
			break;
		}
		case 52: {
			system("cls");
			cout << "Current state of container: " << endl;
			cout << massiv1;
			cout << endl << endl << "Press any key to continue" << endl;
			_getch();
			break;
		}
		case 53: {
			system("cls");
			cout << "Enter N - number of a term you want to calculate" << endl;
			int n = 0;
			cin >> n;
			cout << "Enter index of progression, " << n << " term of which you want to calculate" << endl;
			int index = 0;
			cin >> index;
			double nTerm = -100;
			if (massiv1[index] != nullptr) { nTerm = massiv1[index]->calculate_n_term(n); }
			else {
				cout << "No elements exist at this index" << endl;
				cout << endl << endl << "Press any key to continue" << endl;
				_getch();
				break;
			}
			cout << n << " term of chosen progression is " << nTerm << endl;
			cout << endl << endl << "Press any key to continue" << endl;
			_getch();
			break;
		}
		case 120: case 88: case 231: case 151: {
			return 0;
			break;
		}
		}
	}
}