#include<iostream>

using namespace std;

class figure
{

protected:
	bool f = false;
	bool t = true;
	int sidesCount;
	string figureName;
	void SetSideCount(int sideCount)
	{
		this->sidesCount = sideCount;
	}
public:
	figure() :figure("Фигура", 0) {}
	figure(string name, int sidesCount)
	{
		this->figureName = name;
		SetSideCount(sidesCount);
	}
	int getSidesCount()
	{
		return sidesCount;
	}

	virtual void print_info()
	{
		bool b = this->check();
		cout << figureName << ":" << endl;
		if (b) cout << "Правильная";
		else cout << "Неправильная";
		cout << endl
			<< "Количество сторон: " << sidesCount
			<< endl;
	}

	virtual bool check()
	{
		bool c = f;
		if ((sidesCount == 0) && (figureName == "Фигура")) c = t;
		return c;
	}
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
	triangle() :triangle("Треугольник",10, 20, 30, 50, 60, 70)
	{
		SetSideCount(3);
	}
	triangle(string str, int sideA, int sideB, int sideC,
		int angleA, int angleB, int angleC)
	{
		SetSideCount(3);
		this->figureName = str;
		this->sideA = sideA;
		this->sideB = sideB;
		this->sideC = sideC;

		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
	}

	void print_info() override
	{
		figure::print_info();
		cout << "Стороны: " << "a=" << sideA
			<< " b=" << sideB
			<< " c=" << sideC << endl;
		cout << "Углы: " << "A=" << angleA
			<< " B=" << angleB
			<< " C=" << angleC << endl << endl;
	}

	bool check() override
	{
		bool c = f;
		if ((sidesCount == 3) && ((angleA + angleB + angleC) == 180)) c = t;
		return c;
	}
};

class square :public triangle
{
protected:
	int sideD;
	int angleD;

public:
	square() :square("Четырехугольник", 40, 80)
	{
		SetSideCount(4);
	}
	square(string str, int d, int D)//:figure("Четырехугольник", 4)
	{
		this->figureName = str;

		this->sideD = d;

		this->angleD = D;

	}

	void print_info() override
	{
		figure::print_info();
		cout << "Стороны: " << "a = " << sideA
			<< " b = " << sideB
			<< " c = " << sideC
			<< " d = " << sideD << endl;
		cout << "Углы: " << "A = " << angleA
			<< " B = " << angleB
			<< " C = " << angleC
			<< " D = " << angleD << endl << endl;
	}

	bool check() override
	{
		bool b = ((sidesCount == 4) && ((angleA + angleB + angleC + angleD) == 360));
		bool c = b;
		return c;
	}
};

// prymougolniy treugolnik
class StrengthTriangle :public triangle
{
public:
	StrengthTriangle() :StrengthTriangle(90) {}
	StrengthTriangle(int angleC)// :figure("Прямоугольный треугольник", 3)
	{
		this->angleC = angleC;
	}
	StrengthTriangle(string str, int sideA, int sideB, int sideC,
		int angleA, int angleB, int angleC)// :figure("Прямоугольный треугольник", 3)
	{
		this->figureName = str;
		this->sideA = sideA;
		this->sideB = sideB;
		this->sideC = sideC;

		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
	}

	bool check() override
	{
		bool c;
		bool d = triangle::check();
		c = d;
		if ((angleC == 90) && c) c = t;
		return c;
	}
};

// ravnobedreniy treugolnik
class TwoEqualTriangle :public triangle
{
public:
	TwoEqualTriangle() :TwoEqualTriangle(10, 50) {}
	TwoEqualTriangle(int side, int angle)// :figure("Равнобедренный треугольник", 3)
	{
		this->sideA = side;
		this->sideC = side;
		this->angleA = angle;
		this->angleC = angle;
	}
	TwoEqualTriangle(string str, int a, int b, int c,
		int A, int B, int C)// :figure("Равнобедренный треугольник", 3)
	{
		this->figureName = str;
		this->sideA = a;
		this->sideB = b;
		this->sideC = c;

		this->angleA = A;
		this->angleB = B;
		this->angleC = C;
	}
	bool check() override
	{
		bool c = triangle::check();
		bool b = (sideA == sideC) && (angleA == angleC)&&(triangle::check());
		c = b;
		return c;
	}
};
// ravnostoroniy treugolnik
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

	EqualSideTriangle(string str, int a, int b, int c,
		int A, int B, int C) //:figure("Равносторонний треугольник", 3)
	{
		this->figureName = str;
		this->sideA = a;
		this->sideB = b;
		this->sideC = c;

		this->angleA = A;
		this->angleB = B;
		this->angleC = C;
	}

	bool check() override
	{
		bool c;
		bool b = (sideA == sideB) && (sideB == sideC) && (angleA == angleB) && (angleB == angleC) && triangle::check();
		c = b;
		return c;
	}
};

