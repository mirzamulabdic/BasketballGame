#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Windows.h"
#include "Utakmica.h"

using std::cout;
using std::cin;

int main() {
	Utakmica u;
	cin >> u;
	int x, prviNapad;
	x = rand() % 2;
	prviNapad = x;
	system("cls");
	cout << "Prva cetvrtina:\n";
	Sleep(1000);
	for (int i = 0; i < 20; i++) {
		if (x == 0) {
			++u;
			x++;
			Sleep(1000);
		}
		else {
			u++;
			x--;
			Sleep(1000);
		}
	}
	cout << u;
	system("pause");
	system("cls");
	x = (prviNapad + 1) % 2;
	cout << "Druga cetvrtina:\n";
	Sleep(1000);
	for (int i = 0; i < 20; i++) {
		if (x == 0) {
			++u;
			x++;
			Sleep(1000);
		}
		else {
			u++;
			x--;
			Sleep(1000);
		}
	}
	cout << u;
	system("pause");
	system("cls");
	x = (prviNapad + 1) % 2;
	cout << "Treca cetvrtina:\n";
	Sleep(1000);
	for (int i = 0; i < 20; i++) {
		if (x == 0) {
			++u;
			x++;
			Sleep(1000);
		}
		else {
			u++;
			x--;
			Sleep(1000);
		}
	}
	cout << u;
	system("pause");
	system("cls");
	cout << "Cetvrta cetvrtina:\n";
	x = prviNapad;
	Sleep(1000);
	for (int i = 0; i < 20; i++) {
		if (x == 0) {
			++u;
			x++;
			Sleep(1000);
		}
		else {
			u++;
			x--;
			Sleep(1000);
		}
	}
	cout << u;
	system("pause");
	system("cls");
	while (u.provjera()) {
		x = rand() % 2;
		cout << "Produzetci:\n";
		Sleep(1000);
		for (int i = 0; i < 10; i++) {
			if (x == 0) {
				++u;
				x++;
				Sleep(500);
			}
			else {
				u++;
				x--;
				Sleep(500);
			}
		}
		cout << u;
		system("pause");
		system("cls");
	}
	!u;
	return 0;
}