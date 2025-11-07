#include <iostream>
#include <windows.h>

using namespace std;

class Shape {
protected:
    int x, y;
public:
    Shape(int x = 0, int y = 0) : x(x), y(y) {
        cout << "Вызван конструктор Shape(int, int). Адрес: " << this << endl;
    }
    virtual ~Shape() {
        cout << "Вызван деструктор ~Shape(). Адрес: " << this << endl;
    }
    virtual void draw() const {
        cout << "Фигура в позиции (" << x << ", " << y << ") по адресу: " << this << endl;
    }
};

class Rect: public Shape {
private:
    int width, height;
public:
    Rect(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {
        cout << "Вызван конструктор Rectangle(int, int, int, int). Адрес: " << this << endl;
    }
    ~Rect() override {
        cout << "Вызван деструктор ~Rectangle(). Адрес: " << this << endl;
    }
    void draw() const override {
        cout << "Прямоугольник в позиции (" << x << ", " << y << ") размером " 
             << width << "x" << height << " по адресу: " << this << endl;
    }
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle(int x, int y, int r) : Shape(x, y), radius(r) {
        cout << "Вызван конструктор Circle(int, int, int). Адрес: " << this << endl;
    }
    ~Circle() override {
        cout << "Вызван деструктор ~Circle(). Адрес: " << this << endl;
    }
    void draw() const override {
        cout << "Круг в позиции (" << x << ", " << y << ") радиусом " 
             << radius << " по адресу: " << this << endl;
    }
};

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    Shape* shapes[3];
    
    cout << "\nСоздаем Circle:" << endl;
    shapes[0] = new Circle(5, 5, 3);
    
    cout << "\nСоздаем Rectangle:" << endl;
    shapes[1] = new Rect(10, 10, 4, 6);
    
    cout << "\nСоздаем Shape:" << endl;
    shapes[2] = new Shape(1, 1);

    cout << "\nВызов виртуальных методов" << endl;
    for(int i = 0; i < 3; i++) {
        shapes[i]->draw();
        cout << endl;
    }

    cout << "\nУдаление объектов " << endl;
    for(int i = 0; i < 3; i++) {
        delete shapes[i];
        cout << endl;
    }
    
    cout << "Конец программы" << endl;
    return 0;
}
