#include <iostream>
#include <windows.h>

class Point
{
    protected:
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

class Circle: public Point
{
    private:
        int radius;
    public:
        Circle(): Point(),radius(1)
        {
            std::cout<<"Конструктор Circle(). Адрес: "<<this<<std::endl;
        }
        Circle(int x, int y, int r): Point(x,y),radius(r)
        {
            std::cout<<"Вызван конструктор Circle(int, int, int) с параметрами. Адрес: "<<this<<std::endl;
        }
        ~Circle()
        {
            std::cout<<"Вызван деструктор ~Circle(). Адрес: "<<this<<std::endl;
        }
        void print() const
        {
            std::cout << "Окружность с центром в точке (" << x << ", " << y << ") и радиусом " << radius << std::endl;
        }
        void printAsPoint() const
        {
            std::cout<<"Центр окружности: ";
            Point::print();
        }
};

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Создание объекта Circle" << std::endl;
    Circle c(5, 10, 3);
    c.print();          // Вызов переопределенного метода Circle::print
    c.printAsPoint();   // Вызов метода, который вызывает Point::print
    // c.Point::print(); // Можно вызвать и так

    std::cout << "\nСоздание Circle* как Point* " << std::endl;
    Point* ptr = new Circle(1, 1, 5); // Указатель базового типа на объект потомка
    ptr->print(); // Какой print вызовется? Point::print (Т.к. метод не виртуальный)
    delete ptr;   // Какой деструктор вызовется? Только ~Point()! Утечка?

    std::cout << "\nКонец" << std::endl;
    // Деструктор для c вызовется здесь (~Circle, затем ~Point)
    return 0;
}
