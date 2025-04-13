#pragma once
#include<iostream>
using namespace std;
class cNhanVienSX
{
private:
	string ma;
	string hoTen;
	string ngaySinh;
	int soSP;
	double donGia;
public:
	cNhanVienSX();
	string getMa();
	string getHoTen();
	string getNgaySinh();
	int getSoSP();
	double getDonGia();
	void setMa(string);
	void setHoTen(string);
	void setNgaySinh(string);
	void setSoSP(int);
	void setDonGia(double);
	void Nhap();
	void Xuat();
	double tinhLuong();
	int getTuoi();
};

