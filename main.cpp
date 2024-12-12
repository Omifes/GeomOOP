#include <iostream>
#include <vector>
#include <memory>
#include "Square.h"
#include "Ellipse.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<unique_ptr<Shape>> shapes;

    
    unique_ptr<Shape> ellipse = make_unique<Ellipse>();
    unique_ptr<Shape> square = make_unique<Square>();

    
    cout << "Введите данные для эллипса (x y радиус_вертикальный радиус_горизонтальный): ";
    cin >> dynamic_cast<Ellipse&>(*ellipse);

    cout << "Введите данные для квадрата (x y сторона): ";
    cin >> dynamic_cast<Square&>(*square);

    shapes.push_back(move(ellipse));
    shapes.push_back(move(square));

    cout << "\nИнформация о фигурах:\n";
    for (const auto& shape : shapes) {
        cout << *shape << endl;
    }

    return 0;
}
