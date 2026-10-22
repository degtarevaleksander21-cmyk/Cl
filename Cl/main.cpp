
#include <iostream>
#include "equation.hpp"
#include "system.hpp"
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RU");
	bool start = true;
	string check;
	bool user_is_eblan = false;
	quad_equation equation;
	equation.example();
	do {
		system_2unknown a;
		do {
			cout << "Продолжить? (Y/N)\t";
			cin >> check;
			if (check == "Y") {
				start = true;
				user_is_eblan = false;
			}
			else if (check == "N") {
				start = false;
				user_is_eblan = false;
			}
			else {
				cout << "Введите \"Y\"(да) или \"N\"(нет)\n";
				user_is_eblan = true;
			}
		} while (user_is_eblan = true);
		cout << "///////////////////////////////////////////////////////////////////////////////////" << endl;
	} while (start == true);
	return 0;
}