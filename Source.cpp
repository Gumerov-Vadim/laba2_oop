#include <iostream>

class Point {
protected:
	int x, y;
public:
	Point() {
		printf("Point()\n");
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		printf("Point(int x,int y)\n");
		this->x = 10;
		this->y = 20;
	}
	Point(const Point& p) {
		printf("const Point &p)\n");
		this->x = p.x;
		this->y = p.y;
	}
	~Point() {
		printf("%d, %d\n", this->x, this->y);
		printf("~Point()\n");
	}
	void move(int x, int y) {
		printf("move(int x,int y):\n");
		printf("x: %d => %d\n", this->x, this->x + x);
		printf("y: %d => %d\n", this->y, this->y + y);
		this->x = this->x + x;
		this->y = this->y + y;
	}
	void reset();
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	};
};
class ColoredPoint : public Point {
private:
	int color;
public:
	ColoredPoint() : Point() {
		printf("ColoredPoint()\n");
		color = 0;
	}
	ColoredPoint(int x, int y, int color) : Point(x, y) {
		printf("ColoredPoint(int x,int y,int color)\n");
		this->color = color;
	}
	ColoredPoint(const ColoredPoint& p) {
		printf("ColoredPoint(const ColoredPoint &p)\n");
		this->color = p.color;
		this->x = p.x;
		this->y = p.y;
	}
	~ColoredPoint() {
		printf("x = %d,y = %d, color = %d\n", this->x, this->y, this->color);
		printf("~ColoredPoint()\n");
	}
	void ChangeColor(int new_color) {
		if ((new_color >= 0x0) and (new_color <= 0xFFFFFF)) {
			printf("ChangeColor(int new_color):\n");
			printf("color:%d => %d\n", this->color, new_color);
			this->color = new_color;
		}
		else {
			printf("wrong color\n");
		}
	}

};
class Vector {
protected:
	Point Point_first;
	Point Point_second;
public:
	Vector() {
		printf("\nVector()");
	}
	Vector(Point &p1,Point &p2) {
		Point_first = p1;
		Point_second = p2;
		printf("\nVector(&p1,&p2)");
		printf("\np1.x = %d, p1y = %d\n p2.x = %d, p2.y = %d ", Point_first.get_x(), Point_first.get_y(), Point_second.get_x(), Point_second.get_y());
	}
	Vector(Vector &v) {
		this->Point_first = v.Point_first;
		this->Point_second = v.Point_second;
		printf("\nVector(Vector &v):");
		printf("\n p1.x = %d, p1y = %d\n p2.x = %d, p2.y = %d", Point_first.get_x(), Point_first.get_y(), Point_second.get_x(), Point_second.get_y());
	}
	~Vector() {
		printf("\np1.x = %d, p1y = %d\n p2.x = %d, p2.y = %d\n~Vector() ", Point_first.get_x(), Point_first.get_y(), Point_second.get_x(), Point_second.get_y());
	}
	void getVectorPoints(Point &p1, Point &p2){
		printf("getVectorPoints(Point &p1, Point &p2)");
		this->Point_first = p1;
		this->Point_second = p2;
	}

};
void Point::reset() {
	printf("reset x y\n");
	x = 0;
	y = 0;
}
int main() {
	{	
		setlocale(LC_ALL, "Russian");
		printf("Создание статических объектов:\n");
		Point p01;
		Point p02(10, 20);
		Point p03(p02);
		printf("Изменение свойств объекта с помощью методов:\n");
		p02.move(2, 3);
		p02.reset();
	}
	printf("\n\n\n");
	{
		printf("Создание динамических объектов:\n");
		Point* p1 = new Point;
		Point* p2 = new Point(10, 20);
		Point* p3 = new Point(*p2);
		delete p1;
		delete p2;
		delete p3;
	}
	printf("\n\n\n");
	{
		printf("Создание статических объектов :\n");
		ColoredPoint cp01;
		printf("\n");
		ColoredPoint cp02(10, 20, 12345);
		printf("\n");
		cp02.ChangeColor(0xFFFFFF);
		ColoredPoint cp03(cp02);
		printf("\n");
	}
	printf("\n\n\n");
	{
		ColoredPoint* cp1 = new ColoredPoint();
		printf("\n");
		ColoredPoint* cp2 = new ColoredPoint(10, 20, 12345);
		printf("\n");
		ColoredPoint* cp3 = new ColoredPoint(*cp2);
		printf("\n");
		delete cp1;
		printf("\n");
		delete cp2;
		printf("\n");
		delete cp3;
		printf("\n");
	}
	printf("\n\n\n");
	{
		printf("\nПомещение объектов в переменные различных типов");
		printf("\nPoint * p1 = new Point(); ");
		Point* p1 = new Point();
		printf("\nPoint * p2 = new СoloredPoint(10,20,3003); ");
		Point* p2 = new ColoredPoint(10, 20, 3003);
		printf("\n");
		delete p1;
		printf("\n");
		delete p2;
	}
	printf("\n\n\n");
	{
		printf("\nСтатическое создание векторов:");
		Point p1(2,5);
		Point p2(7,9);
		printf("Работа с векторами:\n");
		Vector v1;
		printf("\n");
		Vector v2(p1,p2);
		printf("\n");
		Vector v3(v2);
		printf("\n");
	}
	printf("\n\n\n");
	{
		printf("\nДинамическое создание векторов:");
		Point *p1 = new Point(2, 5);
		Point *p2 = new Point(7, 9);
		printf("\n");
		printf("Работа с векторами:\n");
		Vector *v1 = new Vector;
		printf("\n");
		Vector *v2 = new Vector(*p1, *p2);
		printf("\n");
		Vector *v3 = new Vector(*v2);
		printf("\n");
		printf("\n");
		printf("\n");
		(*v1).getVectorPoints(*p1, *p2);
		delete v1;
		delete v2;
		delete v3;
		delete p1;
		delete p2;
	}
	return 0;
}