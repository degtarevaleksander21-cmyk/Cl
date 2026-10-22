#pragma once
#include <iostream>
using namespace std;
class system_2unknown {
private:
	double a1, b1, c1;
	double a2, b2, c2;
	double main_determinant;
	double determinantX, determinantY;
	void output_SLAE() {
		cout << "Система выглядит следующим образом:\n";
		cout <<  "/ ";
		if (a1 = -1)
			cout << '-';
		else if (a1 != 1)
			cout << a1;
		cout << "x";
		if (b1 > 0)
			cout << " + ";
		else if (b1 < 0)
			cout << " - ";
		cout << b1 << "y";
		cout << " = " << c1 << endl;
		cout << "\\ ";
		if (a2 = -1)
			cout << '-';
		else if (a2 != 1)
			cout << a2;
		cout << "x";
		if (b2 > 0)
			cout << " + ";
		else if (b2 < 0)
			cout << " - ";
		cout << b2 << "y";
		cout << " = " << c2 << endl;

	}
	void user_input() {
		cout << "Введите значения коэффициентов\n";
		cout << ">> a1 - ";
		cin >> a1;
		cout << ">> b1 - ";
		cin >> b1;
		cout << ">> c1 - ";
		cin >> c1;
		cout << ">> a2 - ";
		cin >> a2;
		cout << ">> b2 - ";
		cin >> b2;
		cout << ">> c2 - ";
		cin >> c2;
	}


public:
	system_2unknown() {
		user_input();
		output_SLAE();
	}
	void example() {
		cout << "Стандартный вид СЛАУ с двумя неизвестными: " << endl;
		cout << "/ a1x + b1y = c1" << endl;
		cout << "\\ a2x + b2y = c2" << endl;
	}
};