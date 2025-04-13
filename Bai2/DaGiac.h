#pragma once
#include"Diem.h"
#include<vector>
using namespace std;

class DaGiac:public Diem
{
private:
	int n;
	vector<Diem> dg;
public:
	DaGiac();
	DaGiac(const DaGiac&);
	DaGiac(int , vector<Diem>);
	~DaGiac();
	
	void Nhap();
	void Xuat();
	void tinhTien(double x, double y);
	void phongTo(double scale);
	void quay(double alpha);
};

