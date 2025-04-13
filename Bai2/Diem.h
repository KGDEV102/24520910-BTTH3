#pragma once
#include<iostream>

using namespace std;
class Diem
{
private:
	double x;
	double y;
public:
	Diem();
	Diem(double dx, double dy);
	Diem(const Diem& d);
	~Diem();
	void Nhap();
	void Xuat();
	double tinhKhoangCach(const Diem& d);
	void tinhTien(double x, double y);
	void phongTo(double scale);
	void quay(double alpha);
};

