#include<iostream>

using namespace std;

class figure
{

protected:
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

	virtual void print_info(bool b)
	{
		cout << figureName << ":" << endl;
		if (b) cout << "Правильная";
		else cout << "Неправильная";
		cout << endl
			<< "Количество сторон: " << sidesCount
			<< endl;
	}

	virtual bool check()
	{
		bool c = false;
		if ((sidesCount == 0) && (figureName == "Фигура")) c = true;
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

	void print_info(bool b) override
	{
		figure::print_info(b);
		cout << "Стороны: " << "a=" << sideA
			<< " b=" << sideB
			<< " c=" << sideC << endl;
		cout << "Углы: " << "A=" << angleA
			<< " B=" << angleB
			<< " C=" << angleC << endl << endl;
	}

	bool check() override
	{
		bool c = false;
		if ((sidesCount == 3) && ((angleA + angleB + angleC) == 180)) c = true;
		else c = false;
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

	void print_info(bool b) override
	{
		figure::print_info(b);
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
		return (sidesCount == 4)&&((angleA + angleB + angleC + angleD) == 360);
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
		bool c = triangle::check();
		if ((angleC == 90) && c) c = true;
		else c = false;
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
		c &= (sideA == sideC) && (angleA == angleC);
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
		bool c = triangle::check();
		c &= (sideA == sideB) && (sideB == sideC) && (angleA == angleB) && (angleB == angleC);
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
		bool c = square::check();
		c &= (sideA == sideC) && (sideB == sideD) && (angleA == angleB) && (angleB == angleC) && (angleC == angleD) && (angleD == 90);
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
		bool c = square::check();
		c &= (sideA == sideB) && (sideB == sideC) && (sideC == sideD) && (angleA == angleB) && (angleB == angleC) && (angleC == angleD) && (angleD == 90);
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
		bool c = square::check();
		c &= (sideA == sideC) && (sideB == sideD) && (angleA == angleC) && (angleB == angleD);
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
		bool c = square::check();
		c &= (sideA == sideB) && (sideB == sideC) && (sideC == sideD) && (angleA == angleC) && (angleB == angleD);
		return c;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");

	figure      Figure;
	Figure.print_info(Figure.check());
	cout << endl;

	triangle    Triangle("Треугольник", 10, 20, 30, 50, 60, 70);
	Triangle.print_info(Triangle.check());

	StrengthTriangle Tr("Прямоугольный треугольник", 10, 20, 30, 50, 60, 90);
	Tr.print_info(Tr.check());

	StrengthTriangle Tr1("Прямоугольный треугольник", 10, 20, 30, 50, 40, 90);
	Tr1.print_info(Tr1.check());

	TwoEqualTriangle Tr2("Равнобедренный треугольник", 10, 20, 10, 50, 60, 50);
	Tr2.print_info(Tr2.check());

	EqualSideTriangle Tr3("Равносторониий треугольник", 30, 30, 30, 60, 60, 60);
	Tr3.print_info(Tr3.check());

	square      Square;
	Square.print_info(Square.check());

	rectangle Square1("Прямоугольник", 10, 20);
	Square1.print_info(Square1.check());

	equalSideRectangle Square2("Квадрат", 20);
	Square2.print_info(Square2.check());

	parallelogramm Square3("Параллелограмм", 20, 30, 30, 40);
	Square3.print_info(Square3.check());

	romb Square4("Ромб", 30, 30, 40);
	Square4.print_info(Square4.check());
	return 0;
}