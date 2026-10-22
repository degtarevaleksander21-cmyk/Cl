#pragma once
#include <cmath>
using namespace std;
class quad_equation {
private:
	double a;
	double b;
	double c;
	double D;
	double x1, x2;
	void output_equation() {
		if (a == -1)
			cout << "-";
		else if (a != 1)
			cout << a;
		cout << "x^2";
		if (b > 0) {
			cout << " + ";
			cout << b << 'x';
		}
		else if (b < 0) {
			cout << " - ";
			cout << -1 * b << 'x';
		}
		if (c > 0) {
			cout << " + ";
			cout << c;
		}
		else if (c < 0) {
			cout << " - ";
			cout << -1 * c;
		}
		cout << endl;
	}
	void user_input() {
		bool is_true = true;
		do {
			cout << "Введите значения коэффициентов\n";
			cout << ">>a — ";
			cin >> a;
			cout << ">>b — ";
			cin >> b;
			cout << ">>c — ";
			cin >> c;
			cout << "Уравнение выглядит следующим образом: \t";
			output_equation();
		} while (is_true == false);
	}
	void discriminant() {
		D = pow(b, 2) - 4 * a * c;
		cout << "Дискриминант равен " << D << endl;
	}
	void solve() {
		if (D >= 0) {
			x1 = (-1 * b + sqrt(D)) / (2 * a);
			x2 = -1 * b - sqrt(D) / (2 * a);
			if (x1 != x2) {
				cout << "X1 = " << x1 << endl;
				cout << "X2 = " << x2 << endl;
			}
			else
				cout << "X = " << x1 << endl;	
		}
		else {
			x1 = -1 * b + sqrt(-1*D) / (2 * a);
			x2 = -1 * b - sqrt(-1*D) / (2 * a);
			cout << "Уравнение не имеет вещественных корней" << endl;
			cout << "--> X1 = " << x1 << 'i' << endl;
			cout << "--> X2 = " << x2 << 'i' << endl;
			
		}
	}
public:
	void start() {
		user_input();
		discriminant();
		solve();
	}
	void example() {
		cout << "Стандартный вид квадратного уравнения: " << endl;
		cout << ">> ax^2 + bx + c = 0" << endl;
		cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	}
};