#include <iostream>
#include <windows.h>

class Point
{
    private:
        int x,y;
    public:
        Point(): x(0), y(0)
        {
            std::cout<<"Вызван конструктор Point() по умолчанию. Адрес: "<<this<<std::endl;
        }
        Point (int x, int y): x(x), y(y)
        {
            std::cout<<"Вызван конструктор Point(int, int) с параметрами. Адрес: "<<this<<std::endl;
        }
        Point (const Point& other): x(other.x), y(other.y)
        {
            std::cout<<"Вызван конструктор копирования Point(const Point&). Адрес: "<<this<<" (копирую с "<<&other<<")"<<std::endl;
        }
        ~Point()
        {
            std::cout<<"Вызван деструктор ~Point(). Адрес: "<<this<<std::endl;
        }
        void set(int newX, int newY)
        {
            x = newX;
            y = newY;
        }
        void print() const 
        {
            std::cout<<"Point("<<x<<", "<<y<<") по адресу: "<<this<<std::endl;
        }
};

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout<<"Point A (по умолчанию)"<<std::endl;
    Point A;
    std::cout<<"Point B(1,2) (с параметрами)"<<std::endl;
    Point B(1,2);
    std::cout<<"Point C = B (копирование)"<<std::endl;
    Point C = B;

    std::cout<<"Присваивание B в A"<<std::endl;
    A = B;
    A.print();
    B.print();

    std::cout<<"Изменение исходного объекта B"<<std::endl;
    B.set(99,98);
    std::cout<<"После изменения B:"<<std::endl;
    A.print();
    B.print();
    C.print();

    std::cout<<"Конец. "<<std::endl;
    return 0;
}
