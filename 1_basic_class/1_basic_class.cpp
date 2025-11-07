#include <iostream>
#include <windows.h>

class Point
{
private:
	int x, y; 
public:
	void SetX(int newX)
	{
		std::cout << "Вызван SetX для точки" << std::endl;
		x = newX;
	}
	void SetY(int newY)
	{
		std::cout << "Вызван SetY для точки" << std::endl;
		y = newY;
	}
void print() const
	{
		std::cout << "Point(" << x << ", " << y << ")" << std::endl;
	}
};

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

	std::cout << "Создание статического объекта" << std::endl;
	Point p1;
	p1.SetX(10);
	p1.SetY(20);
	p1.print();

	std::cout << "Создание динамического объекта" << std::endl;
	Point* p2 = new Point();
	p2->SetX(5);
	p2->SetY(15);
	p2->print();

	delete p2;
	return 0;
}