// pryamougolnik
class rectangle :public square
{
public:
	rectangle() :rectangle("Прямоугольник", 10, 20) {}
	rectangle(string str, int side1, int side2)
	{
		SetSideCount(4);
		this->figureName = str;
		this->sideA = side1;
		this->sideC = side1;
		this->sideB = side2;
		this->sideD = side2;

		this->angleA = 90;
		this->angleB = 90;
		this->angleC = 90;
		this->angleD = 90;
	}

	bool check() override
	{
		bool c;
		bool b = (sideA == sideC) && (sideB == sideD) && (angleA == angleB) && (angleB == angleC) && (angleC == angleD) && (angleD == 90) && square::check();
		c = b;
		return c;
	}
};
// kvadrat
class equalSideRectangle :public square
{
public:
	equalSideRectangle() :equalSideRectangle("Квадрат", 20) {}
	equalSideRectangle(string str, int side)
	{
		this->figureName = str;
		this->sideA = side;
		this->sideC = side;
		this->sideB = side;
		this->sideD = side;

		this->angleA = 90;
		this->angleB = 90;
		this->angleC = 90;
		this->angleD = 90;
	}

	bool check() override
	{
		bool c;
		bool b = (sideA == sideB) && (sideB == sideC) && (sideC == sideD) && (angleA == angleB) && (angleB == angleC) && (angleC == angleD) && (angleD == 90) && square::check();
		c = b;
		return c;
	}
};

class parallelogramm :public square
{
public:
	parallelogramm() :parallelogramm("Параллелограмм", 20, 30, 30, 40) {}
	parallelogramm(string str, int side1, int side2, int angle1, int angle2)
	{
		this->figureName = str;
		this->sideA = side1;
		this->sideC = side1;
		this->sideB = side2;
		this->sideD = side2;

		this->angleA = angle1;
		this->angleB = angle2;
		this->angleC = angle1;
		this->angleD = angle2;
	}
	bool check() override
	{
		bool b = square::check() && (sideA == sideC) && (sideB == sideD) && (angleA == angleC) && (angleB == angleD);
		bool c = b;
		return c;
	}
};

class romb :public square
{
public:
	romb() :romb("Ромб", 30, 30, 40) {}
	romb(string str, int side, int angle1, int angle2)
	{
		this->figureName = str;
		this->sideA = side;
		this->sideC = side;
		this->sideB = side;
		this->sideD = side;

		this->angleA = angle1;
		this->angleB = angle2;
		this->angleC = angle1;
		this->angleD = angle2;
	}
	bool check() override
	{
		bool d = square::check();
		bool b = d && (sideA == sideB) && (sideB == sideC) && (sideC == sideD) && (angleA == angleC) && (angleB == angleD);
		bool c = b;
		return c;
	}

};
void print(figure &f)
{
	f.print_info();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	figure      Figure;
//	Figure.print_info(Figure.check());
	print(Figure);
	cout << endl;

	triangle    Triangle;
	print(Triangle);
//	Triangle.print_info(Triangle.check());

	StrengthTriangle Tr("Прямоугольный треугольник", 10, 20, 30, 50, 60, 90);
//	Tr.print_info(Tr.check());
	print(Tr);
	StrengthTriangle Tr1("Прямоугольный треугольник", 10, 20, 30, 50, 40, 90);
//	Tr1.print_info(Tr1.check());
	print(Tr1);
	TwoEqualTriangle Tr2("Равнобедренный треугольник", 10, 20, 10, 50, 60, 50);
//	Tr2.print_info(Tr2.check());
	print(Tr2);
	EqualSideTriangle Tr3("Равносторониий треугольник", 30, 30, 30, 60, 60, 60);
//	Tr3.print_info(Tr3.check());
	print(Tr3);
	square      Square;
//	Square.print_info(Square.check());
	print(Square);
	rectangle Square1("Прямоугольник", 10, 20);
//	Square1.print_info(Square1.check());
	print(Square1);
	equalSideRectangle Square2("Квадрат", 20);
//	Square2.print_info(Square2.check());
	print(Square2);
	parallelogramm Square3("Параллелограмм", 20, 30, 30, 40);
//	Square3.print_info(Square3.check());
	print(Square3);
	romb Square4("Ромб", 30, 30, 40);
//	Square4.print_info(Square4.check());
	print(Square4);
	return 0;
}