#include <iostream>
#include "Square.h"
#include "Ellipse.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	Ellipse kryg;
	Square kvad;
	cin >> kryg;
	cin >> kvad;

	cout << "getArea\n";
	cout << kryg.getArea() << '\n' << kvad.getArea() << '\n';
	
	cout << "getFrameRectangle\n";
	cout << kryg.getFrameRectangle() << '\n' << kvad.getFrameRectangle() << '\n';

	cout << "moveToPoint("

}