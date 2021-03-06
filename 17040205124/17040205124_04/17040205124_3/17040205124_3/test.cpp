#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Point {
public:
	Point() { x = y = 0; }
	Point(unsigned xx, unsigned yy) { x = xx; y = yy;}

	unsigned getX() { return x; }
	unsigned getY() { return y; }
	void Print() {
		cout << "point(" << x << ", " << y << ")"<< endl;
	}

	friend Point operator + (Point& pt, int nOffset);
	friend Point operator + (int nOffset, Point& pt);

private:
	unsigned x;
	unsigned y;
};
Point operator + (Point& pt, int nOffset) {
	Point ptTemp = pt;
	ptTemp.x += nOffset;
	ptTemp.y += nOffset;

	return ptTemp;
}

Point operator + (int nOffset, Point& pt) {
	Point ptTemp = pt;
	ptTemp.x += nOffset;
	ptTemp.y += nOffset;

	return ptTemp;
}

int main() {
	Point pt(10, 10);
	pt.Print();

	pt = pt + 5;
	pt.Print();

	pt = 10 + pt;
	pt.Print();
	return 0;
};