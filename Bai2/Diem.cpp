#include "Diem.h"
#include<cmath>
#define PI 3.14
Diem::Diem() {
	x = 0;
	y = 0;
}
Diem::Diem(double dx, double dy) {
	x = dx;
	y = dy;
}
Diem::Diem(const Diem& d) {
	x = d.x;
	y = d.y;
}
Diem::~Diem() {
	return;
}
void Diem::Nhap() {
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
} 
void Diem::Xuat() {
	cout << x << ", " << y;
}
double Diem::tinhKhoangCach(const Diem& d) {
	return sqrt(pow(x - d.x, 2) + pow(y - d.y,2));
}
void Diem::tinhTien(double dx, double dy) {
	x += dx;
	y += dy;
}
void Diem::phongTo(double scale) {
	x *= scale;
	y *= scale;
}
void Diem::quay(double alpha) {
	alpha = alpha * PI / 180;
	double xtemp = x * cos(alpha) - y * sin(alpha);
	double ytemp = x * sin(alpha) + y * cos(alpha);
	x = xtemp;
	y = ytemp;
}
