#pragma once
#include<iostream>
#include<vector>
using namespace std;
class cArray
{
private:
	int n;
	vector<int>arr;
public:
	cArray();
	void Xuat();
	void Dem();
	bool kiemTraTangDan();
	int timSoLeMin();
	int timSoNTMax();
	void sapXepTang();
	void sapXepGiam();
};

