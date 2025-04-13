#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class cCandidate
{
private:
	string ma;
	string ten;
	string ngaySinh;
	float toan;
	float van;
	float anh;
public:
	void Nhap();
	void Xuat();
	float tongDiem();
};

