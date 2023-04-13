#include<iostream>

using namespace std;

class figure
{

protected:
    int sidesCount;
    void SetSideCount(int sideCount)
    {
        this->sidesCount = sideCount;
    }
public:
    figure()
    {
        SetSideCount(0);
    }
    int getSidesCount()
    {
        return sidesCount;
    }
};

class triangle :public figure
{
public:
    triangle()
    {
        SetSideCount(3);
    }
};

class square :public figure
{
public:
    square()
    {
        SetSideCount(4);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    figure      Figure;
    triangle    Triangle;
    square      Square;
    cout << "Количество сторон: " << endl;
    cout << "Фигура:      " << Figure.getSidesCount() << endl;
    cout << "Треугольник: " << Triangle.getSidesCount() << endl;
    cout << "Квадрат:     " << Square.getSidesCount() << endl;
}