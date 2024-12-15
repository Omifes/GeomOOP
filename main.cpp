#include <iostream>
#include <vector>
#include <memory>
#include "Square.h"
#include "Ellipse.h"
#include "CompositeShape.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Shape*> shapes;

    
    Shape* ellipse = new Ellipse();
    Shape* square = new Square();

    
    cout << "Введите данные для эллипса (x, y, вертикальный радиус,горизонтальный радиус): ";
    cin >> dynamic_cast<Ellipse&>(*ellipse);

    cout << "Введите данные для квадрата (x, y, сторона): ";
    cin >> dynamic_cast<Square&>(*square);
    
    //Тестировка метода scale
    
    //Тестировка класса CompositeShape
    CompositeShape composite(2);
    composite.addShape(ellipse);
    composite.addShape(square);
    cout << composite;
    /*cout << composite.getFrameRectangle().getWidth() << '\n' << composite.getFrameRectangle().getHeight() << '\n';
    cout << composite.getFrameRectangle().getPos().getX() << " " << composite.getFrameRectangle().getPos().getY() << '\n';*/
    composite.scale(2);
    
    cout << "Изменения полсе изотропного масштабирования:\n\n"<< composite << '\n';
    /*cout << composite.getFrameRectangle().getWidth() << '\n' << composite.getFrameRectangle().getHeight() << '\n';
    cout << composite.getFrameRectangle().getPos().getX() << " " << composite.getFrameRectangle().getPos().getY() << '\n';*/
    return 0;
}
