#include <iostream>
#include <windows.h>

class Point
{
private:
    int x,y;
public:
    Point(): x(0), y(0)
    {
        std::cout << "Вызван конструктор Point() по умолчанию. Адрес: " << this << std::endl;
    }
    Point(int x, int y): x(x), y(y)
    {
        std::cout << "Вызван конструктор Point(int, int) с параметрами. Адрес: " << this << std::endl;
    }
    Point(const Point& other): x(other.x), y(other.y)
    {
        std::cout << "Вызван конструктор копирования Point(const Point&). Адрес: " << this << " (копирую с " << &other << ")" << std::endl;
    }
    ~Point()
    {
        std::cout << "Вызван деструктор ~Point(). Адрес: " << this << std::endl;
    }
    void set(int newX, int newY)
    {
        x = newX;
        y = newY;
    }
    void print() const 
    {
        std::cout << "Point(" << x << ", " << y << ") по адресу: " << this << std::endl;
    }
};

class LineByValue 
{
private:
    Point start;
    Point end;
public:
    LineByValue(const Point& s, const Point& e): start(s), end(e)
    {
        std::cout << "Конструктор LineByValue вызван. Адрес: " << this << std::endl;
    }
    ~LineByValue()
    {
        std::cout << "Вызван деструктор ~LineByValue(). Адрес: " << this << std::endl;
    }
    void print() const
    {
        std::cout << "Линия с ";
        start.print();
        std::cout << " до ";
        end.print();
    }
};

class LineByPointer
{
private:
    Point* start;
    Point* end;
public:
    LineByPointer(const Point& s, const Point& e)
    {
        std::cout << "Конструктор LineByPointer вызван. Адрес: " << this << std::endl;
        start = new Point(s);
        end = new Point(e);
    }
    ~LineByPointer()
    {
        std::cout << "Вызван деструктор ~LineByPointer(). Адрес: " << this << std::endl;
        delete start;
        delete end;
    }
    void print() const
    {
        std::cout << "Линия с ";
        start->print();
        std::cout << " до ";
        end->print();
    }
};

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Создаем точки" << std::endl;
    Point p1(0, 0);
    Point p2(10, 10);

    std::cout << "\nКомпозиция по значению" << std::endl;
    {
        LineByValue line1(p1, p2);
        line1.print();
    }
    
    std::cout << "\nКомпозиция через указатель" << std::endl;
    {
        LineByPointer line2(p1, p2);
        line2.print();
    }
    
    std::cout << "\nКонец" << std::endl;
    return 0;
}
