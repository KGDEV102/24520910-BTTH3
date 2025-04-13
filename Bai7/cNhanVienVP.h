#pragma once
#include<iostream>
using namespace std;

class cNhanVienVP
{
private:
	string ma;
	string hoTen;
	string ngaySinh;
	double luong;
public:
	cNhanVienVP();
	string getMa();
	string getHoTen();
	string getNgaySinh();
	double getLuong();
	void setMa(string);
	void setHoTen(string);
	void setNgaySinh(string);
	void setLuong(double);
	void Nhap();
	void Xuat();
	int getTuoi();
};

