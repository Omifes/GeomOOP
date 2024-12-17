#include <iostream>
#include <vector>
#include <memory>
#include "Square.h"
#include "Ellipse.h"
#include "CompositeShape.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Введите данные для эллипса (x, y, вертикальный радиус, горизонтальный радиус): ";
    Ellipse ellipse;
    cin >> ellipse;

    cout << "Введите данные для квадрата (x, y, сторона): ";
    Square square;
    cin >> square;
    
    CompositeShape composite(2);
    composite.addShape(ellipse.clone());
    composite.addShape(square.clone());
    
    cout << "Начальные данные составной фигуры:\n";
    cout << composite << '\n';

    cout << "Введите координаты для перемещения составной фигуры в точку (x, y): ";
    double moveX, moveY;
    cin >> moveX >> moveY;
    composite.moveToPoint(Point(moveX, moveY));

    cout << "После перемещения составной фигуры:\n";
    cout << composite << '\n';

    cout << "Введите коэффициент масштабирования: ";
    double scaleFactor;
    cin >> scaleFactor;
    composite.scale(scaleFactor);

    cout << "После масштабирования составной фигуры:\n";
    cout << composite << '\n';

    return 0;
}
