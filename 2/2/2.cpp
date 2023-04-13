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
	figure() :figure(0)
	{

	}
	figure(int count)
	{
		SetSideCount(count);
	}
	int getSidesCount()
	{
		return sidesCount;
	}
	virtual void getSides() {
		cout << endl;
	}
	virtual void getAngles() {}
};

class triangle :public figure
{
protected:
	int sideA;
	int sideB;
	int sideC;
	int angleA;
	int angleB;
	int angleC;
public:
	triangle() :figure(3)
	{
		sideA = 10;
		sideB = 20;
		sideC = 30;

		angleA = 50;
		angleB = 60;
		angleC = 70;
	}

	void getSides()  override
	{
		cout << "Стороны: " << "a = " << sideA
			<< " b = " << sideB
			<< " c = " << sideC << endl;
	}

	void getAngles()  override
	{
		cout << "Углы: " << "A = " << angleA
			<< " B = " << angleB
			<< " C = " << angleC << endl;
	}
};

class square :public figure
{
protected:
	int sideA;
	int sideB;
	int sideC;
	int sideD;
	int angleA;
	int angleB;
	int angleC;
	int angleD;

public:
	square()
	{
		sideA = 10;
		sideB = 20;
		sideC = 30;
		sideD = 40;

		angleA = 50;
		angleB = 60;
		angleC = 70;
		angleD = 80;
	}

	void getSides() override
	{
		cout << "Стороны: " << "a = " << sideA
			<< " b = " << sideB
			<< " c = " << sideC
			<< " d = " << sideD << endl;
	}

	void getAngles() override
	{
		cout << "Углы: " << "A = " << angleA
			<< " B = " << angleB
			<< " C = " << angleC
			<< " D = " << angleD << endl;
	}
};

class StrengthTriangle :public triangle
{
public:
	StrengthTriangle() :StrengthTriangle(90) {}
	StrengthTriangle(int angleC)
	{
		this->angleC = angleC;
	}
};

class TwoEqualTriangle :public triangle
{

public:

	TwoEqualTriangle() :TwoEqualTriangle(10, 50) {}

	TwoEqualTriangle(int side, int angle)
	{
		this->sideA = side;
		this->sideC = side;

		this->angleA = angle;
		this->angleC = angle;
	}
};

class EqualSideTriangle :public triangle
{
public:
	EqualSideTriangle() :EqualSideTriangle(30, 60) {}
	EqualSideTriangle(int side, int angle)
	{
		this->sideA = side;
		this->sideB = side;
		this->sideC = side;

		this->angleA = angle;
		this->angleB = angle;
		this->angleC = angle;
	}
};

class rectangle :public square
{
public:
	rectangle() :rectangle(10, 20) {}
	rectangle(int side1, int side2)
	{
		this->sideA = side1;
		this->sideC = side1;
		this->sideB = side2;
		this->sideD = side2;

		this->angleA = 90;
		this->angleB = 90;
		this->angleC = 90;
		this->angleD = 90;
	}
};

class equalSideRectangle :public square
{
public:
	equalSideRectangle() :equalSideRectangle(20) {}
	equalSideRectangle(int side)
	{
		this->sideA = side;
		this->sideC = side;
		this->sideB = side;
		this->sideD = side;

		this->angleA = 90;
		this->angleB = 90;
		this->angleC = 90;
		this->angleD = 90;
	}
};

class parallelogramm :public square
{
public:
	parallelogramm() :parallelogramm(20, 30, 30, 40) {}
	parallelogramm(int side1, int side2, int angle1, int angle2)
	{
		this->sideA = side1;
		this->sideC = side1;
		this->sideB = side2;
		this->sideD = side2;

		this->angleA = angle1;
		this->angleB = angle2;
		this->angleC = angle1;
		this->angleD = angle2;
	}
};

class romb :public square
{
public:
	romb() :romb(30, 30, 40) {}
	romb(int side, int angle1, int angle2)
	{
		this->sideA = side;
		this->sideC = side;
		this->sideB = side;
		this->sideD = side;

		this->angleA = angle1;
		this->angleB = angle2;
		this->angleC = angle1;
		this->angleD = angle2;
	}
};


void print_info(figure& f)
{
	f.getSides();
	f.getAngles();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	triangle    Triangle;
	cout << "Треугольник: " << endl;
	print_info(Triangle);
	cout << endl <<"Прямоугольный треугольник: " << endl;
	StrengthTriangle Triangle1;
	print_info(Triangle1);
	cout << endl<< "Равнобедренный треугольник: " << endl;
	TwoEqualTriangle Triangle2;
	print_info(Triangle2);
	cout << endl << "Равносторониий реугольник: " << endl;
	EqualSideTriangle Triangle3;
	print_info(Triangle3);
	square      Square;
	cout << endl<< "Четырехугольник: " << endl;
	print_info(Square);
	cout << endl <<"Прямоугольник:     " << endl;
	rectangle Square1;
	print_info(Square1);
	cout << endl <<"Квадрат:     " << endl;
	equalSideRectangle Square2;
	print_info(Square2);
	cout <<endl<< "Параллелограмм:     " << endl;
	parallelogramm Square3;
	print_info(Square3);
	cout << endl <<"Ромб:     " << endl;
	romb Square4;
	print_info(Square4);
}