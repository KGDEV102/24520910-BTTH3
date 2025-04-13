#pragma once
#include<iostream>
#include<vector>
using namespace std;

class cDaThuc
{
private:
	int n;
	vector<int>arr;
	int x;
public:
	cDaThuc();
	void tinhcDaThuc();
	void Nhap();
	void Xuat();
	cDaThuc operator +(const cDaThuc&);
	cDaThuc operator -(const cDaThuc&);
};

